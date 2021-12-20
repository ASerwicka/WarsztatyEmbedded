cmake_minimum_required(VERSION 3.21)
project(embedded1)

set(CMAKE_CXX_STANDARD 14)

add_executable(embedded1 main.c hash_table.c hash_table.h array.c array.h)
