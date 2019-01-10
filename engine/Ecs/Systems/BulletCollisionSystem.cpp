/*
 * Copyright 2019 LedoCool.
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
 * File:   BulletCollisionSystem.cpp
 * Author: LedoCool
 * 
 * Created on January 9, 2019, 8:06 PM
 */

#include "BulletCollisionSystem.h"
#include "engine/Ecs/Components/IncludeComponents.h"

BulletCollisionSystem::BulletCollisionSystem()
{
}

BulletCollisionSystem::~BulletCollisionSystem()
{
}

void BulletCollisionSystem::Execute(Uint32 dt, std::shared_ptr<GameState>& gameState)
{
    for(auto collidingPair : gameState->collidingEntitites)
    {
        auto entity1 = collidingPair.first.lock();
        auto entity2 = collidingPair.second.lock();
        
        if(!(entity1 && entity2))
        {
            continue;
        }
        
        auto bulletComponent1 = entity1->GetComponent(ComponentTypes::SHOOTABLE).lock();
        auto bulletCollidableComponent1 = entity1->GetComponent(ComponentTypes::BULLET_COLLIDABLE).lock();
        auto bulletComponent2 = entity2->GetComponent(ComponentTypes::SHOOTABLE).lock();
        auto bulletCollidableComponent2 = entity2->GetComponent(ComponentTypes::BULLET_COLLIDABLE).lock();
        
        if((bulletComponent1 && bulletCollidableComponent2) 
            || (bulletComponent2 && bulletCollidableComponent1))
        {
            gameState->map->RemoveEntity(entity1);
            gameState->map->RemoveEntity(entity2);
        }
    }
}

