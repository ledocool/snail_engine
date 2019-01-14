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
 * File:   Camera.cpp
 * Author: LedoCool
 * 
 * Created on December 5, 2018, 4:40 PM
 */

#include "Camera.h"

Camera::Camera()
{
    _pos.set(0, 0);
    _height = 0;
    _width = 0;
    _projectionMatrix = glm::mat4(1.f);
}

Camera::~Camera()
{
}

void Camera::GenerateProjectionMatrix()
{
    auto rect = GetScreenRect();    
    _projectionMatrix = glm::ortho(rect.left, rect.right, rect.bottom, rect.top, 0.f, 1.f);
}

glm::mat4 Camera::GetProjectionMatrix()
{
    return _projectionMatrix;
}

void Camera::LookAt(float x, float y, bool generateMatrix /* = true */)
{
    _pos.set(x, y);    
    if(generateMatrix)
    {
        GenerateProjectionMatrix();
    }
}

void Camera::LookAt(Vector2<float> coords, bool generateMatrix /* = true */)
{
    LookAt(coords.x(), coords.y(), generateMatrix);
}

void Camera::SetScreenProportions(unsigned int width, unsigned int height, bool generateMatrix /* = true */)
{
    _height = height;
    _width = width;
    
    if(generateMatrix)
    {
        GenerateProjectionMatrix();
    }
}

void Camera::SetScreenProportions(Vector2<unsigned int> size, bool generateMatrix /* = true */)
{
    SetScreenProportions(size.x(), size.y(), generateMatrix);
}

Vector2<float> Camera::GetCoordinates()
{
    return _pos;
}

Vector2<unsigned int> Camera::GetScreenProportions()
{
    return Vector2<unsigned int>(_width, _height);
}

float Camera::x()
{
    return _pos.x();
}

float Camera::y()
{
    return _pos.y();
}

Rect<float> Camera::GetScreenRect()
{
    unsigned int halfWidth = _width/2, 
            halfHeight = _height/2; 
    float   left = _pos.x() - halfWidth, 
            right = _pos.x() + halfWidth, 
            top = _pos.y() + halfHeight, 
            bottom = _pos.y() - halfHeight;
    
    return Rect<float>(left, right, bottom, top);
}
