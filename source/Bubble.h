#pragma once
#include "Enemy.h"

class Bubble : public Enemy
{
public:

	
	bool rotate = false;
	bool leave = false;
	Bubble(Vector2 pos)
		: Enemy(pos, "resources/images/bubble.png", Vector2(1000.f, 1054.f))		
	{
		speed = 6.0f;
	}

	void GoForward() {
	
		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) * speed;
		_transform->position.y += sin(rad) * speed;
	}

	void Rotate() {
	
		_transform->rotation += 1.0f;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) * speed;
		_transform->position.y += sin(rad) * speed;

		if (_transform->rotation > 300)
		{
			leave = true;
		}
	}

	
	void BubbleMoveLeft() {

		_transform->position.x -= speed;
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
