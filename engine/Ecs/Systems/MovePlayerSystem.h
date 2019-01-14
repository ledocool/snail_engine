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
#include "engine/Etc/Vector2.h"

class MovePlayerSystem : public System
{
public:
    MovePlayerSystem();
    MovePlayerSystem(const MovePlayerSystem& orig);
    virtual ~MovePlayerSystem();

    void Execute(Uint32 dt, std::shared_ptr<GameState> & gameState) override;
    
private:
    Vector2<float> bleedSpeed(Vector2<float> oldValue, Vector2<float> bleedFactor);
    float bleedSpeed(float oldValue, float bleedFactor); 
    Vector2<float> capSpeed(Vector2<float> speed, float cap);
    float capSpeed(float speed, float cap); 
    
    float calculateRotation(Uint32 dt, float rotation, float addRotation);
    Vector2<float> calculateSpeed(Uint32 dt, Vector2<float> velocity, Vector2<float> acceleration);
};

#endif /* MOVEPLAYERSYSTEM_H */

