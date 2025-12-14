#pragma once
#include "Enemy.h"

class VerticalMedusa : public Enemy
{
public:

	float moveY = 0.5;

	VerticalMedusa()
		: Enemy(Vector2(rand()% 1000 + 100, 100 ))
	{

		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
	}

	void MoveVertical() {

			_transform->position.y -= moveY;
		
	}

	void Update() {

		MoveVertical();

		Enemy::Update();

	}
};
