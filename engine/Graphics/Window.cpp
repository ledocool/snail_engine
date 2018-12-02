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
 * File:   Window.cpp
 * Author: LedoCool
 * 
 * Created on August 19, 2018, 6:48 PM
 */

#include "Window.h"

Window::Window(const char *title, const unsigned int x, const unsigned int y, const unsigned int height, const unsigned int width)
{
    auto win = SDL_CreateWindow(title, x, y, height, width, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    _window.reset(win, SDL_DestroyWindow);
    
    //Todo: create context in graphics manager;
    _context = SDL_GL_CreateContext(_window.get());
    SetContextActive();
}

Window::~Window()
{
}

int Window::SetContextActive()
{
    SDL_GL_MakeCurrent(_window.get(), _context);
}

void Window::ProcessEvents(float dt)
{

}

void Window::Render(float dt)
{

}

void Window::Update(float dt)
{

}


