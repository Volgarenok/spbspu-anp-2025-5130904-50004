cmake_minimum_required(VERSION 4.0)
project(P3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(P3
        io.cpp
        io.h
        lab3.cpp
        process.cpp
        process.h
)
