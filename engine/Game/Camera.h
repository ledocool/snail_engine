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
 * File:   Camera.h
 * Author: LedoCool
 *
 * Created on December 5, 2018, 4:40 PM
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "engine/includes.h"
#include "engine/Etc/Rect.h"
#include "engine/Etc/Vector2.h"

class Camera
{
public:
    Camera();
    ~Camera();
    
    void SetScreenProportions(unsigned int width, unsigned int height, bool generateMatrix = true);
    void LookAt(float x, float y, bool generateMatrix = true);
    void SetScreenProportions(Vector2<unsigned int> size, bool generateMatrix = true);
    void LookAt(Vector2<float> coords, bool generateMatrix = true);

    Vector2<float> GetCoordinates();
    Vector2<unsigned int> GetScreenProportions();
    Rect<float> GetScreenRect();
    
    float x();
    float y();
    
    glm::mat4 GetProjectionMatrix();
    
private:
    void GenerateProjectionMatrix();
    
    Vector2<float> _pos;
    unsigned int _height, _width;
    glm::mat4 _projectionMatrix;    
};

#endif /* CAMERA_H */

