#pragma once
#include "Enemy.h"

class KillerWhale : public Enemy
{
public:

	float speed = 20.0f;
	int upDown = 1;
	bool down = false;
	bool up = false;
	KillerWhale(Vector2 pos)
		: Enemy(pos, "resources/images/daniel.png", Vector2(1000.f, 1054.f))
	{
	}

	void WaitForShip() {
	
		_transform->position.x -= 0.01f;

	}

	void MoveInWave() {

		if (_transform->rotation > 75)
		{
			upDown = -1;
		}
		else if (_transform->rotation < -75)
		{
			upDown = 1;
		}
	
		_transform->rotation += upDown;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) / 4 * 10;
		_transform->position.y += sin(rad) * 10;
	}

	
	void Update() {
	
		//if (_transform->position.x < ShipPos)
			//WaitForShip();

		MoveInWave();

		Enemy::Update();

	}
};
