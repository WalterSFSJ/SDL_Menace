#pragma once
#include "Enemy.h"
#include "TimeManager.h"
#include "LinearMovementState.h"
#include "GoRightState.h"
#include "InstantRotationState.h"

#define MAX 101
#define HALF 50


class Amoeba : public Enemy
{
public:

	float rotation;
	float maxRotation;

	bool returning = false;
	bool looping = false;
	bool gettingAway = false;
	bool regrouping = false;

	float time;
	float maxTime;
	
	Amoeba(int i)
		: Enemy(Vector2(300, 300), "resources/images/amoeba.png", Vector2(96.0f, 96.0f))
	{
		_transform->scale = Vector2(1.0f, 1.0f);
		
		speed = 4.5f;

		_transform->rotation = i * 45.0f;
		maxRotation = 360 * 2 + _transform->rotation;

		time = 0.0f;
		maxTime = 1.3f;

		esm->AddState(new LinearMovementState(speed, _transform->position, Vector2(RM->WINDOW_WIDTH / 2, _transform->position.y), _transform));
		esm->AddState(new GoRightState(speed, _transform, 1.5f));
		esm->AddState(new InstantRotationState(_transform, 90.0f));
		esm->AddState(new Rotate(_transform, maxRotation, 0.3f * speed,  speed));
		esm->AddState(new InstantRotationState(_transform, 90.0f));
		esm->AddState(new GoRightState(speed, _transform, 1.5f));
		esm->AddState(new LinearMovementState(speed, _transform->position, Vector2(-500.0f, _transform->position.y), _transform));
	}


};
