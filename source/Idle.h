#pragma once
#include "EnemyState.h"
#include "TimeManager.h"


class Idle : EnemyState
{
private:
	float time;
	bool isFinished;

public:
	
	
	
	Idle()
	{
		time = 0.0f;
		isFinished = false;
	}

	void Finish() {
	

	}

	void Update() {
	
		time += TIME.GetDeltaTime();

		if (time > 2.0f)
		{
			isFinished = true;
		}
	}
	
};
