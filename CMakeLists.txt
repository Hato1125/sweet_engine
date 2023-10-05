cmake_minimum_required(VERSION 3.8)

project(sweet_engine CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SWEET_ENGINE_DIR ${PROJECT_SOURCE_DIR}/src/sweet_engine)
set(SWEET_TEST_DIR ${PROJECT_SOURCE_DIR}/src/sweet_test)

find_package(sdl2 REQUIRED)
find_package(sdl2_image REQUIRED)

# Release build.
if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(OUTPUT_DIR ${PROJECT_SOURCE_DIR}/build/release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)

    file(
        GLOB SWEET_ENGINE_HEADER_FILES
        "${SWEET_ENGINE_DIR}/core/**.h"
        "${SWEET_ENGINE_DIR}/graphics/**.h"
        "${SWEET_ENGINE_DIR}/input/**.h"
        "${SWEET_ENGINE_DIR}/scene/**.h"
        "${SWEET_ENGINE_DIR}/unit/**.h"
    )

    foreach(HEADER ${SWEET_ENGINE_HEADER_FILES})
        configure_file(${HEADER} ${OUTPUT_DIR}/inc)
    endforeach()
endif()

add_subdirectory(src/sweet_engine)
add_subdirectory(src/sweet_test)