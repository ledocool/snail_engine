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
 * File:   EntityIdGenerator.cpp
 * Author: LedoCool
 * 
 * Created on December 31, 2018, 12:03 AM
 */

#include "EntityIdGenerator.h"
#include <limits>

EntityIdGenerator::~ EntityIdGenerator()
{
    _lastId = 0;
    _maxId = std::numeric_limits<unsigned int>::max();
}

unsigned int EntityIdGenerator::GenerateId()
{
    if(_lastId == _maxId)
    {
        //todo: throw exception?
    }
    return _lastId++;
}
