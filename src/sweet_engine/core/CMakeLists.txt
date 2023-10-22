add_library(sweet_core SHARED "application.cc" "game_loop.cc" "logger.cc")

target_include_directories(sweet_core PUBLIC ${SWEET_ENGINE_DIR}/unit)
target_link_libraries(sweet_core PUBLIC sweet_unit SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)