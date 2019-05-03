cmake_minimum_required(VERSION 3.13)
project(A_)

set(CMAKE_CXX_STANDARD 14)
set(THREADS_PREFER_PTHEAD_FLAG ON)
find_package(Threads)
include_directories(./include/rapidjson)

add_executable(A_ main.cpp Field.cpp Field.h Pathfinding.cpp Pathfinding.h List.h List_def.h Node.h Node_def.h Matrix.h Matrix_def.h GeneticEvolution.cpp GeneticEvolution.h Army.cpp Army.h Gladiator.cpp Gladiator.h Game.cpp Game.h JSON.cpp JSON.h Server.cpp Server.h)
target_link_libraries(A_ ${CMAKE_THREAD_LIBS_INIT})