#pragma once
#include "EnemyState.h"
#include <cmath>

class OrbitState : public EnemyState {
private:
    Vector2 center;
    float radius;
    float angle = 0.0f;
    float speed;
    float duration;
    float timer = 0.0f;

public:
    OrbitState(Transform* _tr, Vector2 _center, float _radius, float _speed, float _duration)
        : EnemyState(_tr), center(_center), radius(_radius), speed(_speed), duration(_duration) {
    }

    void Update() override {
        timer += 0.016f; 
        angle += speed * 0.016f;

        tr->position.x = center.x + cos(angle) * radius;
        tr->position.y = center.y + sin(angle) * radius;

        if (timer >= duration) {
            Finish();
        }
    }
};