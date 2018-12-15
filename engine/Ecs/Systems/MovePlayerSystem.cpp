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
 * File:   MovePlayerSystem.cpp
 * Author: LedoCool
 * 
 * Created on December 15, 2018, 3:54 PM
 */

#include "MovePlayerSystem.h"
#include "engine/Ecs/Components/IncludeComponents.h"
#include "engine/Etc/Singleton.h"
#include "engine/Events/EventPipeline.h"
#include "engine/Events/InputEvent.h"
#include "engine/Input/PlayerActions.h"

#define PLAYER_MOVE_SPEED (0.3)
#define PLAYER_ROTATION_SPEED (0.007)

MovePlayerSystem::MovePlayerSystem()
{
}

MovePlayerSystem::MovePlayerSystem(const MovePlayerSystem& orig)
{
}

MovePlayerSystem::~MovePlayerSystem()
{
}

void MovePlayerSystem::Execute(Uint32 dt, std::shared_ptr<GameState> & gameState)
{
    auto entitites = gameState->map->GetEntities();
    for(std::shared_ptr<Entity> entity : entitites)
    {
        auto component = entity->GetComponent(ComponentTypes::POSITION).lock();
        if(!component)
        {
            continue;
        }
        
        auto position = std::dynamic_pointer_cast<Position>(component);
        if(!position)
        {
            continue;
        }
        
        auto eventPipeline = Singleton<EventPipeline>::get();
        float acceleration = 0.f, rotation = 0.f;
        
        for(std::weak_ptr<InputEvent> weakInput : eventPipeline->GetEvents<InputEvent>())
        {
            auto inputEvent = weakInput.lock();
            if(!inputEvent)
            {
                continue;
            }
            
            switch(inputEvent->GetEvent())
            {
            case PlayerActions::GO_FORWARD:
                acceleration += dt * PLAYER_MOVE_SPEED;
                break;
            case PlayerActions::GO_BACKWARD:
                acceleration -= dt * PLAYER_MOVE_SPEED;
                break;
            case PlayerActions::TURN_LEFT:
                rotation += dt * PLAYER_ROTATION_SPEED;
                break;
            case PlayerActions::TURN_RIGHT:
                rotation -= dt * PLAYER_ROTATION_SPEED;
                break;
            }
        }
        
        position->angle( position->angle() + rotation );
        position->x( 
                position->x() + std::cos(position->angle()) * acceleration
            );
        
        position->y( 
                position->y() + std::sin(position->angle()) * acceleration
            );
    }
    
}

