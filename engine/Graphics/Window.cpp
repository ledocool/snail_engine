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
#include "Game/Map.h"

Window::Window(const char *title, const unsigned int x, const unsigned int y, const unsigned int height, const unsigned int width)
{
    auto win = SDL_CreateWindow(title,
                                x == 0 ? SDL_WINDOWPOS_UNDEFINED : x,
                                y == 0 ? SDL_WINDOWPOS_UNDEFINED : y,
                                height,
                                width,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    _window.reset(win, SDL_DestroyWindow);

    //Todo: create context in graphics manager;
    _context = SDL_GL_CreateContext(_window.get());
    SetContextActive();
    //const unsigned char * version = glGetString(GL_VERSION);
    SetupOpenGlContext();

    SetupMap();    
}

Window::~Window()
{
}

void Window::SetupMap()
{
    _map = std::shared_ptr<Map>(new Map());
    int w,h;
    SDL_GetWindowSize(_window.get(), &w, &h);   
    _map->SetScreenSize(w,h);
}


int Window::SetContextActive()
{
    SDL_GL_MakeCurrent(_window.get(), _context);
}

void Window::Render(float dt)
{
    SetContextActive();
    glClear(GL_COLOR_BUFFER_BIT);
    _map->Render();
    
    SDL_GL_SwapWindow(_window.get());
}

void Window::Update(float dt)
{
    _map->Update(dt);
}

void Window::ResizeWindow()
{
    int w,h;
    SDL_GetWindowSize(_window.get(), &w, &h);   
    glViewport( 0, 0, ( GLsizei )w, ( GLsizei )h );
}

void Window::SetupOpenGlContext()
{
    int w,h;
    SDL_GetWindowSize(_window.get(), &w, &h);    
    
     // Request an OpenGL 4.5 context (should be core)
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    // Also request a depth buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    
    glClearColor( 0.9f, 0.9f, 0.9f, 1.f );
    glViewport( 0, 0, ( GLsizei )w, ( GLsizei )h );
}
