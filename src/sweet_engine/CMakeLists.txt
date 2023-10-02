set(SWEET_ENGINE_NAME sweet_engine)

add_library(${SWEET_ENGINE_NAME})

add_subdirectory(core)

target_link_libraries(
    ${SWEET_ENGINE_NAME}
    PUBLIC
    SDL2::SDL2
)