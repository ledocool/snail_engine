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
 * File:   ShaderProgram.h
 * Author: LedoCool
 *
 * Created on December 7, 2018, 2:33 PM
 */

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "engine/includes.h"
#include "Shader.h"

class ShaderProgram
{
public:
    ShaderProgram(std::string vertexShader, std::string fragmentShader);
    ~ShaderProgram();
    
    void Use();
    void PassData(glm::mat4 data, std::string parameterName);
    
private:
    unsigned int _programId;
};

#endif /* SHADERPROGRAM_H */

