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
 * File:   State.h
 * Author: LedoCool
 *
 * Created on August 14, 2018, 10:11 PM
 */

#ifndef ISTATE_H
#define ISTATE_H

#include "includes.h"

class IState
{
public:
    IState();
    virtual ~IState();
    friend class StateManager;

protected:
    virtual void render() = 0; //Render object
    virtual void processLogic(Uint32 elapsed) = 0;
    virtual void enter() = 0; //Enter a state;
    virtual void pause() = 0; //Pause a state;
    virtual void resume() = 0;
    virtual void exit() = 0;

    IState *getState()
    {
        return this;
    }
};

#endif /* ISTATE_H */

