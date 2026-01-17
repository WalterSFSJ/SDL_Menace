#pragma once
#include "Boss.h"
#include "TimeManager.h"
#include "Projectile.h"



class Biotitan : public Boss
{
private:
	
	float shootingTime = 3.0f; 
	float currentTime = 0.0f;

public:
	
	
	
	Biotitan()
		: Boss("resources/images/biotitan.png", Vector2(450.0f, 450.0f))
		
	{
		_transform->scale = Vector2(2.7f, 2.7f);
		_transform->rotation += 90;
		score = 10000;
		SetHP(10);
		}

	void MoveLeft() {
	
		if (_transform->position.x > RM->WINDOW_WIDTH - 150)
		{
			_transform->position.x -= 1;
			return;
		}

		Shoot();
	}

	void Shoot();

	void Update() {

		MoveLeft();

		Boss::Update();
		
	}
};
