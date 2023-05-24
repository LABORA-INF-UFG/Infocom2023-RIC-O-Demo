# CMake generated Testfile for 
# Source directory: /home/cciadmin/Infocom2023-RIC-O-Demo/lib/src/radio/test
# Build directory: /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/src/radio/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(benchmark_radio_multi_rf "benchmark_radio" "-d" "zmq" "-a" "tx_port=tcp://*:2000,rx_port=tcp://localhost:2000;tx_port=tcp://*:2001,rx_port=tcp://localhost:2001;tx_port=tcp://*:2002,rx_port=tcp://localhost:2002;tx_port=tcp://*:2003,rx_port=tcp://localhost:2003;" "-p" "4")
set_tests_properties(benchmark_radio_multi_rf PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/src/radio/test/CMakeLists.txt;29;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/src/radio/test/CMakeLists.txt;0;")
