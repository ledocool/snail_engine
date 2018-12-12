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
 * File:   Spaceship.cpp
 * Author: LedoCool
 * 
 * Created on December 5, 2018, 2:50 PM
 */

#include "Spaceship.h"
#include "engine/Ecs/Components/IncludeComponents.h"
#include "engine/Etc/Singleton.h"

Spaceship::Spaceship(float shape[9], float coordinates[2])
{          
    addComponent(std::shared_ptr<Component>(new Position()));
    
    auto position = std::static_pointer_cast<Position>(_components[ComponentTypes::POSITION]);
    if(position)
    {
        position->x(coordinates[0]);
        position->y(coordinates[1]);
    }
    
    for(int i = 0; i < 9; i++)
    {
        _shape[i] = shape[i];
    }
    
    glGenBuffers(1, &_glVBO_Id);
    glBindBuffer(GL_ARRAY_BUFFER, _glVBO_Id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_shape), _shape, GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &_glVAO_Id);
    glBindVertexArray(_glVAO_Id);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _glVAO_Id);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    _shaderProgram = std::shared_ptr<ShaderProgram> (new ShaderProgram("resources/Shaders/BasicVertexShader.glsl", "resources/Shaders/BasicFragmentShader.glsl"));
}

Spaceship::Spaceship(const Spaceship& orig)
{
    
}

Spaceship::~Spaceship()
{
}

void Spaceship::Draw(glm::mat4 projectionMatrix)
{
    auto position = _components[ComponentTypes::POSITION];
    glm::mat4 trans = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    
    trans = glm::translate(trans, glm::vec3(0, 0, 0));
    trans = glm::scale(trans, glm::vec3(40., 40., 1.));  
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    
    trans = projectionMatrix * trans;
    
    _shaderProgram->Use();
    _shaderProgram->PassData(trans, "transform");
    
    glBindVertexArray(_glVAO_Id); 
    glDrawArrays(GL_TRIANGLES, 0, 3);;
}

