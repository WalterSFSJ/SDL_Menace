#pragma once
#include "Enemy.h"
#include "LinearMovementState.h"
#include "Rotate.h"
#include "Idle.h"
#include "GoRightState.h"
class Bubble : public Enemy
{
public:


	Bubble(Vector2 pos)
		: Enemy(pos, "resources/images/bubble.png", Vector2(1000.f, 1054.f))		
	{
		speed = 6.0f;
		score = 100;

		esm->AddState(new Idle(_transform, 0.5f));
		esm->AddState(new LinearMovementState(speed, _transform->position, Vector2(RM->WINDOW_WIDTH / 3, _transform->position.y), _transform));
		esm->AddState(new Rotate(_transform));
		esm->AddState(new GoRightState(speed, _transform));
	}
	
};
