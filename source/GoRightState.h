#pragma once
#include "EnemyState.h"
#include "Vector2.h"


class GoRightState : public EnemyState
{
private:

	float pixelsPerSec;

public:
	
	~GoRightState() {
	
	}
	
	GoRightState(float _pps, Transform* t)
		: EnemyState(t)
	{
		pixelsPerSec = _pps;
	}

	virtual void Update() override {
	
		float rad = tr->rotation * (3.14f / 180.0f);

		tr->position.x += cos(rad) * pixelsPerSec;
		tr->position.y += sin(rad) * pixelsPerSec;
	}
	
};
