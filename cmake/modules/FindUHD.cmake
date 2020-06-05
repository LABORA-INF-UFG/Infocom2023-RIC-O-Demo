INCLUDE(FindPkgConfig)
#PKG_CHECK_MODULES(UHD uhd)
IF(NOT UHD_FOUND)

FIND_PATH(
    UHD_INCLUDE_DIRS
    NAMES uhd.h
    HINTS $ENV{UHD_DIR}/include
    PATHS /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    UHD_LIBRARIES
    NAMES uhd
    HINTS $ENV{UHD_DIR}/lib
    PATHS /usr/local/lib
          /usr/lib
          /usr/lib/x86_64-linux-gnu
          /usr/local/lib64
          /usr/local/lib32
)

message(STATUS "UHD LIBRARIES " ${UHD_LIBRARIES})
message(STATUS "UHD INCLUDE DIRS " ${UHD_INCLUDE_DIRS})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(UHD DEFAULT_MSG UHD_LIBRARIES UHD_INCLUDE_DIRS)
MARK_AS_ADVANCED(UHD_LIBRARIES UHD_INCLUDE_DIRS)

include(CheckCXXSourceCompiles)

IF(UHD_FOUND)
  # Checks whether the UHD driver supports X300 reset from srsLTE. This functionality requires changing the function
  # `x300_make_ctrl_iface_enet` visibility in the file `uhd/host/lib/usrp/x300_fw_ctrl.cpp`. This can be accomplished
  # adding the following line:
  #   `UHD_API wb_iface::sptr x300_make_ctrl_iface_enet(uhd::transport::udp_simple::sptr udp, bool enable_errors);`
  set(_CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS})
  set(_CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES})
  set(CMAKE_REQUIRED_FLAGS ${CMAKE_CXX_FLAGS})
  set(CMAKE_REQUIRED_LIBRARIES uhd boost_program_options boost_system)
  check_cxx_source_compiles("#include <uhd.h>
    #include <uhd/usrp/multi_usrp.hpp>
    #include <uhd/transport/udp_simple.hpp>

    uhd::wb_iface::sptr x300_make_ctrl_iface_enet(uhd::transport::udp_simple::sptr udp, bool enable_errors);

    uhd_error try_usrp_x300_reset()
    {
      uhd::transport::udp_simple::sptr udp_simple = uhd::transport::udp_simple::make_connected(\"\", \"49152\");
      uhd::wb_iface::sptr x300_ctrl = x300_make_ctrl_iface_enet(udp_simple, true);
      x300_ctrl->poke32(0x100058, 1);
      return UHD_ERROR_NONE;
    }

    int main(int argc, char** argv)
    {
      try_usrp_x300_reset();
      return 0;
    }" UHD_ENABLE_X300_FW_RESET)

  set(CMAKE_REQUIRED_FLAGS ${_CMAKE_REQUIRED_FLAGS})
  set(CMAKE_REQUIRED_LIBRARIES ${_CMAKE_REQUIRED_LIBRARIES})
ENDIF(UHD_FOUND)

ENDIF(NOT UHD_FOUND)
