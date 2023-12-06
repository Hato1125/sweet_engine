set(MODULE_NAME SWInput)

add_library(${MODULE_NAME} SHARED)
add_target_sources(${MODULE_NAME})

target_link_libraries(${MODULE_NAME} PRIVATE SDL2::SDL2)
