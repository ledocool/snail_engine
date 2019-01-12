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
 * File:   MovePlayerSystem.cpp
 * Author: LedoCool
 * 
 * Created on December 15, 2018, 3:54 PM
 */

#include "MovePlayerSystem.h"
#include "engine/Ecs/Components/IncludeComponents.h"
#include "engine/Events/InputEvent.h"
#include "engine/Input/PlayerActions.h"
#include "engine/Etc/FloatHelper.h"


#define PLAYER_MOVE_SPEED (3e-4)
#define PLAYER_ROTATION_SPEED (3e-4)
#define MAX_VELOCITY (1e-1)
#define MAX_ROTATION (0.007)
#define VELOCITY_BLEEDOUT (5e-5)
#define ROTATION_BLEEDOUT (5e-5)

MovePlayerSystem::MovePlayerSystem()
{
}

MovePlayerSystem::MovePlayerSystem(const MovePlayerSystem& orig)
{
}

MovePlayerSystem::~ MovePlayerSystem()
{
}

void MovePlayerSystem::Execute(Uint32 dt, std::shared_ptr<GameState> & gameState)
{
    auto entitites = gameState->map->GetEntities();
    for (std::weak_ptr<Entity> weakEntity : entitites)
    {
        std::shared_ptr<Entity> entity = weakEntity.lock();
        if(!entity)
        {
            continue;
        }
        
        auto player = entity->GetComponent(ComponentTypes::PLAYER).lock();
        auto velocity = std::dynamic_pointer_cast<Velocity>(entity->GetComponent(ComponentTypes::VELOCITY).lock());
        auto position = std::dynamic_pointer_cast<Position>(entity->GetComponent(ComponentTypes::POSITION).lock());
        auto acceleration = std::dynamic_pointer_cast<Acceleration>(entity->GetComponent(ComponentTypes::ACCELERATION).lock());
        if (! (player && velocity && position && acceleration))
        {
            continue;
        }

        float rotation = 0.f, accel = 0.f;
        
        for (InputEvent & inputEvent : gameState->inputActions)
        {
            switch (inputEvent.GetEvent()) {
            case PlayerActions::GO_FORWARD:
                accel += PLAYER_MOVE_SPEED;
                break;
            case PlayerActions::GO_BACKWARD:
                accel -= PLAYER_MOVE_SPEED;
                break;
            case PlayerActions::TURN_LEFT:
                rotation += PLAYER_ROTATION_SPEED;
                break;
            case PlayerActions::TURN_RIGHT:
                rotation -= PLAYER_ROTATION_SPEED;
                break;
            }
        }

        velocity->rotation(
            calculateRotation(dt, velocity->rotation(), rotation)
        );
        
        Vector2<float> accelVector(std::cos(position->angle()) * accel, std::sin(position->angle()) * accel);
        acceleration->vector(accelVector);
    }
}

float MovePlayerSystem::bleedSpeed(float oldValue, float bleedFactor)
{
    if(FloatHelper::IsNull(oldValue))
    {
        return 0.f;
    }
    if((bleedFactor > oldValue && oldValue > 0)
       || (-bleedFactor < oldValue && oldValue < 0))
    {
        return 0.f;
    }

    return oldValue > 0 ? oldValue - bleedFactor : oldValue + bleedFactor;
}

Vector2<float> MovePlayerSystem::bleedSpeed(Vector2<float> oldValue, Vector2<float> bleedFactor)
{
    for(int i=0; i<2; i++)
    {
        oldValue[i] = bleedSpeed(oldValue[i], bleedFactor[i]);
    }
    return oldValue;
}

float MovePlayerSystem::capSpeed(float speed, float cap)
{
    if (speed > cap)
    {
        speed = cap;
    }
    else if(speed < -cap)
    {
        speed = -cap;
    }
    
    return speed;
}

Vector2<float> MovePlayerSystem::capSpeed(Vector2<float> speed, float cap)
{
    for(int i=0; i<2; i++)
    {
        speed[i] = capSpeed(speed[i], cap);
    }    
    return speed;
}

float MovePlayerSystem::calculateRotation(Uint32 dt, float rotation, float addRotation)
{
    if (FloatHelper::IsNull(addRotation))
    {
        rotation = bleedSpeed(rotation, dt * ROTATION_BLEEDOUT);
    }
    else
    {
        rotation = rotation + addRotation * dt;
    }
    return capSpeed(rotation, MAX_ROTATION);
}

Vector2<float> MovePlayerSystem::calculateSpeed(Uint32 dt, Vector2<float> velocity, Vector2<float> acceleration)
{
        if (acceleration.IsNull())
        {
            Vector2<float> bleedFactor = velocity.Normal();
            bleedFactor *= (VELOCITY_BLEEDOUT * dt);
            return capSpeed(bleedSpeed(velocity, bleedFactor), MAX_VELOCITY);
        }
        else
        {
            acceleration *= dt;
            velocity += acceleration;
            return capSpeed(velocity, MAX_VELOCITY);         
        }
}

