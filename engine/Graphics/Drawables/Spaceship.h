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
 * File:   Spaceship.h
 * Author: LedoCool
 *
 * Created on December 5, 2018, 2:50 PM
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "engine/includes.h"
#include "engine/Ecs/Entity.h"
#include "engine/Graphics/Drawables/IDrawable.h"

class Spaceship : public Entity, public IDrawable
{
public:
    Spaceship(float shape[9], float coordinates[2]);
    Spaceship(const Spaceship& orig);
    virtual ~Spaceship();
    
    void Draw(glm::mat4 projectionMatrix) override;
    
private:
    float _shape[9];
};

#endif /* SPACESHIP_H */

