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
 * File:   MoveCameraSystem.cpp
 * Author: LedoCool
 * 
 * Created on December 23, 2018, 4:41 PM
 */

#include "MoveCameraSystem.h"
#include "engine/includes.h"
#include "engine/Ecs/Components/IncludeComponents.h"

MoveCameraSystem::MoveCameraSystem()
{
}

MoveCameraSystem::~ MoveCameraSystem()
{
}

void MoveCameraSystem::Execute(Uint32 dt, std::shared_ptr<GameState>& gameState)
{
    for(auto entity : gameState->map->GetEntities())
    {
        auto position = std::dynamic_pointer_cast<Position> (entity->GetComponent(ComponentTypes::POSITION).lock());
        auto player = entity->GetComponent(ComponentTypes::PLAYER).lock();
        
        if(!(player && position))
        {
            continue;
        }
        
        auto coordinates = position->coords();
        gameState->camera->LookAt(coordinates.x(), coordinates.y());
    }
}

