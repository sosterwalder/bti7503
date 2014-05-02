cmake_minimum_required(VERSION 2.8)

project(exercise2-2_project)

add_executable(../bin/exercise2-2 src/Exercise2-2.cpp)


# Usage of C++11
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
