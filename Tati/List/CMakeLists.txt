cmake_minimum_required(VERSION 3.13)
project(List)

set(CMAKE_CXX_STANDARD 14)

add_executable(List main.cpp List_def.h List.h Node.h Node_def.h)