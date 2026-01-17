#pragma once
#include "EnemyState.h"


class Rotate : public EnemyState
{
private:
	float rotationLimit = 300.0f;
	float speed = 6.0f;
	

public:
	
	
	
	Rotate(Transform* _tr)
		: EnemyState(_tr)
	{
		
	}

	
	void CheckIfDone() {
	
		if (tr->rotation > rotationLimit)
			Finish();
	}
	

	void Update() {
	
		tr->rotation += 1.0f;

		float rad = tr->rotation * (3.14f / 180.0f);

		tr->position.x += cos(rad) * speed;
		tr->position.y += sin(rad) * speed;

		
		CheckIfDone();
	}
	
};
