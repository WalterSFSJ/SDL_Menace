#pragma once
#include "EnemyState.h"
#include "Vector2.h"


class LinearMovementState : EnemyState
{
private:
	Vector2 start;
	Vector2 finish;

	float pixelsPerSec;

public:
	
	
	
	LinearMovementState(Vector2 _start)
	{
		start = _start;
	}	

	void Update() {
	
		
	}
	
};
