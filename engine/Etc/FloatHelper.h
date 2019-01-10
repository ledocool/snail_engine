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
 * File:   FloatHelper.h
 * Author: LedoCool
 *
 * Created on December 23, 2018, 4:59 PM
 */

#ifndef FLOATHELPER_H
#define FLOATHELPER_H

#define FLOAT_PRESCISION (1e-7)
#define DOUBLE_PRESCISION (1e-15)

class FloatHelper
{
public:
    static bool IsNull(const float var);
    static bool IsNull(const double var);
    static bool IsNull(const unsigned int var);
    static bool IsNull(const int var);
};

#endif /* FLOATHELPER_H */

