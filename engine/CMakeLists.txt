project(snail_core)
include_directories("${PROJECT_SOURCE_DIR}")
set(CMAKE_CXX_STANDARD 11)

set(ENGINE_SOURCES 
    Engine.cpp
    Etc/FloatHelper.cpp
    
    Input/InputManager.cpp
    Input/InputEventConfig.cpp
  
    Glad/glad/glad.c

    States/StateManager.cpp

    Graphics/WindowManager.cpp
    Graphics/Window.cpp
    Graphics/Shader.cpp
    Graphics/ShaderProgram.cpp

    Graphics/Drawables/IDrawable.cpp
    Graphics/Drawables/Spaceship.cpp
    Graphics/Drawables/Asteroid.cpp
    Graphics/Drawables/Bullet.cpp
    
    Ecs/Entity.cpp
    Ecs/System.cpp

    Ecs/Components/Position.cpp
    Ecs/Components/Player.cpp
    Ecs/Components/Size.cpp
    Ecs/Components/Velocity.cpp
    Ecs/Components/Cannon.cpp

    Ecs/EcsExecutor.cpp
    Ecs/Systems/MovePlayerSystem.cpp
    Ecs/Systems/CollectInputSystem.cpp
    Ecs/Systems/SpawnBulletSystem.cpp
    Ecs/Systems/ApplyVelocitySystem.cpp
    Ecs/Systems/MoveCameraSystem.cpp

    Game/Map.cpp
    Game/Camera.cpp
    Game/BinaryTree/TreeRoot.cpp
    Game/BinaryTree/TreeNode.cpp

    Events/EventPipeline.cpp
    Events/InputEvent.cpp
)

set(ENGINE_HEADERS
    Engine.h
    includes.h
    Etc/Singleton.h
    Etc/FloatHelper.h

    Input/InputManager.h
    Input/KeyEnums.h
    Input/InputEventConfig.h
    Input/PlayerActions.h

    Glad/glad/glad.h

    States/StateManager.h
    States/IState.h

    Graphics/WindowManager.h
    Graphics/Window.h
    Graphics/Shader.h
    Graphics/ShaderProgram.h

    Graphics/Drawables/IDrawable.h
    Graphics/Drawables/Spaceship.h
    Graphics/Drawables/Asteroid.h
    Graphics/Drawables/Bullet.h

    Ecs/System.h
    Ecs/Component.h
    Ecs/Entity.h

    Ecs/Components/ComponentTypes.h
    Ecs/Components/IncludeComponents.h
    Ecs/Components/Position.h
    Ecs/Components/Player.h
    Ecs/Components/Size.h
    Ecs/Components/Velocity.h
    Ecs/Components/Cannon.h
    
    Ecs/EcsExecutor.h
    Ecs/Systems/MovePlayerSystem.h
    Ecs/Systems/CollectInputSystem.h
    Ecs/Systems/SpawnBulletSystem.h
    Ecs/Systems/ApplyVelocitySystem.h
    Ecs/Systems/MoveCameraSystem.h

    Game/Map.h
    Game/Camera.h
    Game/GameState.h
    Game/BinaryTree/TreeRoot.h
    Game/BinaryTree/TreeNode.h

    Events/EventPipeline.h
    Events/Event.h
    Events/EventTypes.h
    Events/InputEvent.h
)

#todo: linux config

set(GLAD_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Glad")
set(SDL2_DIR "D:/projects/libraries/sdl2")
set(GLM_DIR "D:/projects/libraries/glm-0.9.9.3")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)

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
                            PUBLIC ${GLM_INCLUDE_DIRS}
)
