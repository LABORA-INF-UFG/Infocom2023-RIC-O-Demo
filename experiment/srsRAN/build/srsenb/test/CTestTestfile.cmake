# CMake generated Testfile for 
# Source directory: /home/cciadmin/Infocom2023-RIC-O-Demo/srsenb/test
# Build directory: /home/cciadmin/Infocom2023-RIC-O-Demo/build/srsenb/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(enb_metrics_test "enb_metrics_test" "-o" "/home/cciadmin/Infocom2023-RIC-O-Demo/build/srsenb/test/enb_metrics.csv")
set_tests_properties(enb_metrics_test PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/srsenb/test/CMakeLists.txt;28;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/srsenb/test/CMakeLists.txt;0;")
subdirs("mac")
subdirs("phy")
subdirs("upper")
subdirs("rrc")
