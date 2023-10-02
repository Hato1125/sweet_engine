cmake_minimum_required(VERSION 3.8)

project(sweet_engine CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SWEET_ENGINE_DIR ${PROJECT_SOURCE_DIR}/src/sweet_engine)
set(SWEET_TEST_DIR ${PROJECT_SOURCE_DIR}/src/sweet_test)

find_package(sdl2 REQUIRED)

add_subdirectory(src/sweet_engine)
add_subdirectory(src/sweet_test)