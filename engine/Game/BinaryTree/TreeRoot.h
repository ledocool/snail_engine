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
 * File:   TreeRoot.h
 * Author: LedoCool
 *
 * Created on December 24, 2018, 8:39 PM
 */

#ifndef TREEROOT_H
#define TREEROOT_H

#include "TreeNode.h"

class TreeRoot
{
public:
    TreeRoot();
    virtual ~TreeRoot();
    void BuildTree(float left, float right, float bottom, float top, std::vector< std::weak_ptr<Entity> > entities);
    std::vector< std::weak_ptr <Entity> > GetObjects(float x, float y);
    std::vector< std::weak_ptr <Entity> > GetObjects(float left, float right, float bottom, float top);
    
private:
     std::shared_ptr<TreeNode> _root;   
};

#endif /* TREEROOT_H */

