add_library(sweet_graphics SHARED "sprite.cc" "font_family.cc" "font.cc" "font_render.cc")

target_include_directories(sweet_graphics PUBLIC ${SWEET_ENGINE_DIR}/unit)
target_link_libraries(sweet_graphics PUBLIC sweet_unit SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)
