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
 * File:   EventPipeline.cpp
 * Author: LedoCool
 * 
 * Created on December 11, 2018, 8:04 PM
 */

#include "EventPipeline.h"

EventPipeline::EventPipeline()
{
    PushEventBatch();
}

EventPipeline::~EventPipeline()
{
}

std::vector<std::weak_ptr<Event> > EventPipeline::GetAllEvents()
{
    std::vector<std::weak_ptr<Event>> handout;
    for(std::shared_ptr<Event> event : _events.front())
    {
        handout.push_back( std::weak_ptr<Event>(event) );
    }
    
    return handout;
}

void EventPipeline::PopEventBatch()
{
    _events.pop_front();
}

void EventPipeline::PropagateEvents()
{
    PopEventBatch();
    PushEventBatch();
}

void EventPipeline::PushEventBatch()
{
    _events.push_back(std::vector<std::shared_ptr<Event>>());
}

void EventPipeline::RegisterEvent(Event * e)
{
    _events.back().push_back(std::shared_ptr<Event>(e));
}

