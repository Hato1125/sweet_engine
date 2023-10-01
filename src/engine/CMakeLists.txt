set(ENGINE_PROJECT_NAME engine)

add_library(${ENGINE_PROJECT_NAME} ${ENGINE_DIR}/core)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES})

add_subdirectory(core)