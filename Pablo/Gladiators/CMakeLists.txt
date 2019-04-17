cmake_minimum_required(VERSION 3.13)
project(Gladiators)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gladiators main.cpp Gladiator.cpp Gladiator.h Army.cpp Army.h List_def.h List.h Node.h Node_def.h)