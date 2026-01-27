#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"
#include "Idle.h"
class Daniel : public Enemy
{
public:
    float speed = 3.0f;

    Daniel(Vector2 pos, float waitTime)
        : Enemy(pos, "resources/images/daniel.png", Vector2(1000.f, 1054.f))
    {
        Vector2 targetRight = Vector2(RM->WINDOW_WIDTH - 150.0f, _transform->position.y);
        Vector2 targetCenter = Vector2(targetRight.x, RM->WINDOW_HEIGHT / 2.0f);
        Vector2 targetLeft = Vector2(-300.0f, targetCenter.y);

        esm->AddState(new Idle(_transform, waitTime));
        esm->AddState(new LinearMovementState(speed, _transform->position, targetRight, _transform));
        esm->AddState(new LinearMovementState(speed, targetRight, targetCenter, _transform));
        esm->AddState(new LinearMovementState(speed, targetCenter, targetLeft, _transform));
    }

};