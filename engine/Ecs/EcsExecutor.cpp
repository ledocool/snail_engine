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
 * File:   EcsExecutor.cpp
 * Author: LedoCool
 * 
 * Created on December 15, 2018, 8:35 PM
 */

#include "EcsExecutor.h"
#include "engine/Ecs/Systems/MovePlayerSystem.h"
#include "engine/Ecs/Systems/CollectInputSystem.h"
#include "engine/Ecs/Systems/SpawnBulletSystem.h"
#include "engine/Ecs/Systems/ApplyVelocitySystem.h"
#include "engine/Ecs/Systems/MoveCameraSystem.h"
#include "engine/Ecs/Systems/AsteroidSpawnSystem.h"
#include "engine/Ecs/Systems/DespawnEntitiesSystem.h"
#include "engine/Ecs/Systems/ApplyAccelerationSystem.h"
#include "engine/Ecs/Systems/CheckCollisionsSystem.h"
#include "engine/Ecs/Systems/BulletCollisionSystem.h"
#include "engine/Ecs/Systems/AsteroidCollisionSystem.h"

EcsExecutor::EcsExecutor()
{
    _systems.push_back(std::make_shared<CollectInputSystem>());
    _systems.push_back(std::make_shared<AsteroidSpawnSystem>());
    _systems.push_back(std::make_shared<CheckCollisionsSystem>());
    _systems.push_back(std::make_shared<MovePlayerSystem>());
    _systems.push_back(std::make_shared<ApplyAccelerationSystem>());
    _systems.push_back(std::make_shared<ApplyVelocitySystem>());
    _systems.push_back(std::make_shared<MoveCameraSystem>());
    _systems.push_back(std::make_shared<SpawnBulletSystem>());
    _systems.push_back(std::make_shared<DespawnEntitiesSystem>());
    _systems.push_back(std::make_shared<BulletCollisionSystem>());
    _systems.push_back(std::make_shared<AsteroidCollisionSystem>());
}

EcsExecutor::~EcsExecutor()
{
}

void EcsExecutor::ExecuteEcs(Uint32 dt, std::shared_ptr<GameState> & state)
{
    for(std::shared_ptr<System> system : _systems)
    {
        system->Execute(dt, state);
    }
}

