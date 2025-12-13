#pragma once
#include "Enemy.h"

class HorizontalMedusa : public Enemy
{
public:

	float absoluteX;

	HorizontalMedusa()
		: Enemy()
	{
		srand(time(NULL));

		absoluteX = (float)(rand() % 41) + 10;
		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
	}

	//absolute value between 10 and 50 and can be positive or negative 	
	//puede aparecer en izquierda o derecha?
	//es demasiado rápido
	void MoveHorizontally() {

		_transform->position.x -= absoluteX / 2000;
	}

	void Update() {
	
		MoveHorizontally();

		Enemy::Update();

	}
};
