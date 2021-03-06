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
 * File:   MovePlayerSystem.h
 * Author: LedoCool
 *
 * Created on December 15, 2018, 3:54 PM
 */

#ifndef MOVEPLAYERSYSTEM_H
#define MOVEPLAYERSYSTEM_H

#include "engine/includes.h"
#include "engine/Ecs/System.h"

class MovePlayerSystem : public System
{
public:
    MovePlayerSystem();
    MovePlayerSystem(const MovePlayerSystem& orig);
    virtual ~MovePlayerSystem();

    void Execute(Uint32 dt, std::shared_ptr<GameState> & gameState) override;
    
private:
    float bleedSpeed(float oldValue, float bleedFactor);
    float capSpeed(float speed, float cap);
    
    float calculateRotation(Uint32 dt, float rotation, float addRotation);
    void calculateSpeed(Uint32 dt, float & x, float & y, float angle, float speed);
};

#endif /* MOVEPLAYERSYSTEM_H */

