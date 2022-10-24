cmake_minimum_required(VERSION 3.13)  # CMake version check
project(Strarergy_pattern_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

add_executable(weathersim main.cpp  Observer.h 
                                     Subject.h 
                                     WeatherData.h 
                                     StaticDisplay.h 
                                     ThirdPartyDisplay.h 
                                     StaticDisplay.h 
                                     CurrentConditionDisplay.h
                                     ForecastDisplay.h)