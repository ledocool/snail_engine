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
    _x = 0;
    _y = 0;
    _height = 0;
    _width = 0;
    _projectionMatrix = glm::mat4(1.f);
}

Camera::~Camera()
{
}

void Camera::GenerateProjectionMatrix()
{
    float halfHeight = _height/2.f, halfWidth = _width/2.f;
    float   left = _x - halfWidth, 
            right = _x + halfWidth, 
            top = _y + halfHeight, 
            bottom = _y - halfHeight;
    
    _projectionMatrix = glm::ortho(left, right, bottom, top, 0.f, 1.f);
}

glm::mat4 Camera::GetProjectionMatrix()
{
    return _projectionMatrix;
}

void Camera::LookAt(float x, float y, bool generateMatrix /* = true */)
{
    _x = x;
    _y = y;
    
    if(generateMatrix)
    {
        GenerateProjectionMatrix();
    }
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

void Camera::GetCoordinates(float& x, float& y)
{
    x = _x;
    y = _y;
}

void Camera::GetScreenProportions(unsigned int& width, unsigned int& height)
{
    height = _height;
    width = _width;
}

float Camera::x()
{
    return _x;
}

float Camera::y()
{
    return _y;
}

Rect<float> Camera::GetScreenRect()
{
    unsigned int halfWidth = _width/2, 
            halfHeight = _height/2; 
    float   left = _x - halfWidth, 
            right = _x + halfWidth, 
            top = _y + halfWidth, 
            bottom = _y - halfWidth;
    
    return Rect<float>(left, right, bottom, top);
}
