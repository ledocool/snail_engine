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
 * File:   StateManager.cpp
 * Author: LedoCool
 * 
 * Created on August 15, 2018, 10:34 PM
 */

#include "StateManager.h"

StateManager::StateManager()
{
}

bool StateManager::render()
{
    if(stateStack.empty())
    {
        return false;
    }
    stateStack.top()->render();
    return true;
}

bool StateManager::process(Uint32 ms)
{
    if(stateStack.empty())
    {
        return false;
    }
    stateStack.top()->processLogic(ms);
    return true;
}

void StateManager::changeState(IState *st)
{
    class IState *delState;
    if( !stateStack.empty() )
    {
        stateStack.top()->exit();
        delState = stateStack.top();
        stateStack.pop();
        delete delState;
    }

    stateStack.push(st);
    stateStack.top()->enter();
}

void StateManager::pushState(IState *st)
{
    if( !stateStack.empty() )
        stateStack.top()->pause();

    stateStack.push(st);
    stateStack.top()->enter();
}

void StateManager::popState()
{
    IState *st;
    if( !stateStack.empty() )
    {
        stateStack.top()->exit();
        st = stateStack.top();
        stateStack.pop();
        delete st;
    }

    if( !stateStack.empty() )
        stateStack.top()->resume();
}

