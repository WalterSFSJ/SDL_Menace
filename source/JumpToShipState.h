#pragma once
#include "EnemyState.h"
#include "TimeManager.h"
#include "Ship.h"
#include <cmath>

class JumpToShipState : public EnemyState {
private:
    Ship* player;
    float timer = 0.0f;
    float jumpDuration = 1.0f; 
    float nextJump;

    bool jumping = false;
    float jumpTimer = 0.0f;
    Vector2 startPos;
    Vector2 targetPos;

public:
    JumpToShipState(Transform* t, Ship* p) : EnemyState(t), player(p) {
        SetRandomInterval();
    }

    void SetRandomInterval() {
        nextJump = 3.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2.0f));
    }

    virtual void Update() override {
        if (!jumping) {
            timer += TIME.GetDeltaTime();
            if (timer >= nextJump) {
                StartJump();
            }
        }
        else {
            ExecuteJump();
        }
    }

    void StartJump() {
        jumping = true;
        jumpTimer = 0.0f;
        startPos = tr->position;
        targetPos = player->GetTransform()->position;
    }

    void ExecuteJump() {
        jumpTimer += TIME.GetDeltaTime();
        float t = jumpTimer / jumpDuration;

        if (t >= 1.0f) {
            tr->position = targetPos;
            jumping = false;
            timer = 0.0f;
            SetRandomInterval();
        }
        else {
            tr->position.x = startPos.x + (targetPos.x - startPos.x) * t;
            tr->position.y = startPos.y + (targetPos.y - startPos.y) * t;

            float arc = sin(t * 3.14159f) * 100.0f;
            tr->position.y -= arc;
        }
    }
};