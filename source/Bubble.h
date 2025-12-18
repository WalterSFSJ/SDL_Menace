#pragma once
#include "Enemy.h"

class Bubble : public Enemy
{
public:

	float speed = 20.0f;
	bool rotate = false;
	bool leave = false;
	Bubble(Vector2 pos)
		: Enemy(pos, "resources/images/daniel.png", Vector2(1000.f, 1054.f))		
	{

	}

	void GoForward() {
	
		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) / 100;
		_transform->position.y += sin(rad) / 100;
	}

	void Rotate() {
	
		_transform->rotation += 0.01f;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) / 40;
		_transform->position.y += sin(rad) / 40;

		if (_transform->rotation > 300)
		{
			leave = true;
		}
	}

	
	void BubbleMoveLeft() {

		_transform->position.x -= 0.01f;
	}

	void Update() {
	
		if (_transform->position.x > RM->WINDOW_WIDTH / 3 && rotate == false)
		{
			BubbleMoveLeft();
		}
		else if (leave == false)
		{
			rotate = true;
			Rotate();
		}
		else if (leave == true)
		{
			GoForward();
		}

		Enemy::Update();

	}
};
