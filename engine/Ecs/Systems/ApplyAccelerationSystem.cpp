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
 * File:   ApplyAccelerationSystem.cpp
 * Author: LedoCool
 * 
 * Created on January 2, 2019, 6:44 PM
 */

#include "ApplyAccelerationSystem.h"
#include "engine/Ecs/Components/IncludeComponents.h"

ApplyAccelerationSystem::ApplyAccelerationSystem()
{
}

ApplyAccelerationSystem::ApplyAccelerationSystem(const ApplyAccelerationSystem& orig)
{
}

ApplyAccelerationSystem::~ ApplyAccelerationSystem()
{
}

void ApplyAccelerationSystem::Execute(Uint32 dt, std::shared_ptr<GameState>& gameState)
{
    for (auto entity : gameState->map->GetEntities())
    {
        auto acceleration = std::dynamic_pointer_cast<Acceleration>(entity->GetComponent(ComponentTypes::ACCELERATION).lock());
        auto velocity = std::dynamic_pointer_cast<Velocity> (entity->GetComponent(ComponentTypes::VELOCITY).lock());
        
        if (! (acceleration && velocity))
        {
            continue;
        }

        if (! FloatHelper::IsNull(acceleration->rotation()))
        {
            velocity->rotation(velocity->rotation() + acceleration->rotation() * dt);
        }

        if(!acceleration->vector().IsNull())
        {
            auto vel = acceleration->vector() * dt;
            velocity->velocity(velocity->velocity() + vel);
        }
    }
}
