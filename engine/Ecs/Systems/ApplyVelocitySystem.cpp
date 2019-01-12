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
 * File:   ApplyVelocitySystem.cpp
 * Author: LedoCool
 * 
 * Created on December 23, 2018, 4:17 PM
 */

#include "ApplyVelocitySystem.h"
#include "engine/Etc/FloatHelper.h"
#include "engine/Ecs/Components/IncludeComponents.h"

ApplyVelocitySystem::ApplyVelocitySystem()
{
}

ApplyVelocitySystem::~ ApplyVelocitySystem()
{
}

void ApplyVelocitySystem::Execute(Uint32 dt, std::shared_ptr<GameState>& gameState)
{
    for (auto entity : gameState->map->GetEntities())
    {
//        std::shared_ptr<Entity> entity = weakEntity.lock();
//        if(!entity)
//        {
//            continue;
//        }
        
        auto position = std::dynamic_pointer_cast<Position>(entity->GetComponent(ComponentTypes::POSITION).lock());
        auto velocity = std::dynamic_pointer_cast<Velocity> (entity->GetComponent(ComponentTypes::VELOCITY).lock());
        
        if (! (position && velocity))
        {
            continue;
        }

        if (! FloatHelper::IsNull(velocity->rotation()))
        {
            float newRotation = position->angle() + velocity->rotation() * dt;
            position->angle(newRotation);
        }

        if(!velocity->velocity().IsNull())
        {
            auto vel = velocity->velocity() * dt;
            position->coords(position->coords() + vel);
        }
    }
}

