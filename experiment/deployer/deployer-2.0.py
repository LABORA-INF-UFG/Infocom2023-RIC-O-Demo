import pprint
from flask import Flask, request, json
import requests
import copy
import yaml
import os
import urllib.request

app = Flask(__name__)

# Globals
optimization_interation = 1
input_deployed = {'E2Nodes': [{'DB': 2,
                               'E2Node': 2,
                               'E2T': 2,
                               'RIC_MAN': 2,
                               'SDL': 2,
                               'xApp1': 2},
                              {'DB': 2,
                               'E2Node': 3,
                               'E2T': 2,
                               'RIC_MAN': 2,
                               'SDL': 2,
                               'xApp1': 2}]}

payloads = {}

# Constants
TRIGGER_ALLERT_LOOPING = 'HighRICControlLoopLatency'
TRIGGER_ALLERT_NODE = 'NodeDownAlert'

STATUS_ALLERT = 'firing'

E2TERM_SCTP_LIST = [{'name': 'node2', 'addr': '10.43.0.227', 'port': 30002}, {
    'name': 'node3', 'addr': '10.43.0.228', 'port': 30003}]

E2SIM_HANDOVER_LIST = [{'name': 'node2', 'addr': '10.43.0.227', 'port': 31002}, {
    'name': 'node3', 'addr': '10.43.0.228', 'port': 31003}]

PATH = 'Infocom2023-RIC-O-Demo/experiment/deployer/'
PATH = ''
XAPP_VALUES = PATH+'helm-charts/bouncer-xapp/values.yaml'

# A function to sort json file


def sorting(item):
    if isinstance(item, dict):
        return sorted((key, sorting(values)) for key, values in item.items())
    if isinstance(item, list):
        return sorted(sorting(x) for x in item)
    else:
        return item

# A function to compare json file


def compare_json(json1_dict, json2_dict):
    return sorting(json1_dict) == sorting(json2_dict)

# A function to get relation between E2Nodes E2Term


def get_e2node_e2term(input):
    e2node_e2term = {}
    for input_dict in input['E2Nodes']:
        for key in input_dict:
            if key == 'E2Node':
                e2node = ('node'+str(input_dict[key]))
            if key == 'E2T':
                e2term = ('node'+str(input_dict[key]))
        e2node_e2term[e2node] = e2term
    return e2node_e2term

# Method to upgrade e2sim e2term connections


def upgrade_e2sim_to_e2term(input):
    global payloads
    payload_template = {
        "e2term": {
            "from": {
                "addr": "10.43.0.227",
                "port": 30002
            },
            "to": {
                "addr": "0",
                "port": 0
            }
        }
    }

    e2nodes_e2term = get_e2node_e2term(input)
    pprint.pprint(e2nodes_e2term)

    for key, value in e2nodes_e2term.items():
        for node in E2TERM_SCTP_LIST:
            if value == node['name']:
                payload = copy.deepcopy(payload_template)
                payload['e2term']['to']['addr'] = node['addr']
                payload['e2term']['to']['port'] = node['port']
                payloads[key] = payload
                break
    print(payloads)
    for key, value in payloads.items():
        for node in E2SIM_HANDOVER_LIST:
            if key == node['name']:
                url = f'http://{node["addr"]}:{node["port"]}/restconf/operations/handover'
                headers = {"Content-Type": "application/json"}
                payload = payloads[key]

                if payload['e2term']['from']['addr'] != payload['e2term']['to']['addr']:
                    response = requests.post(
                        url, headers=headers, json=payload)
                    if response.status_code == 204:
                        print(
                            f"{key} changed his E2Term from {payload['e2term']['from']['addr']} to {payload['e2term']['to']['addr']}")
                        payload['e2term']['from']['addr'] = payload['e2term']['to']['addr']
                        payload['e2term']['from']['port'] = payload['e2term']['to']['port']
                        payloads[key] = payload
                    else:
                        print(f"Something wrong with ENode in {node['name']}")
                else:
                    print(f'"{key} not changed his E2Term')
                break

 # A function to get relation between xApps E2Node


def get_xApp_e2node(input, xapp_name):
    xApp_e2node = {}
    list_xApp_e2node = []
    for input_dict in input['E2Nodes']:
        for key in input_dict:
            if key == xapp_name:
                xApp = ('node'+str(input_dict[key]))
            if key == 'E2Node':
                e2node = ('node'+str(input_dict[key]))
        xApp_e2node[xApp] = e2node
        list_xApp_e2node.append([xApp, e2node])
    return sorted(list_xApp_e2node)


def read_yaml(path):
    with open(path) as file:
        values = yaml.safe_load(file)
    return values


def write_yaml(data, path_file):
    with open(path_file, 'w') as file:
        yaml.dump(data, file)


def upgrade_xapp_deploy(input, xapp_name):
    xApp_e2node = get_xApp_e2node(input, xapp_name)
    i = 1
    for xApp_e2node_chain in xApp_e2node:
        values = read_yaml(XAPP_VALUES)
        values['nodeSelector']['kubernetes.io/hostname'] = xApp_e2node_chain[0]
        values['containers'][0]['args']['gNB'] = i*100
        write_yaml(values, XAPP_VALUES)
        os.system('helm upgrade --install opt-xapp-e2node'+str(i+1)+' ' +
                  PATH+'helm-charts/bouncer-xapp -n ricxapp')
        i = i + 1


@app.route('/alert', methods=['POST'])
def alert():
    data = request.json
    pprint.pprint(data)
    for i in data['alerts']:
        if (i['labels']['alertname'] == TRIGGER_ALLERT_LOOPING and data['status'] == STATUS_ALLERT)\
                or (i['labels']['alertname'] == TRIGGER_ALLERT_NODE and data['status'] == STATUS_ALLERT):
            print('Trigger activated, calling optimization solution')
            return run_deployment()
    return 'Nothing to do. Untreatable alert\n'


@app.route('/')
def hello():
    return 'Webhook for trigger optimization'


def run_deployment():
    json_url = urllib.request.urlopen("http://service-optimizer.ricinfra.svc.cluster.local/optimizer-optimal")
    input = json.loads(json_url.read())
    pprint.pprint(input)
    #input = {'E2Nodes': [{'DB': 3,
    #                      'E2Node': 3,
    #                      'E2T': 3,
    #                      'RIC_MAN': 1,
    #                      'SDL': 3,
    #                      'xApp1': 3},
    #         {'DB': 2,
    #          'E2Node': 2,
    #          'E2T': 2,
    #          'RIC_MAN': 1,
    #          'SDL': 2,
    #          'xApp1': 2}]}
    #pprint.pprint(input)
    global input_deployed
    if compare_json(input_deployed, input):
        return 'No change in optization result\n'
    else:
        print('Upgrading E2Node to E2Term Connection')
        upgrade_e2sim_to_e2term(input)
        xapp_name = 'xApp1'
        upgrade_xapp_deploy(input, xapp_name)
        return 'RIC environment optimized\n'


if __name__ == '__main__':
    print('Deployer started')
    app.run(debug=True,host='0.0.0.0')
    #run_deployment()
