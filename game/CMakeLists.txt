cmake_minimum_required (VERSION 3.11)
project (game_project)
include_directories("${PROJECT_SOURCE_DIR}")
set(CMAKE_CXX_STANDARD 11)

set(ENGINE_SOURCES 
)

set(ENGINE_HEADERS
)

add_library(snail_core ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_link_libraries(game_project
                      snail_core
)

target_include_directories( 
                            game_project
                            snail_core
)
