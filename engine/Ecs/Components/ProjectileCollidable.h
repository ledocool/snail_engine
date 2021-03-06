/*
 * Copyright 2019 LedoCool.
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
 * File:   ProjectileCollidable.h
 * Author: LedoCool
 *
 * Created on January 10, 2019, 8:49 PM
 */

#ifndef PROJECTILECOLLIDABLE_H
#define PROJECTILECOLLIDABLE_H

#include "engine/Ecs/Component.h"
#include "ComponentTypes.h"

class ProjectileCollidable : public Component
{
public:
    ProjectileCollidable();
    ProjectileCollidable(const ProjectileCollidable& orig);
    virtual ~ProjectileCollidable();
    unsigned int GetComponentId() override;
    
private:

};

#endif /* PROJECTILECOLLIDABLE_H */

