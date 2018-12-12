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
 * File:   InputEventConfig.h
 * Author: LedoCool
 *
 * Created on December 11, 2018, 8:45 PM
 */

#ifndef INPUTEVENTCONFIG_H
#define INPUTEVENTCONFIG_H

#include "engine/includes.h"
#include "PlayerActions.h"
#include "KeyEnums.h"
#include "InputManager.h"
#include "engine/Events/EventPipeline.h"

class InputEventConfig
{
public:
    InputEventConfig();
    virtual ~InputEventConfig();
    
    void GatherInputEvents(InputManager * inputManager, EventPipeline * eventPipeline);
    
private:
    std::vector<std::vector<std::pair<Key::en, KeyState::en>>> _keyCombinations;
    std::vector< PlayerActions::en > _keyEvents; 

};

#endif /* INPUTEVENTCONFIG_H */

