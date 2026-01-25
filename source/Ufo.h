#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"

class Ufo : public Enemy
{
public:
    float fastSpeed = 600.0f;

    Ufo(Vector2 pos)
        : Enemy(pos, "resources/images/ufo.png", Vector2(1000.f, 1054.f))
    {
        Vector2 spawnPos = pos;
        Vector2 screenCenter = Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f);

        esm->AddState(new LinearMovementState(fastSpeed, spawnPos, screenCenter, _transform));
        //idle
        esm->AddState(new LinearMovementState(fastSpeed, screenCenter, spawnPos, _transform));
    }

    void Update() {
        Enemy::Update();
    }
};