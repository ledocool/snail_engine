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
 * File:   Bullet.h
 * Author: LedoCool
 *
 * Created on December 23, 2018, 12:13 AM
 */

#ifndef BULLET_H
#define BULLET_H

#include "engine/includes.h"
#include "engine/Ecs/Entity.h"
#include "engine/Graphics/Drawables/IDrawable.h"
#include "engine/Etc/Vector2.h"

class Bullet : public IDrawable, public Entity
{
public:
    Bullet(const float size, const Vector2<float> coordinates, const float angle, const float velocity);
    virtual ~Bullet();
    
    void Draw(glm::mat4 projection) override;

private:
    
    float _shape[18];
};

#endif /* BULLET_H */

