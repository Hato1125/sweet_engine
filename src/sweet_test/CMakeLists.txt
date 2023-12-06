set(MODULE_NAME SWTest)

add_executable(${MODULE_NAME})
add_target_sources(${MODULE_NAME})


set(
    SWEET_TEST_INCLUDE
    ${SWEET_ENGINE_DIR}/core
    ${SWEET_ENGINE_DIR}/unit
    ${SWEET_ENGINE_DIR}/scene
    ${SWEET_ENGINE_DIR}/graphics
    ${SWEET_ENGINE_DIR}/input
)

set(
    SWEET_TEST_LIBRARY
    SWCore
    SWGraphics
    SWInput
    SWScene
    SWUnit
    SDL2::SDL2
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
)

target_include_directories(${MODULE_NAME} PRIVATE ${SWEET_TEST_INCLUDE})
target_link_libraries(${MODULE_NAME} PRIVATE ${SWEET_TEST_LIBRARY})
