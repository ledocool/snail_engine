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

Spaceship::Spaceship(Vector2<float> coordinates)
{          
    addComponent(std::make_shared<Player>());
    addComponent(std::make_shared<Position>(coordinates, 0));
    addComponent(std::make_shared<Size>(40));
    addComponent(std::make_shared<Velocity>(Vector2<float>(0, 0), 0));
    addComponent(std::make_shared<Acceleration>(Vector2<float>(0, 0), 0));
    addComponent(std::make_shared<Cannon>(120));
    addComponent(std::make_shared<ProjectileCollidable>());
    
    float shape [9] = {
        -0.5f, 0.5f, 0.0f,
        0.9f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };
    
    for(int i=0; i<9; i++)
    {
        _shape[i] = shape[i];
    }
    
    CreateOpenGlBinding(_shape, sizeof(_shape));
}

Spaceship::Spaceship(const Spaceship& orig)
{
    
}

Spaceship::~Spaceship()
{
}

void Spaceship::Draw(glm::mat4 projectionMatrix)
{
    auto position = std::dynamic_pointer_cast<Position>(_components[ComponentTypes::POSITION]);
    auto size = std::dynamic_pointer_cast<Size>(_components[ComponentTypes::SIZE]);
    if(!(position && size))
    {
        return;
    }
    
    glm::mat4 trans = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    auto coordinates = position->coords();
    
    trans = glm::translate(trans, glm::vec3(coordinates.x(), coordinates.y(), 0));
    trans = glm::scale(trans, glm::vec3(size->size(), size->size(), 1.));  
    trans = glm::rotate(trans, position->angle(), glm::vec3(0.0, 0.0, 1.0));
    trans = projectionMatrix * trans;
    
    glm::vec4 color(0.76, 0.12, 0.12, 1.);
    
    _shaderProgram->Use();
    _shaderProgram->PassData(trans, "transform");
    _shaderProgram->PassData(color, "color");
    
    glBindVertexArray(_glVAO_Id); 
    glDrawArrays(GL_TRIANGLES, 0, 3);;
}

