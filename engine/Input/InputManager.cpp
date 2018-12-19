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
 * File:   InpuManager.cpp
 * Author: LedoCool
 * 
 * Created on August 14, 2018, 10:57 PM
 */

#include "InputManager.h"

InputManager::InputManager()
{ 
}

InputManager::~InputManager()
{
}


KeyState::en InputManager::KeyState(Key::en key)
{
    return _keyStates[key];
}

bool InputManager::Update()
{
    SDL_Event event;
    std::vector <Key::en> keys;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            return false;
            break;
        case SDL_KEYDOWN:
            _keyStates[(Key::en)event.key.keysym.sym] = KeyState::DOWN;
            keys.push_back((Key::en)event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            _keyStates[(Key::en)event.key.keysym.sym] = KeyState::UP;
            keys.push_back((Key::en)event.key.keysym.sym);
            break;
//        case SDL_MOUSEMOTION:
//            _m_MouseX = event.motion.x;
//            _m_MouseY = event.motion.y; //Temp. Then we will check window coords
//            break;
//        case SDL_MOUSEBUTTONUP:
//            _mouseStates[event.button.button] = KEY_IS_UP;
//            clicks.push_back((mouseClick)event.button.which);
//            break;
//        case SDL_MOUSEBUTTONDOWN:
//            _mouseStates[event.button.button] = KEY_IS_DOWN;
//            clicks.push_back((mouseClick)event.button.which);
//            break;
//        case SDL_WINDOWEVENT:
//            _windowStates[(short)event.window.event] = 
//            if(event.window.event == SDL_WINDOWEVENT_RESIZED)
//                graphic->resizeViewport();
//            break;

        default:
            break;
        }
    }

    //check to see if any keys haven't been released but were press
    //ie being held

    for (std::map<Key::en, KeyState::en>::iterator itr = _keyStates.begin(); itr != _keyStates.end(); itr++) {
        //put no status flag
        if (itr->second == KeyState::UP) {
            bool keyFound = false;
            for (unsigned int i = 0; i < keys.size(); i++) {
                if (keys[i] == itr->first) {
                    keyFound = true;
                    break;
                }
            }

            if (!keyFound) {
                itr->second = KeyState::UNDEFINED;
            }
        }
        else if (itr->second == KeyState::DOWN) {
            bool keyFound = false;
            for (unsigned int i = 0; i < keys.size(); i++) {
                if (keys[i] == itr->first) {
                    keyFound = true;
                    break;
                }
            }

            if (!keyFound) {
                itr->second = KeyState::HELD;
            }
        }
    }
    
    return true;
}
