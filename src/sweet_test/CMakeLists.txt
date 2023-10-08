set(SWEET_TEST_NAME sweet_test)

add_executable(${SWEET_TEST_NAME} "main.cc")

set(
    SWEET_TEST_INCLUDE
    ${SWEET_ENGINE_DIR}/core
    ${SWEET_ENGINE_DIR}/unit
    ${SWEET_ENGINE_DIR}/graphics
    ${SWEET_ENGINE_DIR}/input
)

set(
    SWEET_TEST_LIBRARY
    sweet_core
    sweet_graphics
    sweet_input
    sweet_scene
    sweet_unit
    SDL2::SDL2
)

target_include_directories(${SWEET_TEST_NAME} PUBLIC ${SWEET_TEST_INCLUDE})
target_link_libraries(${SWEET_TEST_NAME} PUBLIC ${SWEET_TEST_LIBRARY})
