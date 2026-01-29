#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"
#include "OrbitState.h"

class TurboChainsaw : public Enemy {
public:
    TurboChainsaw(Vector2 spawnPos, float orbitRadius, float orbitSpeed, float orbitDuration)
        : Enemy(spawnPos, "resources/images/bubble.png", Vector2(512.f, 512.f))
    {
        score = 300;
        speed = 1.0f;
        Vector2 targetCenter = Vector2(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f);

        esm->AddState(new LinearMovementState(speed, spawnPos, targetCenter, _transform));

        esm->AddState(new OrbitState(_transform, targetCenter, orbitRadius, orbitSpeed, orbitDuration));

        esm->AddState(new LinearMovementState(speed, targetCenter, spawnPos, _transform));
    }
};