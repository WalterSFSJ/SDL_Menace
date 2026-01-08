#pragma once
#include "EnemyState.h"
#include "TimeManager.h"


class WaveMovementState : EnemyState
{
private:
	float time;
	bool isFinished;

	float speedY = 8.0f;
	int upDown = 1;
	
public:
	
	
	
	WaveMovementState()
	{
		time = 0.0f;
		isFinished = false;
	}

	void Finish() {
	

	}

	void Update() {
	
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
