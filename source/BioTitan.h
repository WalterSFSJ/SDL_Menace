#pragma once
#include "Boss.h"
#include "TimeManager.h"
#include "Projectile.h"

#define MAX 101
#define HALF 50
#define CUSHIONSPEED 5

class Biotitan : public Boss
{
private:
	std::vector<Projectile*> allProjectiles;
	float shootingPause = 3.0f; 
	

public:
	
	
	
	Biotitan()
		: Biotitan::Boss("resources/images/biotitan.png", Vector2(450.0f, 450.0f))
		
	{
		_transform->scale = Vector2(2.7f, 2.7f);
		_transform->rotation += 90;
		score = 10000;
		SetHP(10);
	}

	void MoveLeft() {
	
		_transform->position.x -= 1;
	}

	void Shoot() {
	
		
	}

	void Update() {

		MoveLeft();

		Boss::Update();

	}
};
