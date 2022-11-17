cmake_minimum_required(VERSION 3.13)  # CMake version check
project(decorator_pattern)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

add_executable(pizzaapp pizzagui.cpp pizzaStore.hpp simplepizzafactory.hpp pizza.hpp pizzaingredient.hpp pizzaingredientfactory.hpp)