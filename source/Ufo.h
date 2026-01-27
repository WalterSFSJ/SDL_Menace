#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"
#include "Idle.h"

class Ufo : public Enemy
{
public:
    float fastSpeed = 6.0f;

    Ufo(Vector2 pos)
        : Enemy(pos, "resources/images/ufo.png", Vector2(1000.f, 1054.f))
    {
        Vector2 screenCenter = Vector2(RM->WINDOW_WIDTH / 2.0f, _transform->position.y);

        esm->AddState(new LinearMovementState(fastSpeed, _transform->position, screenCenter, _transform));
        esm->AddState(new Idle(_transform, 1.0f));
        esm->AddState(new LinearMovementState(fastSpeed, screenCenter, Vector2(RM->WINDOW_WIDTH + 500.0f, _transform->position.y), _transform));
    }

};