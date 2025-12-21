#pragma once
#include "Enemy.h"
#include "TimeManager.h"

#define MAX 101
#define HALF 50
#define CUSHIONSPEED 5

class Amoeba : public Enemy
{
public:

	float rotation;
	float maxRotation;

	bool returning = false;
	bool looping = false;
	bool gettingAway = false;

	float time;
	float maxTime;
	
	Amoeba(int i)
		: Enemy(Vector2(300, 300), "resources/images/amoeba.png", Vector2(96.0f, 96.0f))
	{
		_transform->scale = Vector2(1.0f, 1.0f);
		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
		speed = 5.0f;

		_transform->rotation = i * 45.0f;
		maxRotation = 360 * 2 + _transform->rotation;

		time = 0.0f;
		maxTime = 1.3f;
	}

	void GoRight() {
	
		if (_transform->position.x < RM->WINDOW_WIDTH / 2) {
			 
			_transform->position.x += CUSHIONSPEED;
			return;		
		}
		
		gettingAway = true;		
	}

	void Loop() {

		_transform->rotation += 0.3f * CUSHIONSPEED;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) * CUSHIONSPEED;
		_transform->position.y += sin(rad) * CUSHIONSPEED;

		if (_transform->rotation > maxRotation)
		{
			returning = true;
		}

	}

	void GetAway() {

		if (time > maxTime) {

			looping = true;
			return;
		}

		time += TIME.GetDeltaTime();

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) * CUSHIONSPEED;
		_transform->position.y += sin(rad) * CUSHIONSPEED;
	}

	void Return() {

		_transform->position.x -= CUSHIONSPEED;
	}

	void Update() {

		if (returning)
			Return();
		else if (looping)
			Loop();
		else if (gettingAway)
			GetAway();
		else
			GoRight();


		Enemy::Update();
	}



};
