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
 * File:   Acceleration.cpp
 * Author: LedoCool
 * 
 * Created on January 2, 2019, 6:21 PM
 */

#include "Acceleration.h"
#include "ComponentTypes.h"

Acceleration::Acceleration()
{
    _vector.set(0.f, 0.f);
    _rotation = 0.f;
}

Acceleration::Acceleration(const Vector2<float> & acceleration, const float rotation)
{
    _vector = acceleration;
    _rotation = rotation;
}

Acceleration::~ Acceleration()
{
}

void Acceleration::vector(Vector2<float> & data)
{
    _vector = data;
}

Vector2<float> Acceleration::vector()
{
    return _vector;
}

void Acceleration::rotation(float rotation)
{
    _rotation = rotation;
}   

float Acceleration::rotation()
{
    return _rotation;
}

unsigned int Acceleration::GetComponentId()
{
    return ComponentTypes::ACCELERATION;
}

