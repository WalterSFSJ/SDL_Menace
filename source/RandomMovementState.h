#pragma once
#include "EnemyState.h"
#include "TimeManager.h"
#define MAX 101
#define HALF 50
class RandomMovementState : public EnemyState
{
private:
	float time;
	float pauseTime = 1.5f;
	float maxTime = 2.5f;
	bool isFinished;

	float speedY;
	
	Vector2 direction;

	Transform* _t;
public:
	
	
	
	RandomMovementState(Transform* t, float f)
		: EnemyState(t)
	{
		time = 0.0f;
		isFinished = false;

		speedY = f;

		_t = t;
	}

	

	virtual void Update() override {
	
		time += TIME.GetDeltaTime();

		
		if (time < pauseTime)
		{
			_t->position.x += direction.x;
			_t->position.y += direction.y;
		}
		
		if (time >= maxTime) {
			time = 0.0f;
			float percentX = rand() % MAX - HALF;
			float percentY = rand() % MAX - HALF;

			float norm = sqrt(percentX * percentX + percentY * percentY);

			direction = Vector2((percentX / norm) * speedY, (percentY / norm) * speedY);
		}
		
	}
	
};
