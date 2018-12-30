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
 * File:   Rect.h
 * Author: LedoCool
 *
 * Created on December 30, 2018, 11:29 PM
 */

#ifndef RECT_H
#define RECT_H

template <typename Type>
struct Rect {
    Rect()
    {
        left = 0;
        right = 0;
        top = 0;
        bottom = 0;
    }
    
    Rect(Type l, Type r, Type b, Type t)
    {
        left = l;
        right = r;
        top = t;
        bottom = b;
    }
    
    Type left, right, top, bottom;
};

#endif /* RECT_H */

