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
 * File:   Triangle.h
 * Author: LedoCool
 *
 * Created on November 29, 2018, 3:13 PM
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Graphics/Color.h"
#include "IDrawable.h"

class Triangle : IDrawable
{
public:
    Triangle(float shape[9], float coordinates[2],  Color color);
    Triangle(const Triangle & orig);
    
    void Draw() override;
    virtual ~Triangle();
    
private:
    Color _color = Color(0, 0, 0, 0);
    float _shape[9];
    float _coordinates[2];
    unsigned int _glVBO_Id, _glVAO_Id;
    
    unsigned int _shaderProgram;
};

#endif /* RECTANGLE_H */

