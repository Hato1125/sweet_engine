cmake_minimum_required(VERSION 3.8)

project(sweet_engine CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ENGINE_DIR ${PROJECT_SOURCE_DIR}/src/engine)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/src/test)

find_package(sdl2 REQUIRED)

add_subdirectory(src/engine)
add_subdirectory(src/test)