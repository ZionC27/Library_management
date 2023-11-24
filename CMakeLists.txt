cmake_minimum_required(VERSION 3.26)
project(Library_management)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library_management main.cpp
        item.h
        Users.cpp
        Library.cpp)
