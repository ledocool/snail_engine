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
 * File:   Bullet.cpp
 * Author: LedoCool
 * 
 * Created on December 23, 2018, 12:13 AM
 */

#include "Bullet.h"
#include "engine/Ecs/Components/IncludeComponents.h"
#include "engine/Etc/Singleton.h"

Bullet::Bullet(const float size, const float coordinates[2], const float angle, const float velocity)
{
    addComponent(std::make_shared<Position> (coordinates[0], coordinates[1], angle));
    addComponent(std::make_shared<Size> (size));
    addComponent(std::make_shared<Velocity> (std::cos(angle) * velocity, std::sin(angle) * velocity, 0));
    
    float shape [18] = {
        -1.f, -0.5f, 0.f,
        0.2f, -0.5f, 0.f,
        1.f, -0.1f, 0.f,
        1.f, 0.1f, 0.f,
        0.2f, 0.5f, 0.f,
        -1.f, 0.5f, 0.f,
    };
    
    for(int i=0; i<18; i++)
    {
        _shape[i] = shape[i];
    }
    
    CreateOpenGlBinding(_shape, sizeof(_shape));
}

Bullet::~Bullet()
{
}

void Bullet::Draw(glm::mat4 projection)
{
    auto position = std::dynamic_pointer_cast<Position>(_components[ComponentTypes::POSITION]);
    auto size = std::dynamic_pointer_cast<Size>(_components[ComponentTypes::SIZE]);
    if(!(position && size))
    {
        return;
    }
    
    glm::mat4 trans = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    
    trans = glm::translate(trans, glm::vec3(position->x(), position->y(), 0));
    trans = glm::scale(trans, glm::vec3(size->size(), size->size(), 1.));  
    trans = glm::rotate(trans, position->angle(), glm::vec3(0.0, 0.0, 1.0));
    trans = projection * trans;
    
    glm::vec4 color(0.76, 0.12, 0.12, 1.);
    
    _shaderProgram->Use();
    _shaderProgram->PassData(trans, "transform");
    _shaderProgram->PassData(color, "color");
    
    glBindVertexArray(_glVAO_Id); 
    glDrawArrays(GL_LINE_LOOP, 0, 6);
}
