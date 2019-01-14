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
 * File:   Shader.cpp
 * Author: LedoCool
 * 
 * Created on December 6, 2018, 7:58 PM
 */

#include "Shader.h"
#include <fstream>
#include <sstream>

Shader::Shader(std::string shaderFilePath, ShaderType::en type)
{
    _shaderType = type;
    _shaderId = 0;

    std::string shaderContents;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        shaderFile.open(shaderFilePath);
        std::stringstream buffer;
        buffer << shaderFile.rdbuf();
        shaderFile.close();
        shaderContents = buffer.str();
    }
    catch (std::ifstream::failure ex) {
        //todo: work errors
    }

    int success;
    char infoLog[512];

    _shaderId = glCreateShader(_shaderType == ShaderType::FRAGMENT ? GL_FRAGMENT_SHADER : GL_VERTEX_SHADER);
    const char * cString = shaderContents.c_str();
    glShaderSource(_shaderId, 1, &cString, NULL);
    glCompileShader(_shaderId);
    glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &success);

    std::string crashInfo;
    if (!success) {
        glGetShaderInfoLog(_shaderId, 512, NULL, infoLog);
        crashInfo = infoLog;
        std::cout << "Shader compile error: " << infoLog << std::endl;
    }
}

Shader::~Shader()
{
    glDeleteShader(_shaderId);
}

