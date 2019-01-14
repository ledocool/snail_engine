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
 * File:   ShaderProgram.cpp
 * Author: LedoCool
 * 
 * Created on December 7, 2018, 2:33 PM
 */

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string vertexShader, std::string fragmentShader)
{
    _programId = glCreateProgram();
    
    Shader vertex(vertexShader, ShaderType::VERTEX), 
            fragment(fragmentShader, ShaderType::FRAGMENT);
    
    glAttachShader(_programId, vertex.GetId());
    glAttachShader(_programId, fragment.GetId());
    glLinkProgram(_programId);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(_programId);
}

void ShaderProgram::Use()
{
    glUseProgram(_programId);
}

void ShaderProgram::PassData(glm::mat4 data, std::string parameterName)
{
    unsigned int location = glGetUniformLocation(_programId, parameterName.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(data));
}

void ShaderProgram::PassData(glm::vec4 data, std::string parameterName)
{
    unsigned int location = glGetUniformLocation(_programId, parameterName.c_str());
    glUniform4fv(location, 1, glm::value_ptr(data));
}

