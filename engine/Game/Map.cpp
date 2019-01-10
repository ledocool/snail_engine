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
 * File:   Map.cpp
 * Author: LedoCool
 * 
 * Created on December 4, 2018, 10:18 PM
 */

#include "Map.h"

#include "engine/includes.h"
#include "engine/Graphics/Drawables/Spaceship.h"
#include "engine/Graphics/Drawables/Asteroid.h"
#include "engine/Graphics/Drawables/Bullet.h"
#include "engine/Events/EventPipeline.h"
#include "engine/Events/EventTypes.h"
#include "engine/Events/Event.h"
#include "engine/Events/InputEvent.h"
#include "engine/Input/PlayerActions.h"

Map::Map()
{
    std::shared_ptr<Spaceship> playerSpaceship = std::shared_ptr<Spaceship> (new Spaceship(Vector2<float>(0.f, 0.f)));
    _entities.push_back(playerSpaceship);
}

Map::~Map()
{
}

void Map::Render(glm::mat4 projection)
{
    for(auto & entity : _entities)
    {
        auto ptr = std::dynamic_pointer_cast<IDrawable>(entity);
        if(ptr)
        {
            ptr->Draw(projection);
        }
    }
}

void Map::AddEntity(std::shared_ptr<Entity> entity)
{
    _entities.push_back(entity);
}

void Map::RemoveEntity(std::shared_ptr<Entity> removable)
{
    auto iterator = FindEntity(removable);
    if(iterator != _entities.end())
    {
        _entities.erase(iterator);
    }
}

std::vector<std::shared_ptr<Entity> >::iterator Map::FindEntity(std::shared_ptr<Entity> entity)
{
    for(std::vector< std::shared_ptr<Entity> >::iterator en = _entities.begin(); en < _entities.end(); en++)
    {
        unsigned int id = (*en)->GetId();
        if(id == entity->GetId())
        {
            return en;
        }
    }
    
    return _entities.end();
}

void Map::RemoveEntities(std::vector<std::shared_ptr<Entity> > removables)
{
    std::vector< std::shared_ptr<Entity> > newEntities;
    
    for(auto mapEntity : _entities)
    {
        bool toBeRemoved = false;
        
        for(auto entity : removables)
        {
            auto iterator = FindEntity(entity);
            if(iterator != _entities.end())
            {
                toBeRemoved = true;
                break;
            }
            
        }
        
        if(!toBeRemoved)
        {
            newEntities.push_back(mapEntity);
        }
    }
    
    if(!newEntities.empty())
    {
        _entities = newEntities;
    }
}

std::vector< std::shared_ptr<Entity> > Map::GetEntities()
{   
    return _entities;
}

