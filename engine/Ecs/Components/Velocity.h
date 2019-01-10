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
 * File:   Velocity.h
 * Author: LedoCool
 *
 * Created on December 23, 2018, 1:13 PM
 */

#ifndef VELOCITY_H
#define VELOCITY_H

#include "ComponentTypes.h"
#include "engine/Ecs/Component.h"
#include "engine/Etc/Vector2.h"

class Velocity : public Component
{
public:
    Velocity(const Vector2<float> & velocity, const float & rotVel);
    virtual ~Velocity();
    
    Vector2<float> velocity();
    void velocity(const Vector2<float> & newVelocity); 
    float rotation();    
    void rotation(const float & rot);
    
    unsigned int GetComponentId() override;
    
private:
    
    Vector2<float> _velocity;
    float _rotationalVelocity;
    float _maxVelocity, _maxRotation;
};

#endif /* VELOCITY_H */

