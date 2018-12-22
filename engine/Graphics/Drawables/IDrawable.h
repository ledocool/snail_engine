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
 * File:   IDrawable.h
 * Author: LedoCool
 *
 * Created on November 29, 2018, 3:16 PM
 */

#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include "engine/includes.h"
#include "engine/Graphics/ShaderProgram.h"

class IDrawable
{
public:
    virtual void Draw(glm::mat4 projection)=0;
    
protected:
    std::shared_ptr<ShaderProgram> _shaderProgram;
    unsigned int _glVBO_Id, _glVAO_Id;
};

#endif /* IDRAWABLE_H */

