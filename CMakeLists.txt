cmake_minimum_required(VERSION 3.8)

project(sweet_engine VERSION 0.3.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif()

set(SWEET_ENGINE_DIR ${PROJECT_SOURCE_DIR}/src/sweet_engine)
set(SWEET_TEST_DIR ${PROJECT_SOURCE_DIR}/src/sweet_test)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

macro(add_target_sources target_name)
    file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
    target_sources(${target_name} PRIVATE ${sources})
endmacro()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(OUTPUT_DIR ${PROJECT_SOURCE_DIR}/build/release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)

    add_subdirectory(src/sweet_engine)

    file(
        GLOB SW_HEADER_FILES
        "${SWEET_ENGINE_DIR}/core/**.h"
        "${SWEET_ENGINE_DIR}/graphics/**.h"
        "${SWEET_ENGINE_DIR}/input/**.h"
        "${SWEET_ENGINE_DIR}/scene/**.h"
        "${SWEET_ENGINE_DIR}/unit/**.h"
    )

    foreach(HEADER ${SW_HEADER_FILES})
        configure_file(${HEADER} ${OUTPUT_DIR}/inc/)
    endforeach()
else()
    add_subdirectory(src/sweet_engine)
    add_subdirectory(src/sweet_test)
endif()
