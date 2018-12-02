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
 * File:   WindowManager.cpp
 * Author: LedoCool
 * 
 * Created on August 19, 2018, 6:40 PM
 */

#include "WindowManager.h"

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}

int WindowManager::CreateWindow(const char* title, const unsigned int x, const unsigned int y, const unsigned int height, const unsigned int width)
{
    _windows.push_back(std::shared_ptr<Window>(new Window(title, x, y, height, width)));
}

int WindowManager::DestroyAllWindows()
{

}
