#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"
#include "JumpToShipState.h"
#include "Idle.h"

class Annoyer : public Enemy
{
public:
    Annoyer(Vector2 pos, Transform* player, int i)
        : Enemy(pos, "resources/images/anoyer.png", Vector2(1000.f, 1054.f))
    {
        Vector2 insideScreenUp = Vector2(pos.x, pos.y+200); 
        Vector2 insideScreenDown = Vector2(pos.x, pos.y-200); 
        
        esm->AddState(new Idle(_transform, 1.0f));
        if (i>0)
        {
            esm->AddState(new LinearMovementState(2.0f, pos, insideScreenUp, _transform));
        }
        else {
            esm->AddState(new LinearMovementState(2.0f, pos, insideScreenDown, _transform));
        }
        esm->AddState(new Idle(_transform, 1.0f));
        esm->AddState(new JumpToShipState(_transform, player));
    }

    void Update() {
        Enemy::Update();
    }
};