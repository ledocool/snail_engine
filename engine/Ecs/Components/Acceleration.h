/*
 * Copyright 2019 LedoCool.
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
 * File:   Acceleration.h
 * Author: LedoCool
 *
 * Created on January 2, 2019, 6:21 PM
 */

#ifndef ACCELERATION_H
#define ACCELERATION_H

#include "engine/Ecs/Component.h"
#include "engine/Etc/Vector2.h"

class Acceleration : public Component
{
public:
    Acceleration();
    Acceleration(const Vector2<float> & acceleration, const float rotation);
    virtual ~Acceleration();
    void vector(Vector2<float> & data);
    Vector2<float> vector();
    void rotation(float rotation);
    float rotation();
    
    unsigned int GetComponentId() override;
    
private:    
    Vector2<float> _vector;
    float _rotation;
};

#endif /* ACCELERATION_H */

