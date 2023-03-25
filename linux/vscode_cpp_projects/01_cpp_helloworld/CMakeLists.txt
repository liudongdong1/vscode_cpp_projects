cmake_minimum_required(VERSION 2.8 FATAL_ERROR) 
SET(CMAKE_C_COMPILER "gcc")
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -fPIC")  
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fPIC")  

project(cmakeDebugTest)

aux_source_directory(. DIR_SRCS)
aux_source_directory(./src DIR_SRCS)

include_directories(./include)

add_executable(exe ${DIR_SRCS}) 

