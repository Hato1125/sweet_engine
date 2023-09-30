add_executable(sweet_test "main.cc")

target_include_directories(sweet_test PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(sweet_test PUBLIC ${SDL2_LIBRARIES})