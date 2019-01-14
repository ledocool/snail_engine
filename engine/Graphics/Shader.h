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
 * File:   Shader.h
 * Author: LedoCool
 *
 * Created on December 6, 2018, 7:58 PM
 */

#ifndef SHADER_H
#define SHADER_H

#include "engine/includes.h"

namespace ShaderType 
{
    enum en
    {
        FRAGMENT,
        VERTEX
    };
};

class Shader
{
public:
    Shader(std::string shaderFilePath, ShaderType::en type);
    ~Shader();  
    
    unsigned int GetType() { return _shaderType; }
    unsigned int GetId() { return _shaderId; } 
    
private:
    unsigned int _shaderId;
    unsigned int _shaderType;
};

#endif /* SHADER_H */

