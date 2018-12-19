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
 * File:   InputEventConfig.cpp
 * Author: LedoCool
 * 
 * Created on December 11, 2018, 8:45 PM
 */

#include "InputEventConfig.h"
#include "engine/Events/EventTypes.h"

InputEventConfig::InputEventConfig()
{    
    int pressedHard = KeyState::DOWN + KeyState::HELD;
    
    _keyEvents.push_back(PlayerActions::GO_FORWARD);
    _keyCombinations.push_back(
            std::vector<std::pair<Key::en, int>>(
                1, std::pair<Key::en, int>(Key::KEY_UP, pressedHard)
            ));
    
    _keyEvents.push_back(PlayerActions::GO_BACKWARD);
    _keyCombinations.push_back(
            std::vector<std::pair<Key::en, int>>(
                1, std::pair<Key::en, int>(Key::KEY_DOWN, pressedHard)
            ));
    
    _keyEvents.push_back(PlayerActions::TURN_LEFT);
    _keyCombinations.push_back(
            std::vector<std::pair<Key::en, int>>(
                1, std::pair<Key::en, int>(Key::KEY_LEFT, pressedHard)
            ));
    
    _keyEvents.push_back(PlayerActions::TURN_RIGHT);
    _keyCombinations.push_back(
            std::vector<std::pair<Key::en, int>>(
                1, std::pair<Key::en, int>(Key::KEY_RIGHT, pressedHard)
            ));
}

InputEventConfig::~InputEventConfig()
{
}

void InputEventConfig::GatherInputEvents(InputManager * inputManager, EventPipeline * eventPipeline)
{    
    unsigned int i = 0;
    for(auto combo : _keyCombinations)
    {
        bool comboGood = true;
        for(std::pair<Key::en, int> stroke : combo)
        {
            if( !(static_cast<int>(inputManager->KeyState(stroke.first)) & stroke.second) )
            {
                comboGood = false;
                break;
            }
        }
        
        if(comboGood)
        {
            PlayerActions::en action = _keyEvents[i];
            InputEvent * e = new InputEvent(action);
            eventPipeline->RegisterEvent(e);
        }
        i++;
    }
}

std::vector<InputEvent> InputEventConfig::GatherInputEvents(InputManager* inputManager)
{
    unsigned int i = 0;
    std::vector<InputEvent> result;
    
    for(auto combo : _keyCombinations)
    {
        bool comboGood = true;
        for(std::pair<Key::en, int> stroke : combo)
        {
            if( !(static_cast<int>(inputManager->KeyState(stroke.first)) & stroke.second) )
            {
                comboGood = false;
                break;
            }
        }
        
        if(comboGood)
        {
            PlayerActions::en action = _keyEvents[i];
            InputEvent e(action);
            result.push_back(e);
        }
        i++;
    }
    
    return result;
}


