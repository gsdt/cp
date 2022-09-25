cmake_minimum_required(VERSION 3.17)
project(acm)

include_directories(ac-library)

add_compile_definitions("gsdt")
set(CMAKE_CXX_STANDARD 17)

add_executable(acm main.cpp libs/gsdt_debug.h)