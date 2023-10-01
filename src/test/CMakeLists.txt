add_executable(sweet_test "main.cc")

set(
    TEST_INCLUDE
    ${SDL2_INCLUDE_DIRS}
    ${ENGINE_DIR}/core
)

set(
    TEST_LIBRARY
    ${SDL2_LIBRARIES}
    engine
)

target_include_directories(sweet_test PUBLIC ${TEST_INCLUDE})
target_link_libraries(sweet_test PUBLIC ${TEST_LIBRARY})