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
 * File:   Asteroid.h
 * Author: LedoCool
 *
 * Created on December 22, 2018, 4:36 PM
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#include "engine/includes.h"
#include "engine/Ecs/Entity.h"
#include "engine/Graphics/Drawables/IDrawable.h"
#include "engine/Etc//Vector2.h"

class Asteroid : public IDrawable, public Entity
{
public:
    Asteroid(const float radius, const Vector2<float> & coordinates, const Vector2<float> & velocity);
    virtual ~Asteroid();
    
    void Draw(glm::mat4 projection) override;

private:
    float _shape[150];
};

#endif /* ASTEROID_H */

