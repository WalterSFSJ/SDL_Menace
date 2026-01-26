#pragma once
#include "AnimatedImageObject.h"
#include "Vector2.h"
class ExplotionAnimation : public AnimatedImageObject
{
private:
    float time;

public:
    ExplotionAnimation(Vector2 pos)
        : AnimatedImageObject("resources/images/explosion.png", Vector2(0.0f, 0.0f), Vector2(256.0f, 256.0f), 16, 4, 64.0f, 64.0f, false)
    {
        _transform->position = pos;
        time = 0.0f;
    }

    void Update() override {
        time += TIME.GetDeltaTime();
        if (time > 0.5f)
            Destroy();

        Object::Update();
    }
};