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
	
	
	
	LinearMovementState(float _pps, Vector2 _start, Vector2 _finish, Transform* t)
		: EnemyState(t)
	{
		start = _start;
		finish = _finish;

		pixelsPerSec = _pps;

		Vector2 line = finish - start;

		//float norm = sqrt(line.x * line.x + line.y * line.y);

		//direction = Vector2((line.x / norm) * pixelsPerSec, (line.y / norm) * pixelsPerSec);

		line.Normalize();
		direction = Vector2(line.x * pixelsPerSec, line.y * pixelsPerSec);
	}

	virtual void Update() override {
	
		if (abs(tr->position.x) - abs(finish.x) < 5 && abs(tr->position.y) - abs(finish.y) < 5)
		{
			Finish();
			return;
		}

		tr->position.x += direction.x;
		tr->position.y += direction.y;
	}
	
};
