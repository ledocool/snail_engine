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
 * File:   Asteroid.cpp
 * Author: LedoCool
 * 
 * Created on December 22, 2018, 4:36 PM
 */

#include "Asteroid.h"
#include "engine/Ecs/Components/IncludeComponents.h"
#include "engine/Etc/Singleton.h"


Asteroid::Asteroid(const float radius, const Vector2<float> & coordinates, const Vector2<float> & velocity)
{
    addComponent(std::make_shared<Position>(coordinates, 0.f));
    addComponent(std::make_shared<Velocity>(velocity, 0.f));
    addComponent(std::make_shared<Size>(radius));
    addComponent(std::make_shared<DespawnOutsideScreen>());
    
    float step = 2 * M_PI / 50;
    
    for(int i=0; i<50; i++)
    {
        float angle = step * i;
        float x = cos(angle);
        float y = sin(angle);
        
        _shape[i*3] = x;
        _shape[i*3 + 1] = y;
        _shape[i*3 + 2] = 0.0f;
    }
    
    CreateOpenGlBinding(_shape, sizeof(_shape));
}

Asteroid::~Asteroid()
{
}

void Asteroid::Draw(glm::mat4 projection)
{
    auto position = std::dynamic_pointer_cast<Position>(_components[ComponentTypes::POSITION]);
    auto size = std::dynamic_pointer_cast<Size>(_components[ComponentTypes::SIZE]);
    if(!(position && size))
    {
        return;
    }
    
    glm::mat4 trans = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    auto coordinates = position->coords();
    
    trans = glm::translate(trans, glm::vec3(coordinates.x(), coordinates.y(), 0));
    trans = glm::scale(trans, glm::vec3(size->size(), size->size(), 1.));  
    trans = glm::rotate(trans, position->angle(), glm::vec3(0.0, 0.0, 1.0));
    trans = projection * trans;
    
    glm::vec4 color(0.76, 0.12, 0.12, 1.);
    
    _shaderProgram->Use();
    _shaderProgram->PassData(trans, "transform");
    _shaderProgram->PassData(color, "color");
    
    glBindVertexArray(_glVAO_Id); 
    glDrawArrays(GL_LINE_LOOP, 0, 50);
}

