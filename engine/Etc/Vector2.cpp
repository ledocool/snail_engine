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
 * File:   Vector2.cpp
 * Author: LedoCool
 * 
 * Created on December 25, 2018, 11:38 PM
 */

#include "Vector2.h"

template<typename T>
Vector2<T>::Vector2()
{
    _data[0] = 0;
    _data[1] = 0;
}

template<typename T>
Vector2<T>::Vector2(const T x, const T y)
{
    _data[0] = x;
    _data[1] = y;
}

template<typename T>
Vector2<T>::Vector2(const Vector2<T>& orig)
{
    this->_data[0] = orig->_data[0];
    this->_data[1] = orig->_data[1];
}

template<typename T>
Vector2<T> Vector2<T>::operator *=(T& mul)
{
    _data[0] *= mul;
    _data[1] *= mul;
    return this;
}

template<typename T>
Vector2<T> Vector2<T>::operator +=(const Vector2<T>& vec)
{
    _data[0] += vec->_data[0];
    _data[1] += vec->_data[1];
    return this;
}

template<typename T>
Vector2<T> Vector2<T>::operator =(const Vector2<T>& vec)
{
    _data[0] = vec->_data[0];
    _data[1] = vec->_data[1];
    return this;
}

template<typename T>
T & Vector2<T>::operator [](const unsigned int index)
{
    return _data[index];
}

template<typename T>
Vector2<T> & Vector2<T>::Normal()
{
    const T magnitude = Magnitude();
    const T noramlizationConstantX = x / magnitude, 
            noramlizationConstantY = y / magnitude;

    return Vector2(noramlizationConstantX, noramlizationConstantY);
}

template<typename T>
T Vector2<T>::Magnitude()
{
    return std::sqrt(_data[0]*_data[0] + _data[1]*_data[1]);
}

template<typename T>
T Vector2<T>::x()
{
    return _data[0];
}

template<typename T>
void Vector2<T>::x(const T val)
{
    _data[0] = val;
}

template<typename T>
T Vector2<T>::y()
{
    return _data[1];
}

template<typename T>
void Vector2<T>::y(const T val)
{
    _data[1] = val;
}

template<typename T>
void Vector2<T>::set(const T x, const T y)
{
    _data[0] = x;
    _data[1] = y;
}

template<typename T>
void Vector2<T>::get(T& x, T& y)
{
    x = _data[0];
    y = _data[1];
}
