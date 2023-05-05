#!/bin/bash

# Check if the user running the script is root or not
if [ "$EUID" -ne 0 ]
  then echo "Please run the script as root or use sudo"
  exit
fi

while true; do
  # Add a 30ms latency to the enp0s3 interface
  tc qdisc add dev enp0s3 root netem delay 30ms
  echo "30ms latency has been added to the enp0s3 interface"

  echo "Waiting for 120 seconds before remove latency to the enp0s3 interface"
  sleep 120

  # Remove latency from the enp0s3 interface
  tc qdisc del dev enp0s3 root
  echo "Latency has been removed from the enp0s3 interface at Node 3"

  # Roolback E2Term conenction of E2Node2
  curl -v -X POST "http://192.168.1.127:31003/restconf/operations/handover" -H "Content-Type: application/json" -d @handover_payload.json
  echo "E2Node2 at Node 3 disconnected from E2Tem at Node 3 and connected to E2Term at Node 2 again."
  sleep 120
done


