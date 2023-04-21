from prometheus_api_client import PrometheusConnect
import json
import pprint
prom = PrometheusConnect(url ="http://r4-infrastructure-prometheus-server.ricplt:80/", disable_ssl=True)


result = prom.get_current_metric_value(metric_name='sum by (job) (avg_over_time(probe_http_duration_seconds{app_kubernetes_io_instance="blackbox-node3", phase!="resolve", phase!="tls",phase!="processing"}[1m]))')
pprint.pprint(result)