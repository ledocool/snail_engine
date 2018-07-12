project(snail_core)
include_directories("${PROJECT_SOURCE_DIR}")

set(ENGINE_SOURCES 
    Engine.cpp
)
set(ENGINE_HEADERS
    Engine.h
)

add_library(snail_core ${ENGINE_HEADERS} ${ENGINE_SOURCES})
