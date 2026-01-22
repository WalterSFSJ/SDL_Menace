#pragma once
#include "Enemy.h"
#include "TimeManager.h"
#include "LinearMovementState.h"
#include "Idle.h"
class VerticalMedusa : public Enemy
{
public:

	float moveY = 2.0f;
	int timeMove = 3; 
	float timePause = 3.0f; 
	float moveTimer = 0; 
    bool isMoving = true;
	
	VerticalMedusa()
		: Enemy(Vector2(rand()% 1000 + 100, RM->WINDOW_HEIGHT), "resources/images/up.png", Vector2(1000.f, 1054.f))
	{
		score = 50;		
		esm->AddState(new LinearMovementState(moveY, _transform->position, Vector2(_transform->position.x, _transform->position.y -150.0f), _transform));
		esm->AddState(new Idle(_transform, 1.0f));
		esm->AddState(new LinearMovementState(moveY, _transform->position, Vector2(_transform->position.x, _transform->position.y - 300.0f), _transform));
		esm->AddState(new Idle(_transform, 1.0f));
		esm->AddState(new LinearMovementState(moveY, _transform->position, Vector2(_transform->position.x, _transform->position.y - 450.0f), _transform));
		esm->AddState(new Idle(_transform, 1.0f));
		esm->AddState(new LinearMovementState(moveY, _transform->position, Vector2(_transform->position.x, _transform->position.y - 600.0f), _transform));
		esm->AddState(new Idle(_transform, 1.0f));
		esm->AddState(new LinearMovementState(moveY, _transform->position, Vector2(_transform->position.x, _transform->position.y - 750.0f), _transform));
		esm->AddState(new Idle(_transform, 1.0f));
		esm->AddState(new LinearMovementState(moveY, _transform->position, Vector2(_transform->position.x, _transform->position.y - 900.0f), _transform));
		esm->AddState(new Idle(_transform, 1.0f));
		esm->AddState(new LinearMovementState(moveY, _transform->position, Vector2(_transform->position.x, _transform->position.y - 1500.0f), _transform));
	}
};
