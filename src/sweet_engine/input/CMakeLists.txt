add_library(sweet_input SHARED "keyboard.cc")

target_link_libraries(sweet_input PUBLIC SDL2::SDL2)