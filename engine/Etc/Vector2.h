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

#include "engine/includes.h"
#include "engine/Etc/FloatHelper.h"

template <typename T> 
class Vector2
{
public:
    Vector2()
    {
        _data[0] = 0;
        _data[1] = 0;
    }
    
    Vector2(const T & x, const T & y)
    {
        _data[0] = x;
        _data[1] = y;
    }
    Vector2(const Vector2& orig)
    {
        _data[0] = orig._data[0];
        _data[1] = orig._data[1];
    }
    virtual ~Vector2() {}

    Vector2<T> operator = (Vector2 vec)
    {
        _data[0] = vec._data[0];
        _data[1] = vec._data[1];
        return *this;
    }
    Vector2<T> operator += (Vector2 vec)
    {
        _data[0] += vec._data[0];
        _data[1] += vec._data[1];
        return *this;
    }
    Vector2<T> operator -= (Vector2 vec)
    {
        _data[0] -= vec[0];
        _data[1] -= vec[1];
        return *this;
    }
    
    Vector2<T> operator + (Vector2 & val) const
    {
        return Vector2<T>(_data[0] + val[0], _data[1] + val[1]);
    }
    
    Vector2<T> operator - (Vector2 & val) const
    {
        return Vector2<T>(_data[0] - val[0], _data[1] - val[1]);
    }
    
    template <typename K> Vector2<T> operator *= (K mul)
    {
        _data[0] *= mul;
        _data[1] *= mul;
        return *this;
    };
    
    template <typename K> Vector2<T> operator += (K mul)
    {
        _data[0] += mul;
        _data[1] += mul;
        return *this;
    }
    
    template <typename K> Vector2<T> operator -= (K mul)
    {
        _data[0] -= mul;
        _data[1] -= mul;
        return *this;
    }
    
    template <typename K> Vector2<T> operator /= (K mul)
    {
        _data[0] /= mul;
        _data[1] /= mul;
        return *this;
    }
    
    template <typename K> Vector2<T> operator * (K mul) const
    {
        return Vector2<T> (_data[0] * mul, _data[1] * mul);
    }
    
    template <typename K> Vector2<T> operator + (K val) const
    {
        return Vector2<T> (_data[0] + val, _data[1] + val);
    }
    
    template <typename K> Vector2<T> operator - (K val) const
    {
        return Vector2<T> (_data[0] - val, _data[1] - val);
    }
    
    template <typename K> Vector2<T> operator / (K val) const
    {
        return Vector2<T> (_data[0] / val, _data[1] / val);
    }
    
    T & operator[](const unsigned int index)
    {
        return _data[index];
    }

    T x()
    {
        return _data[0];
    }
    
    void x(const T val)
    {
        _data[0] = val;
    }

    T y()
    {
        return _data[1];
    }
    
    void y(const T val)
    {
        _data[1] = val;
    }
    
    void set(const T x, const T y)
    {
        _data[0] = x;
        _data[1] = y;
    }
    
    void get(T& x, T& y)
    {
        x = _data[0];
        y = _data[1];
    }

    bool IsNull()
    {
        return FloatHelper::IsNull(_data[0]) && FloatHelper::IsNull(_data[1]);
    }
    
    Vector2<T> Normal()
    {
        const T magnitude = Magnitude();
        const T noramlizationConstantX = _data[0] / magnitude, 
                noramlizationConstantY = _data[1] / magnitude;

        return Vector2<T>(noramlizationConstantX, noramlizationConstantY);
    }
    T Magnitude()
    {
        return std::sqrt(_data[0]*_data[0] + _data[1]*_data[1]);
    }

private:
    T _data[2];
};

#endif /* VECTOR2_H */

