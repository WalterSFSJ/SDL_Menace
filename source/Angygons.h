#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"

class Angrygons : public Enemy
{
public:

    float speed = 2.0f;
    float distance = 150.0f;

    Angrygons(Vector2 pos)
        : Enemy(pos, "resources/images/fist_0.png", Vector2(1000.f, 1054.f))
    {

        Vector2 p1 = Vector2(pos.x + distance, pos.y);            // Right
        Vector2 p2 = Vector2(p1.x, p1.y + distance);             // Down
        Vector2 p3 = Vector2(p2.x + distance, p2.y);             // Right
        Vector2 p4 = Vector2(p3.x, p3.y - distance);             // Up
        Vector2 p5 = Vector2(p4.x + distance, p4.y);            // Right
        Vector2 p6 = Vector2(p5.x, p5.y + distance);             // Down
        Vector2 p7 = Vector2(p6.x + distance, p6.y);             // Right
        Vector2 p8 = Vector2(p7.x, p7.y - distance);             // Up
        Vector2 p9 = Vector2(p8.x + distance, p8.y);            // Right
        Vector2 p10 = Vector2(p9.x, p9.y + distance);             // Down
        Vector2 p11 = Vector2(p10.x + distance, p10.y);             // Right
        Vector2 p12 = Vector2(p11.x, p11.y - distance);             // Up
        Vector2 p13 = Vector2(p12.x + distance, p12.y);            // Right
        Vector2 p14 = Vector2(p13.x, p13.y + distance);             // Down
        Vector2 p15 = Vector2(p14.x + distance, p14.y);             // Right
        Vector2 p16 = Vector2(p15.x, p15.y - distance);             // Up
        Vector2 p17 = Vector2(p16.x + distance, p16.y);            // Right
        Vector2 p18 = Vector2(p17.x, p17.y + distance);             // Down
        Vector2 p19 = Vector2(p18.x + 500.0f, p18.y);             // Right
        

        esm->AddState(new LinearMovementState(speed, pos, p1, _transform));
        esm->AddState(new LinearMovementState(speed, p1, p2, _transform));
        esm->AddState(new LinearMovementState(speed, p2, p3, _transform));
        esm->AddState(new LinearMovementState(speed, p3, p4, _transform));
        esm->AddState(new LinearMovementState(speed, p4, p5, _transform));
        esm->AddState(new LinearMovementState(speed, p5, p6, _transform));
        esm->AddState(new LinearMovementState(speed, p6, p7, _transform));
        esm->AddState(new LinearMovementState(speed, p7, p8, _transform));
        esm->AddState(new LinearMovementState(speed, p8, p9, _transform));
        esm->AddState(new LinearMovementState(speed, p9, p10, _transform));
        esm->AddState(new LinearMovementState(speed, p10, p11, _transform));
        esm->AddState(new LinearMovementState(speed, p11, p12, _transform));
        esm->AddState(new LinearMovementState(speed, p12, p13, _transform));
        esm->AddState(new LinearMovementState(speed, p13, p14, _transform));
        esm->AddState(new LinearMovementState(speed, p14, p15, _transform));
        esm->AddState(new LinearMovementState(speed, p15, p16, _transform));
        esm->AddState(new LinearMovementState(speed, p16, p17, _transform));
        esm->AddState(new LinearMovementState(speed, p17, p18, _transform));
        esm->AddState(new LinearMovementState(speed, p18, p19, _transform));        
    }

    void Update() {
        Enemy::Update();
    }
};