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
 * File:   Event.h
 * Author: LedoCool
 *
 * Created on December 11, 2018, 8:05 PM
 */

#ifndef EVENT_H
#define EVENT_H

#include "EventTypes.h"

class Event
{
public: 
    virtual EventTypes::en GetEventType() { return EventTypes::UNDEFINED; }
};

#endif /* EVENT_H */

