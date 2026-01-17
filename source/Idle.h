#pragma once
#include "EnemyState.h"
#include "TimeManager.h"


class Idle : public EnemyState
{
private:
	float time = 0.0f;
	float pauseTime;
	

public:
	
	~Idle() {
	
	}
	
	Idle(Transform* _tr, float _pauseTime)
		: EnemyState(_tr)
	{
		time = 0.0f;
		pauseTime = _pauseTime;
	}

	
	

	

	void Update() {
	
		time += TIME.GetDeltaTime();

		if (time > pauseTime)
		{
			Finish();
		}
	}
	
};
