project(snail_core)
include_directories("${PROJECT_SOURCE_DIR}")
set(CMAKE_CXX_STANDARD 11)

set(ENGINE_SOURCES 
    Engine.cpp
    Etc/FloatHelper.cpp
    Etc/EntityIdGenerator.cpp
    
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
    Ecs/Components/DespawnOutsideScreen.cpp
    Ecs/Components/Acceleration.cpp
    Ecs/Components/Shootable.cpp
    Ecs/Components/BulletCollidable.cpp
    Ecs/Components/ProjectileCollidable.cpp
    Ecs/Components/Projectile.cpp

    Ecs/EcsExecutor.cpp
    Ecs/Systems/MovePlayerSystem.cpp
    Ecs/Systems/CollectInputSystem.cpp
    Ecs/Systems/SpawnBulletSystem.cpp
    Ecs/Systems/ApplyVelocitySystem.cpp
    Ecs/Systems/MoveCameraSystem.cpp
    Ecs/Systems/AsteroidSpawnSystem.cpp
    Ecs/Systems/DespawnEntitiesSystem.cpp
    Ecs/Systems/ApplyAccelerationSystem.cpp
    Ecs/Systems/CheckCollisionsSystem.cpp
    Ecs/Systems/BulletCollisionSystem.cpp
    Ecs/Systems/AsteroidCollisionSystem.cpp

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
    Etc/Vector2.h
    Etc/Rect.h
    Etc/EntityIdGenerator.h

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
    Ecs/Components/Shootable.h
    Ecs/Components/BulletCollidable.h

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
    Ecs/Components/DespawnOutsideScreen.h
    Ecs/Components/Acceleration.h
    Ecs/Components/ProjectileCollidable.h
    Ecs/Components/Projectile.h
    
    Ecs/EcsExecutor.h
    Ecs/Systems/MovePlayerSystem.h
    Ecs/Systems/CollectInputSystem.h
    Ecs/Systems/SpawnBulletSystem.h
    Ecs/Systems/ApplyVelocitySystem.h
    Ecs/Systems/MoveCameraSystem.h
    Ecs/Systems/AsteroidSpawnSystem.h
    Ecs/Systems/ApplyAccelerationSystem.h
    Ecs/Systems/CheckCollisionsSystem.h
    Ecs/Systems/BulletCollisionSystem.h
    Ecs/Systems/AsteroidCollisionSystem.h

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
set(SOIL_DIR "D:/projects/libraries/soil")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(SOIL REQUIRED)

file(COPY ${SDL2_BINARIES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_library(snail_core ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_link_libraries(snail_core 
                        ${SDL2_LIBRARIES} 
                        ${OPENGL_gl_LIBRARY}
                        ${SOIL}
)

target_include_directories( 
                            snail_core
                            PUBLIC ${GLAD_INCLUDE_DIR} 
                            PUBLIC ${SDL2_INCLUDE_DIRS} 
                            PUBLIC ${GLAD_DIRECTORIES} 
                            PUBLIC ${GLM_INCLUDE_DIRS} 
                            PUBLIC ${SOIL_INCLUDE_DIRS}
)
