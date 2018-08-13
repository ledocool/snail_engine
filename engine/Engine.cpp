/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Engine.cpp
 * Author: LedoCool
 * 
 * Created on July 10, 2018, 9:25 PM
 */

#include "Engine.h"
#include <iostream>

Engine::Engine()
{
    //Todo: move me to dedicated class;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();
}

Engine::Engine(const Engine& orig)
{
}

Engine::~Engine()
{
}

void Engine::simpleFunction()
{
    std::cout << "Hello world!" << std::endl;
}

/* Wrapper method for all engine initialization */
void Engine::init()
{
    initSDL();
}

/* Wrapper method for all engine destruction */
void Engine::destroy()
{

}

void Engine::initSDL()
{

}

/* Base loop */
int Engine::loop()
{

}
