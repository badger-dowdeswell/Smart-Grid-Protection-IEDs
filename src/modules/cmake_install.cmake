# Install script for directory: /home/badger/org.eclipse.4diac.forte/src/modules

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/HTTP/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/IEC61131-3/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ads/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/conmeleon_c1/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/convert/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/eclipseSCADA_SFP/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/embrick/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/i2c_dev/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/lms_ev3/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/mlpi/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/modbus/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/mqtt_paho/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/odroid/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/opc/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/opc_ua/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/piface/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/powerlink/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/raspberry_sps/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/reconfiguration/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ros/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/rt_events/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/sysfs/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/tsn/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/umic/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/utils/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/wagokbus/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/xquery/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ext_AGENT2/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ext_AGENT3/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ext_DPs/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ext_HVAC_Pi/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ext_HVACsim/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ext_Library/cmake_install.cmake")
  include("/home/badger/Development/4diac/Smart_Grid_02/src/modules/ext_SMART_GRID/cmake_install.cmake")

endif()

