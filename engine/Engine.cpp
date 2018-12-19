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

#include "engine/Managers/WindowManager.h"
#include "engine/Events/EventPipeline.h"
#include "engine/Input/InputEventConfig.h"

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
    _inputManager = Singleton<InputManager>::get();
    
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
    bool shouldWork = true;
    Uint32  dt = 16;
    Uint32  lastUpdateTime, 
            frameTime, 
            currentUpdateTime,
            processingElapsed,
            lastProcessingTime,
            timeleft;
    
    //inputManager->Update();
    lastProcessingTime = lastUpdateTime = currentUpdateTime = SDL_GetTicks();
    
    while (shouldWork) 
    {
        currentUpdateTime = SDL_GetTicks();
        frameTime = currentUpdateTime - lastUpdateTime;
        lastUpdateTime = currentUpdateTime;
        
        timeleft = dt - frameTime;
        do
        {
            currentUpdateTime = SDL_GetTicks();
            processingElapsed = currentUpdateTime - lastProcessingTime;
            lastProcessingTime = currentUpdateTime;
            
            shouldWork = _inputManager->Update();
            _wm.Update(processingElapsed);
        }
        while(currentUpdateTime < lastUpdateTime + timeleft && shouldWork);
        _wm.Render(frameTime);
    }

    return 0;
}

void Engine::DestroySDL()
{
    SDL_Quit();
}


