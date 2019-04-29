cmake_minimum_required(VERSION 3.2)

project(generate_maze)

find_package(OpenCV REQUIRED)

#use c++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#debug mode, use gdb to debug
#SET(CMAKE_BUILD_TYPE "Debug") 
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

include_directories(
 include
 /usr/local/include
 ${OpenCV_INCLUDE_DIRS}
)
#link_directories(./)

#all source put here
set(genMazeSrcList
    src/maze.cpp
    genMaze.cpp)


add_executable(genMaze ${genMazeSrcList})

target_link_libraries(genMaze ${OpenCV_LIBS})


