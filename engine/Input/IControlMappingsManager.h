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
 * File:   IControlMappingsManager.h
 * Author: LedoCool
 *
 * Created on July 15, 2018, 6:35 PM
 */

#ifndef ICONTROLMAPPINGSMANAGER_H
#define ICONTROLMAPPINGSMANAGER_H

#include "../filetypes.h"
#include "IKeystroke.h"

class IKeystroke;

/**
 * This one should be able to extract control mappings from previously generated file,
 * save them to file and keep/reveal info on all keystroke-event pairs
 */

class IControlMappingsManager 
{
public:
    /**
     * Loads config from specified file
     * @param file - file to be read
     */
    virtual void Load(std::string file)=0;
    
    /**
     * Saves config to specified file
     * @param file
     */
    virtual void Save(std::string file)=0;
    
    //todo: should return event;
    virtual void GetEventByKeystroke(IKeystroke key)=0;
};

#endif /* ICONTROLMAPPINGSMANAGER_H */

