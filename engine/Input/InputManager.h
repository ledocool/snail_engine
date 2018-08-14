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
 * File:   InpuManager.h
 * Author: LedoCool
 *
 * Created on August 14, 2018, 10:57 PM
 */

#ifndef INPUMANAGER_H
#define INPUMANAGER_H

#include "KeyEnums.h"
#include "includes.h"

class KeyStroke;

class InputManager 
{
public:
    friend KeyStroke;
    
    InputManager();
    virtual ~InputManager();
    
    bool Update(); //Don't forget to update this; 
    
protected:
    KeyState::en KeyState(Key::en key);
    
private:
    std::map <Key::en, KeyState::en> _keyStates;
//    int _m_MouseX, _m_MouseY;
//    std::vector < short > _mouseStates;
//    std::map < int, short > _videoStates;
    
};

#endif /* INPUMANAGER_H */

