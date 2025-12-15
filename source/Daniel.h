#pragma once
#include "Enemy.h"

class Daniel : public Enemy
{
public:

	float speed = 20.0f;

	Daniel(Vector2 pos)
		: Enemy(pos, "resources/images/daniel.png", Vector2(1000.f, 1054.f))
		//	HorizontalMedusa()
		//: Enemy(Vector2(RM->WINDOW_WIDTH + 100, (rand() % (RM->WINDOW_HEIGHT - 200)) + 100), "resources/images/daniel.png", Vector2(1000.f, 1054.f))

		//VerticalMedusa()
		//: Enemy(Vector2(rand()% 1000 + 100, 100 ), "resources/images/daniel.png", Vector2(1000.f, 1054.f))
	{

	}

	//Su spawner decide dónde aparece
	//¿Cómo hacer state?
	
	void MoveRight() {

		_transform->position.x += speed / 2000;
	}

	void MoveDown() {

		_transform->position.y += speed / 2000;
	}

	void MoveUp() {

		_transform->position.y -= speed / 2000;
	}

	void Update() {
	
		MoveRight();

		Enemy::Update();

	}
};
