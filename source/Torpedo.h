#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"

class Torpedo : public Enemy
{
public:

	float absoluteX;

	Torpedo()
		:Enemy(Vector2(RM->WINDOW_WIDTH + 100, (rand() % (RM->WINDOW_HEIGHT - 200)) + 100), "resources/images/horizontal.png", Vector2(1000.f, 1054.f))
	{

		absoluteX = (float)(rand() % 41) + 10;
		score = 50;

		esm->AddState(new LinearMovementState(absoluteX / 4, _transform->position, Vector2(-250.0f, _transform->position.y), _transform));
	}


};
