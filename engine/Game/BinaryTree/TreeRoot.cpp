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
 * File:   TreeRoot.cpp
 * Author: LedoCool
 * 
 * Created on December 24, 2018, 8:39 PM
 */

#include "TreeRoot.h"

TreeRoot::TreeRoot()
{
    _root = nullptr;
}

void TreeRoot::BuildTree(Rect<float> rect, std::vector< std::weak_ptr<Entity> > entities)
{
    _root = std::make_shared<TreeNode>(rect, entities, nullptr, true, 0);
}

void TreeRoot::BuildTree(Rect<float> rect, const std::vector< std::shared_ptr<Entity> > & entities)
{
    std::vector< std::weak_ptr<Entity> > weakEntities;
    weakEntities.reserve(entities.size());
    for(auto entity : entities)
    {
        weakEntities.push_back(entity);
    }
    
    BuildTree(rect, weakEntities);
}

std::vector< std::weak_ptr <Entity> > TreeRoot::GetObjects(Vector2<float> & pos)
{
    return _root->GetBelongingEntities(pos);
}

std::vector< std::weak_ptr <Entity> > TreeRoot::GetObjects(Rect<float> & rect)
{
    return _root->GetBelongingEntities(rect);
}

TreeRoot::~ TreeRoot()
{
}

