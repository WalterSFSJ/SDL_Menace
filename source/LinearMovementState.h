#pragma once
#include "EnemyState.h"
#include "Vector2.h"


class LinearMovementState : public EnemyState
{
private:
	Vector2 start;
	Vector2 finish;

	float pixelsPerSec;

	Vector2 direction;

public:
	
	~LinearMovementState() {
	
	}
	
	
	LinearMovementState(float _pps, Vector2 _start, Vector2 _finish, Transform* t)
		: EnemyState(t)
	{
		start = _start;
		finish = _finish;

		pixelsPerSec = _pps;

		Vector2 line = finish - start;

		line.Normalize();
		direction = Vector2(line.x * pixelsPerSec, line.y * pixelsPerSec);
	}

	virtual void Update() override {
	
		if (abs(tr->position.x - finish.x) < 5 && abs(tr->position.y - finish.y) < 5)
		{
			Finish();
			return;
		}

		tr->position.x += direction.x;
		tr->position.y += direction.y;
	}
	
};
