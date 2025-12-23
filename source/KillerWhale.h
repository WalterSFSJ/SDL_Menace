#pragma once
#include "Enemy.h"

class KillerWhale : public Enemy
{
public:

	float speedY = 8.0f;
	int upDown = 1;
	bool go = false;

	KillerWhale(Vector2 pos, int i)
		: Enemy(pos, "resources/images/whale.png", Vector2(1000.f, 1054.f))
	{
		upDown = i;
		score = 150;
	}

	void WaitForShip() {
	
		_transform->position.x -= speedY;

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
		_transform->position.y += sin(rad) * speedY;
	}

	
	void Update() {
	
		if (_transform->position.x > RM->WINDOW_WIDTH / 2 && go == false)
			WaitForShip();
		else {
			go = true;
			MoveInWave();
		}

		if (go == true)
		{
			if (_transform->position.x > RM->WINDOW_WIDTH)
				Destroy();
		}
		Enemy::Update();

	}
};
