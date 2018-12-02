project(snail_core)
include_directories("${PROJECT_SOURCE_DIR}")
set(CMAKE_CXX_STANDARD 11)

set(ENGINE_SOURCES 
    Engine.cpp
    Input/InputManager.cpp
  
    Glad/glad/glad.c

    Managers/StateManager.cpp
    Managers/WindowManager.cpp

    Graphics/Window.cpp
    Graphics/Color.cpp
    Graphics/ShaderManager.cpp

    Graphics/Drawables/Triangle.cpp


)

set(ENGINE_HEADERS
    Engine.h
    includes.h
    Etc/Singleton.h

    Input/InputManager.h
    Input/KeyEnums.h

    Managers/StateManager.h
    Managers/WindowManager.h

    Glad/glad/glad.h

    States/IState.h

    Graphics/Window.h
    Graphics/Color.h
    Graphics/ShaderManager.h

    Graphics/Drawables/Triangle.h
    Graphics/Drawables/IDrawable.h
)

#todo: linux config
set(GLAD_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Glad")
message(${GLAD_INCLUDE_DIR})
set(SDL2_DIR "D:/projects/libraries/sdl2")
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
#find_package(GLEW REQUIRED)

file(COPY ${SDL2_BINARIES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_library(snail_core ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_link_libraries(snail_core 
                        ${SDL2_LIBRARIES}
                        ${OPENGL_gl_LIBRARY}
)
target_include_directories( 
                            snail_core
                            PUBLIC ${GLAD_INCLUDE_DIR}
                            PUBLIC ${SDL2_INCLUDE_DIRS}
                            PUBLIC ${GLAD_DIRECTORIES}
)
