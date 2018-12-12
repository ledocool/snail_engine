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
    _x = 0;
    _y = 0;
}

Position::Position(float x, float y)
{
    _x = x;
    _y = y;
}

Position::~Position()
{
}

float Position::x()
{
    return _x;
}

void Position::x(float x)
{
    _x = x;
}

float Position::y()
{
    return _y;
}

void Position::y(float y)
{
    _y = y;
}

unsigned int Position::GetComponentType()
{
    return ComponentTypes::POSITION;
}

