import yaml
import re
import pprint
import json
import os
from kubernetes import client, config
from subprocess import PIPE, run
import time
from flask import Flask,request,json
import urllib.request
import requests


app = Flask(__name__)

#Globals
optimization_interation= 1
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

#Constants
TRIGGER_ALLERT_LOOPING = 'HighRICControlLoopLatency'
TRIGGER_ALLERT_NODE = 'NodeDownAlert'

STATUS_ALLERT = 'firing'
E2TERM_SCTP_LIST = [ {'name': 'node2', 'addr': '10.43.0.227', 'port': 30002}, {'name': 'node3', 'addr': '10.43.0.228', 'port': 30003}]
E2SIM_HANDOVER_LIST = [ {'name': 'node2', 'addr': '10.43.0.227', 'port': 31002}, {'name': 'node3', 'addr': '10.43.0.228', 'port': 31003}]
XAPP_VALUES = 'helm-charts/bouncer-xapp/values.yaml'

#A function to sort json file
def sorting(item):
    if isinstance(item, dict):
        return sorted((key, sorting(values)) for key, values in item.items())
    if isinstance(item, list):
        return sorted(sorting(x) for x in item)
    else:
        return item

#A function to compare json file
def compare_json(json1_dict,json2_dict):
    return sorting(json1_dict) == sorting(json2_dict)

#A function to get relation between E2Nodes E2Term
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

# Method to upgrade e2sim deploy
def upgrade_e2sim_to_e2term(input):
    global payloads
    payload = {
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
    i=0
    for key, value in e2nodes_e2term.items():
        for node in E2TERM_SCTP_LIST:
            if value == node['name']:
                payload['e2term']['to']['addr'] = node['addr']
                payload['e2term']['to']['port'] = node['port']
            payloads[key] = payload

    print(payloads)
    for key, value in payloads.items():
        for node in E2SIM_HANDOVER_LIST:
            if key == node['name']:
                url = 'http://'+str(node['addr'])+':'+str(node['port'])+'/restconf/operations/handover'
                headers = {"Content-Type": "application/json"}
                payload = payloads[key]
                if payload['e2term']['from']['addr'] != payload['e2term']['to']['addr']:
                    response = requests.post(url, headers=headers, data=json.dumps(payload))
                    print(response.status_code)
                else:
                    print('No E2Term change')




            





  


@app.route('/alert',methods=['POST'])
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
    json_url = urllib.request.urlopen("http://10.233.43.65/optimizer-optimal")
    input = json.loads(json_url.read())
    #TODO comparar ultima otimização verificar se não é igual
    pprint.pprint(input)
    #print('Upgrade e2term deployment')
    #input = read_json()
    #upgrade_e2term_deploy(input)
    global input_deployed
    if compare_json(input_deployed,input):
        return 'No change in optization result\n'
    else:
        print('Upgrade e2sim to E2Term Connection')
        upgrade_e2sim_to_e2term(input)
        print('Upgrade xApp1 deployment')
        xapp_name =  'xApp1'
        upgrade_xapp_deploy(input, xapp_name)
        print('Remove last optimized functions')
        remove_OPT_VNFs()
        global optimization_interation 
        optimization_interation += 1
        input_deployed = input
        return 'RIC environment optimized\n'

if __name__ == '__main__':
    #print('Deployer started')
    #app.run(debug=True,host='0.0.0.0')
    run_deployment()

