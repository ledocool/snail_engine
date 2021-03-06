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
 * File:   SpawnBulletSystem.cpp
 * Author: LedoCool
 * 
 * Created on December 23, 2018, 2:32 PM
 */

#include "SpawnBulletSystem.h"
#include "engine/Ecs/Components/IncludeComponents.h"
#include "engine/Input/PlayerActions.h"
#include "engine/Graphics/Drawables/Bullet.h"

SpawnBulletSystem::SpawnBulletSystem()
{
}

SpawnBulletSystem::~ SpawnBulletSystem()
{
}

void SpawnBulletSystem::Execute(Uint32 dt, std::shared_ptr<GameState>& gameState)
{
    for(auto entity : gameState->map->GetEntities())
    {
        auto player = std::dynamic_pointer_cast<Player> (entity->GetComponent(ComponentTypes::PLAYER).lock());
        auto position = std::dynamic_pointer_cast<Position>( entity->GetComponent(ComponentTypes::POSITION).lock() );
        auto size = std::dynamic_pointer_cast<Size> (entity->GetComponent(ComponentTypes::SIZE).lock());
        if(!(player && position && size))
        {
            continue;
        }
        
        for(auto action : gameState->inputActions)
        {
            if(action.GetEvent() == PlayerActions::SHOOT)
            {
                float coordinates[2];
                coordinates[0] = position->x() + cos(position->angle()) * size->size();
                coordinates[1] = position->y() + sin(position->angle()) * size->size();
                                
                auto bullet = std::make_shared<Bullet>(10, coordinates, position->angle(), 0.2);
                gameState->map->AddEntity(bullet);
            }
        }
        
    }
}

