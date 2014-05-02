cmake_minimum_required(VERSION 2.8)

project(exercise3-2_project)

# Add all *.cpp and *.h files within src
file(GLOB srcfiles src/*.cpp)

# Build executable from srcfiles defined above
add_executable(../bin/exercise3-2 ${srcfiles})


# Usage of C++11
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
