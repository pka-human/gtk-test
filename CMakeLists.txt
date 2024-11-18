cmake_minimum_required(VERSION 3.15)
project(gtk-test)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_COMPILER clang)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

include_directories(${GTK_INCLUDE_DIRS})

add_definitions(${GTK_DEFINITIONS})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES})