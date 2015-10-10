cmake_minimum_required(VERSION 3.2)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME ArduinoExperimentation1)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_PORT /dev/tty.usbmodem1411)
set(${CMAKE_PROJECT_NAME}_SKETCH ArduinoExperimentation1.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})
