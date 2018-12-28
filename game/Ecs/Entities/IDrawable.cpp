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

#include "IDrawable.h"

IDrawable::~ IDrawable()
{

}

IDrawable::IDrawable()
{
    _glVAO_Id = 0;
    _glVBO_Id = 0;
    CreateShaderProgram();
}

void IDrawable::CreateShaderProgram()
{
    _shaderProgram = std::make_shared<ShaderProgram> ("resources/Shaders/BasicVertexShader.glsl", "resources/Shaders/BasicFragmentShader.glsl");
}


void IDrawable::CreateOpenGlBinding(const void * shape, size_t sizeOfShape)
{
    glGenBuffers(1, &_glVBO_Id);
    glBindBuffer(GL_ARRAY_BUFFER, _glVBO_Id);
    glBufferData(GL_ARRAY_BUFFER, sizeOfShape, shape, GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &_glVAO_Id);
    glBindVertexArray(_glVAO_Id);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _glVAO_Id);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}
