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
 * File:   ShaderManager.cpp
 * Author: LedoCool
 * 
 * Created on December 2, 2018, 4:51 PM
 */

#include "ShaderManager.h"

const char * vertexShaderSource = "#version 450 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char * fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
    "}\n\0";

ShaderManager::ShaderManager()
{
}

unsigned int ShaderManager::CompileFragmentShader()
{
    int  success;
    char infoLog[512];
    
    unsigned int shaderId;
    shaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shaderId, 1, &fragmentShaderSource, NULL);
    glCompileShader(shaderId);
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        //todo: log me
    }
    
    return shaderId;
}

unsigned int ShaderManager::CompileVertexShader()
{
    int  success;
    char infoLog[512];

    unsigned int shaderId;
    shaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shaderId, 1, &vertexShaderSource, NULL);
    glCompileShader(shaderId);
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        //todo: log me;
    }
    
    return shaderId;
}

void ShaderManager::KillShader(unsigned int shader)
{
     glDeleteShader(shader);
}
