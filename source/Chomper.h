#pragma once
#include "Enemy.h"
#include "TimeManager.h"

#define MAX 101
#define HALF 50
#define CUSHIONSPEED 5

class Chomper : public Enemy
{
public:

	
	Chomper(float f)
		: Enemy(Vector2(f, 300), "resources/images/chomper.png", Vector2(1238.f, 760.f))
	{
		_transform->scale = Vector2(1.0f, 1.0f);
		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
		speed = 5.0f;
	}

	void Rotate();

	void Update();
};
