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
 * File:   Entity.h
 * Author: LedoCool
 *
 * Created on December 4, 2018, 8:32 PM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "engine/includes.h"
#include "Component.h"

class Entity
{
public:
    virtual ~Entity();;
    std::vector< std::weak_ptr<Component> > GetComponents();
    std::weak_ptr<Component> GetComponent(unsigned int id);    
    unsigned int GetId();
    
protected:
    void addComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    std::map< unsigned int, std::shared_ptr<Component> > _components;
    
    Entity();
    
private:
    unsigned int _id;
};

#endif /* ENTITY_H */

