#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"

class Angrygons : public Enemy
{
public:

    float speed = 200.0f;
    float distance = 150.0f;

    Angrygons(Vector2 pos)
        : Enemy(pos, "resources/images/angrygon.png", Vector2(1000.f, 1054.f))
    {

        Vector2 p1 = Vector2(pos.x + distance, pos.y);            // Right
        Vector2 p2 = Vector2(p1.x, p1.y + distance);             // Down
        Vector2 p3 = Vector2(p2.x + distance, p2.y);             // Right
        Vector2 p4 = Vector2(p3.x, p3.y - distance);             // Up

        esm->AddState(new LinearMovementState(speed, pos, p1, _transform));
        esm->AddState(new LinearMovementState(speed, p1, p2, _transform));
        esm->AddState(new LinearMovementState(speed, p2, p3, _transform));
        esm->AddState(new LinearMovementState(speed, p3, p4, _transform));
    }

    void Update() {
        Enemy::Update();
    }
};