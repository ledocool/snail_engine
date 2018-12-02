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
 * File:   Window.h
 * Author: LedoCool
 *
 * Created on August 19, 2018, 6:48 PM
 */

#ifndef WINDOW_H
#define WINDOW_H

#include "engine/includes.h"

class Window 
{
public:
    Window(const char *title, const unsigned int x, const unsigned int y, const unsigned int height, const unsigned int width);
    virtual ~Window();
    
    SetContextActive();
    
    virtual void Update(float dt);
    virtual void Render(float dt);
    virtual void ProcessEvents(float dt);
private:

   
    std::shared_ptr<SDL_Window> _window;
    SDL_GLContext _context;
};

#endif /* WINDOW_H */

