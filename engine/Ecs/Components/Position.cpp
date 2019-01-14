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
 * File:   Position.cpp
 * Author: LedoCool
 * 
 * Created on December 5, 2018, 2:54 PM
 */

#include "Position.h"

Position::Position()
{

}

Position::Position(const Vector2<float>& coords, const float& angle)
{
    _pos = coords;
    _angle = angle;
}

Position::~Position()
{
}

Vector2<float> Position::coords()
{
    return _pos;
}

void Position::coords(Vector2<float> vec)
{
    _pos = vec;
}

float Position::angle()
{
    return _angle;
}

void Position::angle(float angle)
{
    if (angle >= 2 * M_PI)
    {
        angle -= 2 * M_PI;
    }
    else if (angle < 0)
    {
        angle += 2 * M_PI;
    }       
    _angle = angle;
}

unsigned int Position::GetComponentId()
{
    return ComponentTypes::POSITION;
}

