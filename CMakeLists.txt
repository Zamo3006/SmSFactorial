cmake_minimum_required(VERSION 3.9)
project(BigFactorial C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -m64)
set(CMAKE_CXX_FLAGS -m64)
add_executable(BigFactorial main.c main2.c)