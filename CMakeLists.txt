cmake_minimum_required(VERSION 2.8.1)
project(cppdl)

SET(CMAKE_CXX_FLAGS  "--std=c++11" )
SET(CMAKE_EXE_LINKER_FLAGS "-ldl")
add_library(exampleprocessor SHARED ExampleProcessor.cpp)
add_executable(cppdl main.cpp)

