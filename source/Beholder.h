#pragma once
#include "Enemy.h"
#include "TimeManager.h"
#include "LinearMovementState.h"
#include "RandomMovementState.h"

#define MAX 101
#define HALF 50
#define CUSHIONSPEED 5

class Beholder : public Enemy
{
public:

	Vector2 direction = Vector2(0.5f * CUSHIONSPEED, 0.5f * CUSHIONSPEED);
	int timeMove = 2; 
	float timePause = 3.0f; 
	float moveTimer = 0; 
    bool isMoving = true;
	float speed = 6.0f;
	Beholder(float f)
		: Enemy(Vector2(f, RM->WINDOW_HEIGHT + 100), "resources/images/beholder.png", Vector2(1238.f, 760.f))
	{
		_transform->scale = Vector2(0.7f, 0.7f);
		
		score = 200;
		
		esm->AddState(new LinearMovementState(CUSHIONSPEED, _transform->position, Vector2(_transform->position.x, RM->WINDOW_HEIGHT / 2), _transform));
		esm->AddState(new RandomMovementState(_transform, speed));
	}
	
};
