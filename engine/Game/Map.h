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
 * File:   Map.h
 * Author: LedoCool
 *
 * Created on December 4, 2018, 10:18 PM
 */

#ifndef MAP_H
#define MAP_H

#include "engine/Ecs/Entity.h"
#include "engine/Graphics/Drawables/IDrawable.h"
#include "Camera.h"
#include "engine/Input/Inputmanager.h"

class Map
{
public:
    Map();
    virtual ~Map();
    void AddEntity(std::shared_ptr<Entity> entity);
    void RemoveEntity();
    void SetScreenSize(unsigned int width, unsigned int height);
    
    void Render();   
    void Update(Uint32 dt);
    
private:
    Camera _camera;
    std::vector< std::shared_ptr<Entity> > _entities;
    
    InputManager * _inputManager;
};

#endif /* MAP_H */

