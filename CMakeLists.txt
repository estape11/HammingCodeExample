cmake_minimum_required(VERSION 3.8)
project(Test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp HammingCode.cpp HammingCode.h BaseConverter.cpp BaseConverter.h HammingCodeMenu.cpp HammingCodeMenu.h)
add_executable(Test ${SOURCE_FILES})