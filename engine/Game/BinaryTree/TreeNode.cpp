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
 * File:   TreeNode.cpp
 * Author: LedoCool
 * 
 * Created on December 24, 2018, 8:39 PM
 */

#include "TreeNode.h"

#define MIN_NODE_SIZE (1)

TreeNode::TreeNode(float left, float right, float top, float bottom, std::vector<std::weak_ptr< Entity > > & entities, TreeNode * parent, bool horizontal)
{
    _left = left;
    _right = right;
    _top = top;
    _bottom = bottom;
    _parent = parent;
    
    _leftLeaf = NULL;
    _rightLeaf = NULL;
    
    for(std::weak_ptr< Entity > weakEntity : entities)
    {
        if(auto entity = weakEntity.lock())
        {
            bool belongs = false;
            
            
            if(auto position = std::dynamic_pointer_cast<Position>(entity->GetComponent(ComponentTypes::POSITION).lock()))
            {
                if(PointInBounds(position->x(), position->y()))
                {
                    belongs = true;
                }
                
                if(auto size = std::dynamic_pointer_cast<Size>(entity->GetComponent(ComponentTypes::SIZE).lock()))
                {
                    float halfSize = size->size() / 2.f;
                    if(RectIntersects(position->x() - halfSize, position->x() + halfSize, 
                                      position->y() - halfSize, position->y() + halfSize))
                    {
                        belongs = true;
                    }
                }
            }
            
            if(belongs)
            {
                _belongingEntitites.push_back(weakEntity);
            }
        }
    }
    
    float width = _right - _left, 
          height = _top - _bottom;
    
    if(_belongingEntitites.size() < 2)
    {
        return;
    }
    
    if(width <= MIN_NODE_SIZE || height <= MIN_NODE_SIZE)
    {
        return;
    }
    
    float halfWidth = width/2.f, 
        halfHeight = height/2.f;
    
    float newLeft_left = 0, newRight_left = 0, newTop_left = 0, newBottom_left = 0;
    float newLeft_right = 0, newRight_right = 0, newTop_right = 0, newBottom_right = 0;

    if(horizontal)
    {
        newLeft_left = _left;
        newLeft_right = newRight_left = _left + halfWidth;
        newRight_right = _right;
        newTop_left = newTop_right = _top;
        newBottom_left = newBottom_right = _bottom;
    }
    else
    {
        newTop_left = _top;
        newTop_right = newBottom_left = _top + halfHeight;
        newBottom_right = _bottom;
        newLeft_left = newLeft_right = _left;
        newRight_right = newRight_left = _right;
    }
    
    _leftLeaf = new TreeNode (newLeft_left, newRight_left, newTop_left, newBottom_left, _belongingEntitites, this, !horizontal);
    _rightLeaf = new TreeNode (newLeft_right, newRight_right, newTop_right, newBottom_right, _belongingEntitites, this, !horizontal);
}

TreeNode::~ TreeNode()
{
    delete _leftLeaf;
    delete _rightLeaf;
}

std::vector<std::weak_ptr<Entity> > TreeNode::GetBelongingEntities(float x, float y)
{
    if(!PointInBounds(x, y))
    {
        return std::vector<std::weak_ptr<Entity> >();
    }
    
    if(_leftLeaf && _leftLeaf->PointInBounds(x, y))
    {
        return _leftLeaf->GetBelongingEntities(x, y);
    }
    else if(_rightLeaf && _rightLeaf->PointInBounds(x, y))
    {
        return _rightLeaf->GetBelongingEntities(x, y);
    }
    
    return GetEntities();
}

std::vector<std::weak_ptr<Entity> > TreeNode::GetBelongingEntities(float left, float right, float bottom, float top)
{
    if(!RectIntersects(left, right, bottom, top))
    {
        return std::vector<std::weak_ptr<Entity> >();
    }
    
    if(_leftLeaf && _leftLeaf->RectInside(left, right, bottom, top))
    {
        return _leftLeaf->GetBelongingEntities(left, right, bottom, top);
    }
    else if(_rightLeaf && _rightLeaf->RectInside(left, right, bottom, top))
    {
        return _rightLeaf->GetBelongingEntities(left, right, bottom, top);
    }
    
    return GetEntities();
}


std::vector<std::weak_ptr<Entity> > TreeNode::GetEntities()
{
    return _belongingEntitites;
}

bool TreeNode::PointInBounds(float x, float y)
{
    return (_left <= x && x <= _right) && (_bottom <= y && y <= _top);
}

bool TreeNode::RectIntersects(float left, float right, float bottom, float top)
{
    return (left <= _right || right >= _left) && (bottom <= _top || top >= _bottom);
}

bool TreeNode::RectInside(float left, float right, float bottom, float top)
{
    return (_left <= left) && (right <= _right) && (_bottom <= bottom) && (top <= _top);
}

