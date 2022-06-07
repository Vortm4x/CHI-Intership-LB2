cmake_minimum_required(VERSION 3.5)

project(LB2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LB2 List.h Pair.h main.cpp)
