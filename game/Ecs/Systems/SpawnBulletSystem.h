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
 * File:   SpawnBulletSystem.h
 * Author: LedoCool
 *
 * Created on December 23, 2018, 2:32 PM
 */

#ifndef SPAWNBULLETSYSTEM_H
#define SPAWNBULLETSYSTEM_H

#include "engine/includes.h"
#include "engine/Ecs/System.h"

class SpawnBulletSystem : public System
{
public:
    SpawnBulletSystem();
    SpawnBulletSystem(const SpawnBulletSystem& orig);
    virtual ~SpawnBulletSystem();

    void Execute(Uint32 dt, std::shared_ptr<GameState>& gameState) override;
    
private:

};

#endif /* SPAWNBULLETSYSTEM_H */

