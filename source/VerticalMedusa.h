#pragma once
#include <chrono>
#include "Enemy.h"

class HorizontalMedusa : public Enemy
{
public:

	float moveY = 10;
	const std::chrono::duration<float> moveDuration = std::chrono::seconds(3);
	std::chrono::steady_clock::time_point time;

	void RestartMovement() {
		time = std::chrono::steady_clock::now();
	}

	HorizontalMedusa()
		: Enemy(Vector2(RM->WINDOW_WIDTH + 100, (rand() % (RM->WINDOW_HEIGHT - 200)) + 100))
	{

		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
	}

	void MoveVertical(float deltaTime) {

		std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
		std::chrono::duration<float> crono = currentTime - time;

		if (crono < moveDuration)
		{
			_transform->position.y -= moveY;
		}
		
	}

	void Update(float deltaTime) {

		MoveVertical(deltaTime);

		Enemy::Update();

	}
};
