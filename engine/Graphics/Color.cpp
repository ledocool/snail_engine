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
 * File:   Color.cpp
 * Author: LedoCool
 * 
 * Created on November 29, 2018, 3:13 PM
 */

#include "Color.h"


Color::Color(float r, float g, float b, float a)
{   
    _r = inBounds(r) ? r : 1.f;
    _g = inBounds(g) ? g : 1.f;
    _b = inBounds(b) ? b : 1.f;
    _a = inBounds(a) ? a : 1.f;
}

bool Color::inBounds(float val)
{
    return val >= 0.f && val <= 1.f;
}
