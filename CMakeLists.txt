cmake_minimum_required(VERSION 3.15)
project(gtk-test)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_COMPILER clang)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_subdirectory(src)