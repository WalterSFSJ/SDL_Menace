#pragma once
#include "Enemy.h"
#include "TimeManager.h"


class Boss : public Enemy
{
public:


	
	Boss(std::string path, Vector2 picSize)
		: Enemy(Vector2(RM->WINDOW_WIDTH + 100, RM->WINDOW_HEIGHT / 2), path, picSize)
	{
	}


	

	void Update() {

		

		Enemy::Update();

	}
};
