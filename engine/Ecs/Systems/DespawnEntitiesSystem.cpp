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
 * File:   DespawnEntities.cpp
 * Author: LedoCool
 * 
 * Created on December 28, 2018, 9:34 PM
 */

#include "DespawnEntitiesSystem.h"
#include "engine/Ecs/Components/IncludeComponents.h"
#include "engine/Etc/Rect.h"
#include "engine/Ecs/Entity.h"
#include "engine/Etc/Vector2.h"

DespawnEntitiesSystem::DespawnEntitiesSystem()
{
}

DespawnEntitiesSystem::~ DespawnEntitiesSystem()
{
}

void DespawnEntitiesSystem::Execute(Uint32 dt, std::shared_ptr<GameState>& gameState)
{
    std::vector< std::shared_ptr<Entity> > toBeRemoved;
    for(auto entity : gameState->map->GetEntities())
    {
        if(TryDespawnOutsideSquare(entity, gameState->camera->GetScreenRect()))
        {
            toBeRemoved.push_back(entity);
        }   
    }

    if(!toBeRemoved.empty())
    {
        if(toBeRemoved.size() > 1)
        {
            gameState->map->RemoveEntities(toBeRemoved);
        }else{
            gameState->map->RemoveEntity(toBeRemoved[0]);
        }
        
        if(gameState->asteroidCounter < toBeRemoved.size())
        {
            gameState->asteroidCounter = 0;
        }else{
            gameState->asteroidCounter -= toBeRemoved.size();
        }
    }
}

bool DespawnEntitiesSystem::TryDespawnOutsideSquare(std::shared_ptr<Entity> entity, Rect<float> screenRect)
{
    auto size = std::dynamic_pointer_cast<Size>(entity->GetComponent(ComponentTypes::SIZE).lock());
    auto position = std::dynamic_pointer_cast<Position>(entity->GetComponent(ComponentTypes::POSITION).lock());
    auto despawnOutside = std::dynamic_pointer_cast<DespawnOutsideScreen>(entity->GetComponent(ComponentTypes::DESPAWN_OUTSIDE_SCREEN).lock());
    
    if(!(size && position && despawnOutside))
    {
        return false;
    }
    
    Vector2<float> posPlus(position->coords() + size->size()), 
                  posMinus(position->coords() - size->size());
    
    if(posPlus.x() < screenRect.left - despawnOutside->despawnMargin()
       || posMinus.x() > screenRect.right + despawnOutside->despawnMargin()
       || posPlus.y() < screenRect.bottom - despawnOutside->despawnMargin()
       || posMinus.y() > screenRect.top + despawnOutside->despawnMargin())
    {
        return true;
    }
    
    return false;
}


