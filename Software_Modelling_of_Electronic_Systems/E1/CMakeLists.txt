cmake_minimum_required(VERSION 4.2)
project(E1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/EDA1)
include_directories(src/EDA2)

add_executable(E1
        src/EDA1/design.cpp
        src/EDA1/testbench.cpp
        src/EDA2/Counter.h
        src/EDA2/design.cpp
        src/EDA2/testbench.cpp
        src/first.cpp
        src/second.cpp)
