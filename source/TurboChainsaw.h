#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"
#include "OrbitState.h"
#include "Idle.h"

class TurboChainsaw : public Enemy {
public:
    TurboChainsaw(Vector2 spawnPos, float orbitDuration, float time)
        : Enemy(spawnPos, "resources/images/chainsaw.png", Vector2(512.f, 512.f))
    {
        score = 300;
        speed = 4.0f;
        Vector2 targetCenter = Vector2(RM->WINDOW_WIDTH / 2.0f + 100.0f, RM->WINDOW_HEIGHT / 2.0f);

        esm->AddState(new Idle(_transform, time));

        esm->AddState(new LinearMovementState(speed, spawnPos, targetCenter, _transform));

        esm->AddState(new OrbitState(_transform, Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f), 100.0f, speed, orbitDuration));

        esm->AddState(new LinearMovementState(speed, targetCenter, spawnPos, _transform));
    }
};