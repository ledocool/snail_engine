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
#include "engine/Etc/Vector2.h"

class Position : public Component
{
public:
    Position();
    Position(const Vector2<float> & coords, const float & angle);
    virtual ~Position();
    
    Vector2<float> coords();
    void coords(Vector2<float> vec);
    
    float angle();
    void angle(float angle);
    
    virtual unsigned int GetComponentId() override;
    
private:
    Vector2<float> _pos;
    float _angle;
    
};

#endif /* POSITION_H */

