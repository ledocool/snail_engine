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
#include "Input/KeyStroke.h"

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
}

/* Wrapper method for all engine destruction */
void Engine::Destroy()
{
    DestroySDL();
}

void Engine::InitSDL()
{
    SDL_Init(SDL_INIT_VIDEO);
    _window = SDL_CreateWindow("snail_engine",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                640,
                                480,
                                0);
    
    
    //Todo: create context in graphics manager;
    SDL_Renderer *renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    //Todo: this above should be in graphics manager;
}

/* Base loop */
int Engine::Loop()
{
    InputManager man;
    
    bool shouldWork = true;
    while (shouldWork)
    {
        shouldWork = !man.Update();
    }
    
    return 0;
}

void Engine::DestroySDL()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}


