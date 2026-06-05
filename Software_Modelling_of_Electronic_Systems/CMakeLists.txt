cmake_minimum_required(VERSION 4.2)
project(Software_Modelling_of_Electronic_Systems)

set(CMAKE_CXX_STANDARD 14)

include_directories(Extra_Practice/Chap2.1)

add_executable(Software_Modelling_of_Electronic_Systems
        Extra_Practice/Chap2.1/main.cpp
        Extra_Practice/Chap2.1/mittelwert.cpp
        Extra_Practice/Chap2.1/mittelwert.h)
