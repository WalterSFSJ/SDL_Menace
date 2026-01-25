#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"
#include "JumpToShipState.h"

class Annoyer : public Enemy
{
public:
    Annoyer(Vector2 pos, Ship* player)
        : Enemy(pos, "resources/images/annoyer.png", Vector2(1000.f, 1054.f))
    {
        Vector2 insideScreen = Vector2(pos.x - 200.0f, pos.y); 

        esm->AddState(new LinearMovementState(150.0f, pos, insideScreen, _transform));
        //Idle
        esm->AddState(new JumpToShipState(_transform, player));
    }

    void Update() {
        Enemy::Update();
    }
};