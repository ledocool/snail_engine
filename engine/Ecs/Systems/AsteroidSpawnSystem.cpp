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
    if(!gameState->asteroidCooldown)
    {   
        if(gameState->asteroidCounter < MAX_ASTEROIDS)
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

            float asteroidSize = 10.f;
            auto cameraPos = gameState->camera->GetCoordinates();
            auto screenSize = gameState->camera->GetScreenProportions();

            auto coords = CalculateAsteroidCoordinates(cameraPos, screenSize, asteroidSize);                       
            Vector2<float> delta = playerPosition->coords() - coords;
            auto normDelta = delta.Normal();
            Vector2<float> velocity (normDelta * ASTEROID_SPEED);
            gameState->map->AddEntity(std::make_shared<Asteroid>(asteroidSize, coords, velocity));

            gameState->asteroidCounter += 1;
            gameState->asteroidCooldown = ASTEROID_COOLDOWN;
        }
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

Vector2<float> AsteroidSpawnSystem::CalculateAsteroidCoordinates(Vector2<float> & cameraCoordinates, 
                                                                 Vector2<unsigned int> & screenProportions, 
                                                                 float asteroidSize) const
{
    Vector2<unsigned int> halfScreen = screenProportions / 2;
    float   randX = static_cast <float> (std::rand()) 
                    / static_cast <float> (RAND_MAX) * screenProportions.x(), 
            randY = static_cast <float> (std::rand()) 
                    / static_cast <float> (RAND_MAX) * screenProportions.y();
    
    bool vertical = std::rand() % 2;
    
    Vector2<float> coordinates;
    if(vertical)
    {   
        coordinates[0] = randX + cameraCoordinates.x() - halfScreen.x();
        coordinates[1] = randY > screenProportions.y() 
                ? cameraCoordinates.y() + /*asteroidSize +*/ halfScreen.y()
                : cameraCoordinates.y() - /*asteroidSize -*/ halfScreen.y();
    }
    else
    {
        coordinates[0] = randX > screenProportions.x() 
                ? cameraCoordinates.x() + /*asteroidSize +*/ halfScreen.x()
                : cameraCoordinates.x() - /*asteroidSize -*/ halfScreen.x();
        coordinates[1] = randY + cameraCoordinates.y() - halfScreen.y();
    }
    
    return coordinates;
}
