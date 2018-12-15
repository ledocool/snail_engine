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
 * File:   EventPipeline.h
 * Author: LedoCool
 *
 * Created on December 11, 2018, 8:04 PM
 */

#ifndef EVENTPIPELINE_H
#define EVENTPIPELINE_H

#include "engine/includes.h"
#include "Event.h"
#include "EventTypes.h"
#include "engine/Etc/Singleton.h"

class EventPipeline
{
public:
    friend class Singleton<EventPipeline>;
    
    virtual ~EventPipeline();
    
    void RegisterEvent(Event * e);
    void PropagateEvents();
    void PushEventBatch();
    void PopEventBatch();
    std::vector<std::weak_ptr<Event>> GetAllEvents();
    template <class T> std::vector< std::weak_ptr<T> > GetEvents()
    {
        std::vector<std::weak_ptr<T>> handout;
        for(std::shared_ptr<Event> event : _events.front())
        {
            std::shared_ptr<T> casted = std::dynamic_pointer_cast<T>(event);
            if(casted)
            {
                handout.push_back( std::weak_ptr<T>(casted) );
            }
        }

        return handout;
    }
    
protected:
    EventPipeline();
    
private:
    std::deque<std::vector<std::shared_ptr<Event>>> _events;
};

#endif /* EVENTPIPELINE_H */

