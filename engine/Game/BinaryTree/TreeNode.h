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
 * File:   TreeNode.h
 * Author: LedoCool
 *
 * Created on December 24, 2018, 8:39 PM
 */

#ifndef TREENODE_H
#define TREENODE_H

#include "engine/Ecs/Entity.h"
#include "engine/Ecs/Components/IncludeComponents.h"

class TreeNode
{
public:
    TreeNode(float left, float right, float top, float bottom, std::vector<std::weak_ptr< Entity > > & entities, TreeNode * parent, bool horizontal);
    virtual ~TreeNode();
    
    std::vector < std::weak_ptr <Entity> > GetEntities();
    bool PointInBounds(float x, float y);
    bool RectIntersects(float left, float right, float bottom, float top);
    bool RectInside(float left, float right, float bottom, float top);
    
    std::vector < std::weak_ptr <Entity> > GetBelongingEntities(float x, float y);
    std::vector < std::weak_ptr <Entity> > GetBelongingEntities(float left, float right, float bottom, float top);
    
private:

    std::vector < std::weak_ptr <Entity> > _belongingEntitites;    
    TreeNode * _leftLeaf; 
    TreeNode * _rightLeaf;
    TreeNode * _parent;
    
    float _left, _right, _top, _bottom;
};

#endif /* TREENODE_H */

