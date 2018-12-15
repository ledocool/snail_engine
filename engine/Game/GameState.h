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
 * File:   GameState.h
 * Author: LedoCool
 *
 * Created on December 15, 2018, 6:34 PM
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "engine/includes.h"
#include "engine/Game/Map.h"
#include "engine/Game/Camera.h"

struct GameState
{    
    std::shared_ptr<Map> map;
    std::shared_ptr<Camera> camera;
    
};

#endif /* GAMESTATE_H */

