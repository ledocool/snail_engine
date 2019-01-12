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
 * File:   CheckCollisions.cpp
 * Author: LedoCool
 * 
 * Created on December 24, 2018, 8:35 PM
 */

#include "CheckCollisionsSystem.h"
#include "engine/Etc/Rect.h"
#include "engine/Etc/Vector2.h"
#include "engine/Game/Camera.h"
#include "engine/Ecs/Components/IncludeComponents.h"

CheckCollisionsSystem::CheckCollisionsSystem()
{
}

CheckCollisionsSystem::~ CheckCollisionsSystem()
{
}

void CheckCollisionsSystem::Execute(Uint32 dt, std::shared_ptr<GameState>& gameState)
{
    return;
    gameState->collidingEntitites.clear();
    BuildBinaryTree(gameState);
    for(auto entity : gameState->map->GetEntities())
    {
//        std::shared_ptr<Entity> entity = weakEntity.lock();
//        if(!entity)
//        {
//            continue;
//        }
        
        auto position = std::dynamic_pointer_cast<Position>(entity->GetComponent(ComponentTypes::POSITION).lock());
        auto velocity = std::dynamic_pointer_cast<Velocity>(entity->GetComponent(ComponentTypes::VELOCITY).lock());
        auto acceleration = std::dynamic_pointer_cast<Acceleration>(entity->GetComponent(ComponentTypes::ACCELERATION).lock());
        auto size = std::dynamic_pointer_cast<Size>(entity->GetComponent(ComponentTypes::SIZE).lock());
        
        if(!acceleration)
        {
            acceleration = std::make_shared<Acceleration>(Vector2<float>(0.f, 0.f), 0.f);
        }
        if(!velocity)
        {
            velocity = std::make_shared<Velocity>(Vector2<float>(0.f, 0.f), 0.f);
        }        
        if(!(position && size))
        {
            continue;
        }
        
        float halfSize = size->size() / 2.f;
        
        Rect<float> boundingRect(
            - halfSize,
            halfSize,
            - halfSize,
            halfSize
        );
        
        for(auto weakPossiblyCollidingEntity : gameState->collisionTree->GetObjects(boundingRect))
        {
            auto collider = weakPossiblyCollidingEntity.lock();
            if(!collider || collider->GetId() == entity->GetId())
            {
                continue;
            }
            
            auto colliderPosition = std::dynamic_pointer_cast<Position>(collider->GetComponent(ComponentTypes::POSITION).lock());
            auto colliderVelocity = std::dynamic_pointer_cast<Velocity>(collider->GetComponent(ComponentTypes::VELOCITY).lock());
            auto coliderAcceleration = std::dynamic_pointer_cast<Acceleration>(collider->GetComponent(ComponentTypes::ACCELERATION).lock());
            auto colliderSize = std::dynamic_pointer_cast<Size>(collider->GetComponent(ComponentTypes::SIZE).lock());

            if(!coliderAcceleration)
            {
                coliderAcceleration = std::make_shared<Acceleration>(Vector2<float>(0.f, 0.f), 0.f);
            }
            if(!colliderVelocity)
            {
                colliderVelocity = std::make_shared<Velocity>(Vector2<float>(0.f, 0.f), 0.f);
            }        
            if(!(colliderPosition && colliderSize))
            {
                continue;
            }
            float colliderHalfSize = colliderSize->size() / 2.f;
            Rect<float> colliderBoundingRect(
                - colliderHalfSize,
                colliderHalfSize,
                - colliderHalfSize,
                colliderHalfSize
            );
            
            for(Uint32 iTime = 0; iTime < dt; iTime++)
            {
                Vector2<float> entity1_position = position->coords();
                               entity1_position += velocity->velocity() * iTime;
                               entity1_position += acceleration->vector() * iTime * iTime / 2.f;
                Vector2<float> entity2_position = colliderPosition->coords();
                               entity2_position += colliderVelocity->velocity() * iTime; 
                               entity2_position += coliderAcceleration->vector() * iTime * iTime / 2.f;
                
                if(boundingRect.addPosition(entity1_position.x(), entity1_position.y()).CollidesWith(
                   colliderBoundingRect.addPosition(entity2_position.x(), entity2_position.y())))
                {
                    Vector2<float> diff = entity1_position - entity2_position;
                    if(diff.Magnitude() <= colliderSize->size() + size->size())
                    {
                        std::weak_ptr<Entity> leftEntity(entity);
                        std::pair<std::weak_ptr<Entity>, std::weak_ptr<Entity> > collidingPair(leftEntity, weakPossiblyCollidingEntity);
                        gameState->collidingEntitites.push_back(collidingPair);
                    }
                }
            }
        }
    }
}


void CheckCollisionsSystem::BuildBinaryTree(std::shared_ptr<GameState>& gameState)
{
    auto cameraCoordinates = gameState->camera->GetCoordinates();
    auto screenSize = gameState->camera->GetScreenProportions();
    
    Rect<float> chunk(
        cameraCoordinates.x() - screenSize.x(),
        cameraCoordinates.x() + screenSize.x(),
        cameraCoordinates.y() - screenSize.y(),
        cameraCoordinates.y() + screenSize.y()
    );
    
    gameState->collisionTree = std::make_shared<TreeRoot>();
    gameState->collisionTree->BuildTree(chunk, gameState->map->GetEntities());
}
