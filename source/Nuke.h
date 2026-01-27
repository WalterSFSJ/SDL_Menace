#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"

class Nuke : public Enemy
{
public:

	float moveY = 2.0f;

	Nuke()
		: Enemy(Vector2(rand() % 1000 + 100, RM->WINDOW_HEIGHT), "resources/images/up.png", Vector2(1000.f, 1054.f))
	{
		score = 50;
		esm->AddState(new LinearMovementState(moveY, _transform->position, Vector2(_transform->position.x, -500.0f), _transform));
	}

};
