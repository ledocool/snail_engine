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

#ifndef ENGINE_H
#define ENGINE_H

#include "includes.h"
#include "SDL.h"
#include "engine/Graphics/WindowManager.h"
#include "engine/Input/InputManager.h"

class Engine
{
public:
    Engine();
    virtual ~Engine();

private:
    int Loop();

    void Init();
    void InitSDL();
    void CreateWindows();

    void Destroy();
    void DestroySDL();

    WindowManager _wm;
    InputManager * _inputManager;
};

#endif /* ENGINE_H */

