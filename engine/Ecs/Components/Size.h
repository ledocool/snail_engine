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
 * File:   Size.h
 * Author: LedoCool
 *
 * Created on December 23, 2018, 12:45 PM
 */

#ifndef SIZE_H
#define SIZE_H

#include "engine/Ecs/Component.h"
#include "ComponentTypes.h"

class Size : public Component
{
public:
    Size();
    Size(const float size);
    virtual ~Size();

    float size();
    void size(const float & size);

    virtual unsigned int GetComponentId() override;
    
private:
    float _size;
};

#endif /* SIZE_H */

