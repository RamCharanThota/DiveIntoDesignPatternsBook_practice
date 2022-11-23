cmake_minimum_required(VERSION 3.13)  # CMake version check
project(Strarergy_pattern_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

add_executable(simpleremotetest command.hpp remotecontrol.cpp simpleremote.hpp)