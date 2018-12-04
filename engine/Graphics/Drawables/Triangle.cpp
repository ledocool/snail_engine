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
 * File:   Triangle.cpp
 * Author: LedoCool
 * 
 * Created on November 29, 2018, 3:13 PM
 */

#include "Triangle.h"
#include "includes.h"
#include "Graphics/ShaderManager.h"
#include "Etc/Singleton.h"

Triangle::Triangle(float shape[9], float coordinates[2], Color color)
{
    for(int i = 0; i < 9; i++)
    {
        _shape[i] = shape[i];
    }
    
    for(int i = 0; i < 2; i++)
    {
        _coordinates[i] = coordinates[i];
    }
    _color = color;
    
    
    glGenBuffers(1, &_glVBO_Id);
    glBindBuffer(GL_ARRAY_BUFFER, _glVBO_Id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_shape), _shape, GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &_glVAO_Id);
    glBindVertexArray(_glVAO_Id);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _glVAO_Id);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    

    auto shaderManager = Singleton<ShaderManager>::get();

    unsigned int vertexShader = shaderManager->CompileVertexShader(), 
            fragmentShader = shaderManager->CompileFragmentShader();
    
    //FRAGMENT;

    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, vertexShader);
    glAttachShader(_shaderProgram, fragmentShader);
    glLinkProgram(_shaderProgram);
    
    
    shaderManager->KillShader(vertexShader);
    shaderManager->KillShader(fragmentShader);
}

Triangle::Triangle(const Triangle & orig)
{
    //todo;
}

Triangle::~Triangle()
{
}

void Triangle::Draw()
{
    glUseProgram(_shaderProgram);
    glBindVertexArray(_glVAO_Id); 
    glDrawArrays(GL_TRIANGLES, 0, 3);;
}
