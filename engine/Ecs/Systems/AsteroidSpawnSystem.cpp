/*
 * Copyright 2018 LedoCool.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   AsteroidSpawnSystem.cpp
 * Author: LedoCool
 * 
 * Created on December 26, 2018, 10:09 PM
 */

#include "AsteroidSpawnSystem.h"

#include "engine/Graphics/Drawables/Asteroid.h"
#include "engine/Game/Camera.h"
#include "engine/Ecs/Components/IncludeComponents.h"
#include <time.h>

#define MAX_ASTEROIDS (5)
#define ASTEROID_SPEED (1e-1)
#define ASTEROID_COOLDOWN (1000 * 1)

AsteroidSpawnSystem::AsteroidSpawnSystem()
{
    std::srand (time(NULL));
}

AsteroidSpawnSystem::~ AsteroidSpawnSystem()
{
}

void AsteroidSpawnSystem::Execute(Uint32 dt, std::shared_ptr<GameState>& gameState)
{       
    if(!gameState->asteroidCooldown && gameState->asteroidCounter < MAX_ASTEROIDS)
    {   
        std::shared_ptr<Position> playerPosition;
        for(auto playerEntity : gameState->map->GetEntities())
        {
            if(auto position = std::dynamic_pointer_cast<Position>(playerEntity->GetComponent(ComponentTypes::POSITION).lock()))
            {
                if(auto player = playerEntity->GetComponent(ComponentTypes::PLAYER).lock())
                {
                    playerPosition = position;
                    break;
                }
            }
        }
        
        float cameraX, cameraY;
        unsigned int height, width;
        gameState->camera->GetScreenProportions(width, height);
        gameState->camera->GetCoordinates(cameraX, cameraY);

        float asteroidSize = 10.f;
        float velocity[2] = {0.f, 0.f}, 
                coords[2] = {0.f, 0.f};
        
        CalculateAsteroidCoordinates(cameraX, cameraY, height, width, coords);
        
        float dx = playerPosition->x() - coords[0], 
              dy = playerPosition->y() - coords[1];        
        float magnitude = std::sqrt(dx*dx + dy*dy);
        float normY = dy/magnitude, 
              normX = dx/magnitude;
        
        velocity[0] = ASTEROID_SPEED * normX;
        velocity[1] = ASTEROID_SPEED * normY;
        auto asteroid = std::make_shared<Asteroid>(asteroidSize, coords, velocity);
        gameState->map->AddEntity(asteroid);
        
        gameState->asteroidCounter += 1;
        gameState->asteroidCooldown = ASTEROID_COOLDOWN;
    }
    else if(gameState->asteroidCooldown > dt)
    {
        gameState->asteroidCooldown -= dt;
    }
    else
    {
        gameState->asteroidCooldown = 0;
    }
}

void AsteroidSpawnSystem::CalculateAsteroidCoordinates(float cameraX, float cameraY, 
                                                       unsigned int screenHeight, 
                                                       unsigned int screenWidth, 
                                                       float * coordinates)
{
    unsigned int halfHeight = screenHeight/2, halfWidth = screenWidth/2;
    
    float   randX = static_cast <float> (std::rand()) 
                    / static_cast <float> (RAND_MAX) * screenWidth, 
            randY = static_cast <float> (std::rand()) 
                    / static_cast <float> (RAND_MAX) * screenHeight;
    
    bool vertical = std::rand() % 2;
    float asteroidSize = 10.f;

    if(vertical)
    {
        coordinates[0] = randX + (cameraX - halfWidth);
        coordinates[1] = randY > halfHeight ? cameraY + asteroidSize + halfHeight
                                    : cameraY - asteroidSize - halfHeight;
    }
    else
    {
        coordinates[0] = randX > halfWidth ? cameraX + asteroidSize + halfWidth
                                    : cameraX - asteroidSize - halfWidth;
        coordinates[1] = randY + (cameraY - halfHeight);
    } 
}

