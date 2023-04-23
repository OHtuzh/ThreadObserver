cmake_minimum_required(VERSION 3.25)
project(cycle_so_lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../)

ADD_LIBRARY(${PROJECT_NAME} SHARED Cycle.cpp)

target_compile_definitions(${PROJECT_NAME} PUBLIC SLEEP_TIME=200 TIMEOUT=10)

