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
 * File:   Cannon.cpp
 * Author: LedoCool
 * 
 * Created on December 23, 2018, 4:47 PM
 */

#include "Cannon.h"
#include "ComponentTypes.h"

Cannon::Cannon(Uint32 maxCooldown)
{
    _maxCooldown = maxCooldown;
    _cooldown = 0;
}

Cannon::~ Cannon()
{
}

Uint32 Cannon::ReduceCooldown(Uint32 cooldown)
{
    if(cooldown > _cooldown)
    {
        _cooldown = 0;
    }else{
        _cooldown -= cooldown;
    }
    return _cooldown;
}

void Cannon::SetCooldownToMax()
{
    _cooldown = _maxCooldown;
}

void Cannon::cooldown(Uint32 val)
{
    _cooldown = val;
}

Uint32 Cannon::cooldown()
{
    return _cooldown;
}

void Cannon::maxCooldown(Uint32 val)
{
    _maxCooldown = val;
}

Uint32 Cannon::maxCooldown()
{
    return _maxCooldown;
}

unsigned int Cannon::GetComponentId()
{
    return ComponentTypes::CANNON;
}

