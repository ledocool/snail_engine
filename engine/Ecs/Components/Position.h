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
 * File:   Position.h
 * Author: LedoCool
 *
 * Created on December 5, 2018, 2:54 PM
 */

#ifndef POSITION_H
#define POSITION_H

#include "engine/Ecs/Component.h"
#include "ComponentTypes.h"

class Position : public Component
{
public:
    Position();
    Position(float x, float y);
    virtual ~Position();
    
    float x();
    void x(float x);
    
    float y();
    void y(float y);
    
    virtual unsigned int GetComponentType();
    
private:
    float _x, _y, _angle;
    
};

#endif /* POSITION_H */

