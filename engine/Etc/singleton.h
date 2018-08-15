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
 * File:   singleton.h
 * Author: LedoCool
 *
 * Created on August 15, 2018, 10:30 PM
 */

#ifndef SINGLETON_H
#define SINGLETON_H

template <template T> class Singleton
{
public:
    Singleton();
    virtual ~Singleton();

    static T* get()
    {
        static T theSingleInstance;
        return &theSingleInstance;
    }

private:

    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);
};

#endif /* SINGLETON_H */

