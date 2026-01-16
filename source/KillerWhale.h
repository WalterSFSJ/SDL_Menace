#pragma once
#include "Enemy.h"
#include "WaveMovementState.h"
#include "LinearMovementState.h"
#include "Idle.h"

class KillerWhale : public Enemy
{
public:

	float speedY = 8.0f;
	int upDown = 1;
	bool go = false;

	KillerWhale(Vector2 pos, int i, float _time)
		: Enemy(pos, "resources/images/whale.png", Vector2(1000.f, 1054.f))
	{
		upDown = i;
		score = 150;
		esm.AddState(new Idle(_transform, _time));
		esm.AddState(new LinearMovementState(speedY, pos, Vector2(RM->WINDOW_WIDTH / 2, pos.y), _transform));
		esm.AddState(new WaveMovementState(_transform, i));		
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
	
		//execute behaviour
		esm.Update();
		/*if (_transform->position.x > RM->WINDOW_WIDTH / 2 && go == false)
			WaitForShip();
		else {
			go = true;
			MoveInWave();
		}

		if (go == true)
		{
			if (_transform->position.x > RM->WINDOW_WIDTH)
				Destroy();
		}*/
		Enemy::Update();

	}
};
