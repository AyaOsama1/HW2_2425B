cmake_minimum_required(VERSION 3.28)
project(HW2)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW2
        dry/main.cpp
        dry/Pirate.cpp
        wet/Utilities.cpp
        wet/tests.cpp
        wet/Matrix.cpp
        wet/MataMvidia.cpp
        wet/MataMvidia.h
)
