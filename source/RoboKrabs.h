#pragma once
#include "Enemy.h"
#include "JumpToShipState.h"

class RoboKrabs : public Enemy {
public:
    RoboKrabs(Vector2 spawnPos, Ship* player)
        : Enemy(spawnPos, "resources/images/robokrabs.png", Vector2(400.f, 400.f))
    {
        score = 250; 
        _transform->scale = Vector2(0.8f, 0.8f); 

        Vector2 finishLine = Vector2(-200.0f, spawnPos.y);
        float speed = 2.0f;

        esm->AddState(new LinearMovementState(speed, spawnPos, finishLine, _transform));
        esm->AddState(new JumpToShipState(_transform, player));
    }
};