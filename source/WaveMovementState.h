#pragma once
#include "EnemyState.h"
#include "TimeManager.h"


class WaveMovementState : public EnemyState
{
private:
	float time;
	bool isFinished;

	float speedY = 8.0f;
	int upDown;
	
public:
	
	
	
	WaveMovementState(Transform* t, int i)
		: EnemyState(t)
	{
		upDown = i;
		time = 0.0f;
		isFinished = false;
	}

	

	virtual void Update() override {
	
		if (tr->rotation > 75)
		{
			upDown = -1;
		}
		else if (tr->rotation < -75)
		{
			upDown = 1;
		}

		tr->rotation += upDown;

		float rad = tr->rotation * (3.14f / 180.0f);

		tr->position.x += cos(rad) / 4 * 10;
		tr->position.y += sin(rad) * speedY;

		
	}
	
};
