#!/bin/bash
srsenb/src/srsenb --enb.n_prb=15 --enb.name=enb1 --enb.enb_id=0x19B --rf.device_name=zmq --ric.agent.remote_ipv4_addr=192.168.1.126 --ric.agent.remote_port=30002 --log.all_level=warn --ric.agent.log_level=debug --log.filename=stdout --slicer.enable=1 --slicer.workshare=0 --ric.agent.local_ipv4_addr=192.168.1.116 --ric.agent.local_port=5055 --ric.agent.no_reconnect=0
cciadmin@NUC14:~/Infocom2023-RIC-O-Demo/build$ srsenb/src/srsenb --enb.n_prb=15 --enb.name=enb1 --enb.enb_id=0x19B --rf.device_name=zmq --ric.agent.remote_ipv4_addr=192.168.1.126 --ric.agent.remote_port=30002 --log.all_level=warn --ric.agent.log_level=debug --log.filename=stdout --slicer.enable=1 --slicer.workshare=0 --ric.agent.local_ipv4_addr=192.168.1.116 --ric.agent.local_port=5055 --ric.agent.no_reconnect=0

