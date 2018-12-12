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
#include "engine/Graphics/Drawables/Spaceship.h"
#include "engine/Etc/Singleton.h"
#include "engine/Events/EventPipeline.h"
#include "engine/Events/EventTypes.h"

Map::Map()
{
    float coords[2] = {0.f, 0.f},
          vertices[9] = {
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.0f,  0.5f, 0.0f
            };
    
    std::shared_ptr<Spaceship> playerSpaceship = std::shared_ptr<Spaceship> (new Spaceship(vertices, coords));
    _entities.push_back(playerSpaceship);
    _inputManager = Singleton<InputManager>::get();
}

Map::~Map()
{
}

void Map::SetScreenSize(unsigned int width, unsigned int height)
{
    _camera.SetScreenProportions(width, height);
}

void Map::Render()
{
    auto projection = _camera.GetProjectionMatrix();
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

void Map::Update(Uint32 dt)
{
    auto eventPipeline = Singleton<EventPipeline>::get();
    auto events = eventPipeline->GetEvents(EventTypes::INPUT);
    if(!events.empty())
    {
        std::cout << "Imma working" << std::endl;
    }
}
