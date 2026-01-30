#pragma once
#include "Enemy.h"
#include "JumpToShipState.h"

class RoboKrabs : public Enemy {
public:
    RoboKrabs(Vector2 spawnPos, Transform* player, float time)
        : Enemy(spawnPos, "resources/images/robokrabs.png", Vector2(512.f, 512.f))
    {
        score = 250; 
        _transform->scale = Vector2(0.8f, 0.8f); 

        Vector2 finishLine = Vector2(RM->WINDOW_WIDTH / 2, spawnPos.y);
        float speed = 2.0f;

        esm->AddState(new Idle(_transform, time));
        esm->AddState(new LinearMovementState(speed, spawnPos, finishLine, _transform));
        esm->AddState(new JumpToShipState(_transform, player));
    }
};