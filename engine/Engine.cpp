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

#include "Engine.h"
#include <iostream>

#include "Input/InputManager.h"
#include "Managers/WindowManager.h"
#include "Events/EventPipeline.h"
#include "Input/InputEventConfig.h"

Engine::Engine()
{   
    Init();
    Loop();
}

Engine::~Engine()
{
    Destroy();
}

/* Wrapper method for all engine initialization */
void Engine::Init()
{
    InitSDL();
    CreateWindows();
}

/* Wrapper method for all engine destruction */
void Engine::Destroy()
{
    DestroySDL();
}

void Engine::InitSDL()
{
    if (SDL_Init(0)) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }
    //SDL_GL_LoadLibrary(NULL);
}

void Engine::CreateWindows()
{
    _wm.Create("Base window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480);
}

/* Base loop */
int Engine::Loop()
{
    auto inputManager = Singleton<InputManager>::get();
    auto eventPipeline = Singleton<EventPipeline>::get();
    auto inputEventconfig = Singleton<InputEventConfig>::get();

    bool shouldWork = true;
    Uint32  lastUpdateTime, 
            frameTime, 
            currentUpdateTime;
    
    lastUpdateTime = currentUpdateTime = SDL_GetTicks();
    
    while (shouldWork) {
        currentUpdateTime = SDL_GetTicks();
        frameTime = currentUpdateTime - lastUpdateTime;
        lastUpdateTime = currentUpdateTime;
        
        shouldWork = !inputManager->Update();
        inputEventconfig->GatherInputEvents(inputManager, eventPipeline);
        _wm.Update(frameTime);
        _wm.Render(frameTime);
        eventPipeline->PropagateEvents();
        
        
    }

    return 0;
}

void Engine::DestroySDL()
{
    SDL_Quit();
}


