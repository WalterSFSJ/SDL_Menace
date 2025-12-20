#pragma once
#include "Enemy.h"

class Circle : public Enemy
{
public:

	Circle(Vector2 pos)
		: Enemy(pos, "resources/images/daniel.png", Vector2(1000.f, 1054.f))
	{

	}

	void CircleMovement() {

		_transform->rotation += 0.01f;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) / 40;
		_transform->position.y += sin(rad) / 40;

	}

	void Update() {

		CircleMovement();

		Enemy::Update();

	}
};
