cmake_minimum_required(VERSION 4.2)
project(Chap2_1)

# Corrected: SystemC 3.0.2 strictly requires C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

# Your existing executable target definition
add_executable(Chap2_1
        main.cpp
        mittelwert.cpp
        mittelwert.h
        testbench/testbench.h
        testbench/testbench.cpp)


#COPY ALL UNDER THIS AROUND BUT MAKE SURE THE TARGET FOLDER IS CORRECTLY NAMED
#target_include_directories(Chap2_1 PRIVATE "C:/SystemC/systemc-3.0.2/src")

# 2. Binary Linker Injection
# Links the binary engine you just compiled directly into your practice executable
#target_link_libraries(Chap2_1 PRIVATE "C:/SystemC/systemc-3.0.2/cmake-build-debug/src/libsystemc.a")