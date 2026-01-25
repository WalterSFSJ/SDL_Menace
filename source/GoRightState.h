#pragma once
#include "EnemyState.h"
#include "Vector2.h"


class GoRightState : public EnemyState
{
private:

	float pixelsPerSec;
	float time = 0.0f;
	float _maxTime;
public:
	
	~GoRightState() {}
	
	GoRightState(float _pps, Transform* t, float maxTime)
		: EnemyState(t)
	{
		pixelsPerSec = _pps;
		_maxTime = maxTime;
	}

	virtual void Update() override {
	
		time += TIME.GetDeltaTime();

		if (time > _maxTime)
			Finish();


		float rad = tr->rotation * (3.14f / 180.0f);

		tr->position.x += cos(rad) * pixelsPerSec;
		tr->position.y += sin(rad) * pixelsPerSec;
	}
	
};
