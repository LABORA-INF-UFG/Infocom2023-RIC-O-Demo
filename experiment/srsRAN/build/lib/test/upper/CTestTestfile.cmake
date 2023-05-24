# CMake generated Testfile for 
# Source directory: /home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper
# Build directory: /home/cciadmin/Infocom2023-RIC-O-Demo/build/lib/test/upper
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(rlc_am_data_test "rlc_am_data_test")
set_tests_properties(rlc_am_data_test PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;23;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(rlc_am_control_test "rlc_am_control_test")
set_tests_properties(rlc_am_control_test PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;27;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(rlc_am_test "rlc_am_test")
set_tests_properties(rlc_am_test PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;31;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(rlc_am_stress_test "rlc_stress_test" "--mode=AM" "--loglevel" "1" "--sdu_gen_delay" "250")
set_tests_properties(rlc_am_stress_test PROPERTIES  TIMEOUT "3000" _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;41;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(rlc_um_stress_test "rlc_stress_test" "--mode=UM" "--loglevel" "1")
set_tests_properties(rlc_um_stress_test PROPERTIES  TIMEOUT "3000" _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;42;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(rlc_tm_stress_test "rlc_stress_test" "--mode=TM" "--loglevel" "1" "--random_opp=false")
set_tests_properties(rlc_tm_stress_test PROPERTIES  TIMEOUT "3000" _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;43;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(rlc_um_data_test "rlc_um_data_test")
set_tests_properties(rlc_um_data_test PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;54;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(rlc_um_test "rlc_um_test")
set_tests_properties(rlc_um_test PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;58;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(rlc_common_test "rlc_common_test")
set_tests_properties(rlc_common_test PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;62;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
add_test(pdcp_lte_test_rx "pdcp_lte_test_rx")
set_tests_properties(pdcp_lte_test_rx PROPERTIES  _BACKTRACE_TRIPLES "/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;89;add_test;/home/cciadmin/Infocom2023-RIC-O-Demo/lib/test/upper/CMakeLists.txt;0;")
