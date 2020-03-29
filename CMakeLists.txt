cmake_minimum_required(VERSION 3.15)
project(data_structures C)

set(CMAKE_C_STANDARD 99)

add_executable(test main.c include/array.h include/stack.h include/binary_tree.h)