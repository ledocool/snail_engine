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
 * File:   Cannon.h
 * Author: LedoCool
 *
 * Created on December 23, 2018, 4:47 PM
 */

#ifndef CANNON_H
#define CANNON_H

#include "engine/includes.h"
#include "engine/Ecs/Component.h"

#define SHOOT_COOLDOWN (240)

class Cannon : public Component
{
public:
    Cannon(Uint32 maxCooldown);
    virtual ~Cannon();
    void maxCooldown(Uint32 val);    
    Uint32 maxCooldown();
    void cooldown(Uint32 val);
    Uint32 cooldown();
    
    Uint32 ReduceCooldown(Uint32 cooldown);
    void SetCooldownToMax();
    
    unsigned int GetComponentId() override;

    
private:
    Uint32 _cooldown, _maxCooldown;
};

#endif /* CANNON_H */

