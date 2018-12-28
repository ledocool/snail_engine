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
 * File:   CollectInputSystem.h
 * Author: LedoCool
 *
 * Created on December 19, 2018, 10:53 PM
 */

#ifndef COLLECTINPUTSYSTEM_H
#define COLLECTINPUTSYSTEM_H

#include "engine/includes.h"
#include "engine/Ecs/System.h"
#include "Input/InputEventConfig.h"
#include "Input/InputManager.h"

class CollectInputSystem : public System
{
public:
    CollectInputSystem();
    virtual ~CollectInputSystem();
    void Execute(Uint32 dt, std::shared_ptr<GameState>& gameState) override;
    
private:
    InputManager * _inputManager;
    InputEventConfig * _eventConfig;
};

#endif /* COLLECTINPUTSYSTEM_H */

