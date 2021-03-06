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
 * File:   InputEvent.h
 * Author: LedoCool
 *
 * Created on December 12, 2018, 8:56 PM
 */

#ifndef INPUTEVENT_H
#define INPUTEVENT_H

#include "engine/includes.h"
#include "Event.h"
#include "EventTypes.h"
#include "engine/Input/PlayerActions.h"

class InputEvent : public Event
{
public:
    InputEvent(PlayerActions::en event);
    virtual ~InputEvent();
    
    virtual EventTypes::en GetEventType() override { return EventTypes::INPUT; }
    PlayerActions::en GetEvent();
    
private:
    PlayerActions::en _event;
};

#endif /* INPUTEVENT_H */

