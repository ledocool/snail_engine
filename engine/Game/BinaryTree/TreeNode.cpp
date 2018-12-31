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

TreeNode::TreeNode(Rect<float> rect, std::vector<std::weak_ptr< Entity > > & entities, TreeNode * parent, bool horizontal)
{
    _bounds = rect;
    
    _leftLeaf = NULL;
    _rightLeaf = NULL;
    
    for(std::weak_ptr< Entity > weakEntity : entities)
    {
        if(auto entity = weakEntity.lock())
        {
            bool belongs = false;
            
            
            if(auto position = std::dynamic_pointer_cast<Position>(entity->GetComponent(ComponentTypes::POSITION).lock()))
            {
                if(PointInBounds(position->coords()))
                {
                    belongs = true;
                }
                
                if(auto size = std::dynamic_pointer_cast<Size>(entity->GetComponent(ComponentTypes::SIZE).lock()))
                {
                    float halfSize = size->size() / 2.f;
                    auto coordinates = position->coords();
                    Rect<float> rect(coordinates.x() - halfSize, coordinates.x() + halfSize,
                                     coordinates.y() - halfSize, coordinates.y() + halfSize);
                    
                    if(RectIntersects(rect))
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
    
    float width = _bounds.right - _bounds.left, 
          height = _bounds.top - _bounds.bottom;
    
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
    Rect<float> newLeft, newRight;

    if(horizontal)
    {
        newLeft.left = _bounds.left;
        newRight.left = newLeft.right = _bounds.left + halfWidth;
        newRight.right = _bounds.right;
        newLeft.top = newRight.top = _bounds.top;
        newLeft.bottom = newRight.bottom = _bounds.bottom;
    }
    else
    {
        newLeft.top = _bounds.top;
        newRight.top = newLeft.bottom = _bounds.top + halfHeight;
        newRight.bottom = _bounds.bottom;
        newLeft.left = newRight.left = _bounds.left;
        newLeft.right = newRight.right = _bounds.right;
    }
    
    _leftLeaf = new TreeNode (newLeft, _belongingEntitites, this, !horizontal);
    _rightLeaf = new TreeNode (newRight, _belongingEntitites, this, !horizontal);
}

TreeNode::~ TreeNode()
{
    delete _leftLeaf;
    delete _rightLeaf;
}

std::vector<std::weak_ptr<Entity> > TreeNode::GetBelongingEntities(Vector2<float> & pos)
{
    if(!PointInBounds(pos))
    {
        return std::vector<std::weak_ptr<Entity> >();
    }
    
    if(_leftLeaf && _leftLeaf->PointInBounds(pos))
    {
        return _leftLeaf->GetBelongingEntities(pos);
    }
    else if(_rightLeaf && _rightLeaf->PointInBounds(pos))
    {
        return _rightLeaf->GetBelongingEntities(pos);
    }
    
    return GetEntities();
}

std::vector<std::weak_ptr<Entity> > TreeNode::GetBelongingEntities(Rect<float> & rect)
{
    if(!RectIntersects(rect))
    {
        return std::vector<std::weak_ptr<Entity> >();
    }
    
    if(_leftLeaf && _leftLeaf->RectInside(rect))
    {
        return _leftLeaf->GetBelongingEntities(rect);
    }
    else if(_rightLeaf && _rightLeaf->RectInside(rect))
    {
        return _rightLeaf->GetBelongingEntities(rect);
    }
    
    return GetEntities();
}


std::vector<std::weak_ptr<Entity> > TreeNode::GetEntities()
{
    return _belongingEntitites;
}

bool TreeNode::PointInBounds(Vector2<float> pos)
{
    return (_bounds.left <= pos.x() && pos.x() <= _bounds.right) 
            && (_bounds.bottom <= pos.y() && pos.y() <= _bounds.top);
}

bool TreeNode::RectIntersects(Rect<float> rect)
{
    return (rect.left <= _bounds.right || rect.right >= _bounds.left) 
            && (rect.bottom <= _bounds.top || rect.top >= _bounds.bottom);
}

bool TreeNode::RectInside(Rect<float> rect)
{
    return (_bounds.left <= rect.left) && (rect.right <= _bounds.right) 
            && (_bounds.bottom <= rect.bottom) && (rect.top <= _bounds.top);
}

