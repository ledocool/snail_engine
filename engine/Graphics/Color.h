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
 * File:   Color.h
 * Author: LedoCool
 *
 * Created on November 29, 2018, 3:13 PM
 */

#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    Color(float r, float g, float b, float a);
    
private:
    bool inBounds(float val);
    
    float _r, _g, _b, _a;
};

#endif /* COLOR_H */

