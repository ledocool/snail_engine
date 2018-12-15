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
 * File:   Entity.cpp
 * Author: LedoCool
 * 
 * Created on December 4, 2018, 8:32 PM
 */

#include "Entity.h"

void Entity::addComponent(std::shared_ptr<Component> component)
{
    if(component)
    {
        removeComponent(component);
        auto componentId = component->GetComponentId();
        _components.insert(std::make_pair(component->GetComponentId(), component)); 
    }
}

void Entity::removeComponent(std::shared_ptr<Component> component)
{
    if(component)
    {
        auto componentIterator = _components.find(component->GetComponentId());    
        if(componentIterator != _components.end())
        {
            _components.erase(componentIterator);
        }
    }
}

std::vector< std::weak_ptr<Component> > Entity::GetComponents()
{
    std::vector< std::weak_ptr<Component> > myComponents;
    for(auto component : _components)
    {
       myComponents.push_back( std::weak_ptr<Component>(component.second) );
    }
    
    return myComponents;
}

std::weak_ptr<Component> Entity::GetComponent(unsigned int id)
{
    std::weak_ptr<Component> ret;
    if(_components.at(id))
    {
        ret = _components[id];
    }
    
    return ret;
}

