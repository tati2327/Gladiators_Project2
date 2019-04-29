cmake_minimum_required(VERSION 3.13)
project(Client)

set(CMAKE_CXX_STANDARD 14)
set(THREADS_PREFER_PTHEAD_FLAG ON)
find_package(Threads)
include_directories(./include/rapidjson)

add_executable(Client main.cpp Client.cpp Client.h JSON.cpp JSON.h List.h List_def.h Node.h Node_def.h)

target_link_libraries(Client ${CMAKE_THREAD_LIBS_INIT})