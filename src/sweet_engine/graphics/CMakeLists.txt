set(MODULE_NAME SWGraphics)

add_library(${MODULE_NAME} SHARED)
add_target_sources(${MODULE_NAME})

target_include_directories(
    ${MODULE_NAME}
    PRIVATE
    ${SWEET_ENGINE_DIR}/unit
)

target_link_libraries(
    ${MODULE_NAME}
    PRIVATE
    SWUnit
    SDL2::SDL2
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
)
