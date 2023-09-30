cmake_minimum_required(VERSION 3.8)

project(sweet_engine CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(sdl2 REQUIRED)

add_subdirectory(src/engine)
add_subdirectory(src/test)