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
#include "engine/Events/EventPipeline.h"
#include "engine/Events/EventTypes.h"
#include "engine/Events/Event.h"
#include "engine/Events/InputEvent.h"
#include "engine/Input/PlayerActions.h"

Map::Map()
{
    float coords[2] = {0.f, 0.f},
          vertices[9] = {
                -0.5f, 0.5f, 0.0f,
                0.9f, 0.0f, 0.0f,
                -0.5f, -0.5f, 0.0f
            };
    
    std::shared_ptr<Spaceship> playerSpaceship = std::shared_ptr<Spaceship> (new Spaceship(vertices, coords));
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

void Map::RemoveEntity()
{

}

std::vector< std::shared_ptr<Entity> > Map::GetEntities()
{   
    return _entities;
}

