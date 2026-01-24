#pragma once
#include "Enemy.h"
#include "Idle.h"
#include "GoCirclingState.h"

#define MAX 101
#define HALF 50
#define CUSHIONSPEED 5

class Chomper : public Enemy
{
private:
	float time;
	float maxTime;
public:

	
	Chomper(float f)
		: Enemy(Vector2(RM->WINDOW_WIDTH - 40, f), "resources/images/chomper.png", Vector2(1238.f, 760.f))
	{
		_transform->scale = Vector2(1.0f, 1.0f);
		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
		speed = 5.0f;
		time = 0.0f;
		maxTime = 2.0f;


		esm->AddState(new Idle(_transform, 1.6f));
		esm->AddState(new GoCirclingState(_transform, speed));
	}



	
};
