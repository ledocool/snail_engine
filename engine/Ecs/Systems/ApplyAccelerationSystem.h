/*
 * Copyright 2019 LedoCool.
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
 * File:   ApplyAccelerationSystem.h
 * Author: LedoCool
 *
 * Created on January 2, 2019, 6:44 PM
 */

#ifndef APPLYACCELERATIONSYSTEM_H
#define APPLYACCELERATIONSYSTEM_H

#include "engine/includes.h"
#include "engine/Ecs/System.h"

class ApplyAccelerationSystem : public System
{
public:
    ApplyAccelerationSystem();
    ApplyAccelerationSystem(const ApplyAccelerationSystem& orig);
    virtual ~ApplyAccelerationSystem();
    void Execute(Uint32 dt, std::shared_ptr<GameState>& gameState) override;
    
private:

};

#endif /* APPLYACCELERATIONSYSTEM_H */

