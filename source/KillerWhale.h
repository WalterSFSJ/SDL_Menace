#pragma once
#include "Enemy.h"
#include "WaveMovementState.h"
#include "LinearMovementState.h"
#include "Idle.h"

class KillerWhale : public Enemy
{
public:

	float speedY = 8.0f;
	int upDown = 1;
	bool go = false;

	KillerWhale(Vector2 pos, int i, float _time)
		: Enemy(pos, "resources/images/whale.png", Vector2(1000.f, 1054.f))
	{
		upDown = i;
		score = 150;
		esm->AddState(new Idle(_transform, _time));
		esm->AddState(new LinearMovementState(speedY, pos, Vector2(RM->WINDOW_WIDTH / 2, pos.y), _transform));
		esm->AddState(new WaveMovementState(_transform, i));		
	}	 
};
