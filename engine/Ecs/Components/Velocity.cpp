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
 * File:   Velocity.cpp
 * Author: LedoCool
 * 
 * Created on December 23, 2018, 1:13 PM
 */

#include "Velocity.h"

Velocity::Velocity(const float & velX, const float & velY, const float & rotVel)
{
    _x = velX;
    _y = velY;
    _rotationalVelocity = rotVel;
}

float Velocity::rotation()
{
    return _rotationalVelocity;
}

void Velocity::rotation(const float & rot)
{
    _rotationalVelocity = rot;
}

float Velocity::x()
{
    return _x;
}

void Velocity::x(const float & x)
{
    _x = x;
}

float Velocity::y()
{
    return _y;
}

void Velocity::y(const float & y)
{
    _y = y;
}

unsigned int Velocity::GetComponentId()
{
    return ComponentTypes::VELOCITY;
}


Velocity::~ Velocity()
{
}

