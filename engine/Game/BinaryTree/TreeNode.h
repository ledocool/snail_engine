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
#include "engine/Etc/Vector2.h"
#include "engine/Etc/Rect.h"

class TreeNode
{
public:
    TreeNode(Rect<float> rect, std::vector<std::weak_ptr< Entity > > & entities, TreeNode * parent, bool horizontal);
    virtual ~TreeNode();
    
    std::vector < std::weak_ptr <Entity> > GetEntities();
    bool PointInBounds(Vector2<float> pos);
    bool RectIntersects(Rect<float> rect);
    bool RectInside(Rect<float> rect);
    
    std::vector < std::weak_ptr <Entity> > GetBelongingEntities(Vector2<float> & pos);
    std::vector < std::weak_ptr <Entity> > GetBelongingEntities(Rect<float> & rect);
    
private:

    std::vector < std::weak_ptr <Entity> > _belongingEntitites;    
    TreeNode * _leftLeaf; 
    TreeNode * _rightLeaf;
    TreeNode * _parent;
    
    Rect<float> _bounds;
};

#endif /* TREENODE_H */

