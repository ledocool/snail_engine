project(snail_core)
include_directories("${PROJECT_SOURCE_DIR}")
set(CMAKE_CXX_STANDARD 11)

set(ENGINE_SOURCES 
    Engine.cpp
    Input/KeyStroke.cpp
    Input/InputManager.cpp
    
    Managers/StateManager.cpp
    Managers/WindowManager.cpp

    Graphics/RenderHelper.cpp
    Graphics/Window.cpp

)
set(ENGINE_HEADERS
    Engine.h
    includes.h
    Input/KeyStroke.h
    Input/InputManager.h
    Input/KeyEnums.h

    Managers/StateManager.h
    Managers/WindowManager.h

    States/IState.h

    Graphics/RenderHelper.h
    Graphics/Window.h
)

#todo: linux config
set(SDL2_DIR "D:/projects/libraries/sdl2")
find_package(SDL2 REQUIRED)

file(COPY ${SDL2_BINARIES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_library(snail_core ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_link_libraries(snail_core ${SDL2_LIBRARIES})
target_include_directories(snail_core PUBLIC ${SDL2_INCLUDE_DIRS})
