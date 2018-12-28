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
 * File:   Vector2.h
 * Author: LedoCool
 *
 * Created on December 25, 2018, 11:38 PM
 */

#ifndef VECTOR2_H
#define VECTOR2_H

#include "includes.h"

template <typename T> class Vector2
{
public:
    Vector2();
    Vector2(const T x, const T y);
    Vector2(const Vector2& orig);
    virtual ~Vector2();

    Vector2<T> operator=(const Vector2 & vec);
    Vector2<T> operator+=(const Vector2 & vec);
    Vector2<T> operator*=(T & mul);
    T & operator[](const unsigned int index);

    T x();
    void x(const T val);
    T y();
    void y(const T val);
    void set(const T x, const T y);
    void get(T& x, T& y);

    Vector2 & Normal();
    T Magnitude();

private:
    T _data[2];
};

#endif /* VECTOR2_H */

