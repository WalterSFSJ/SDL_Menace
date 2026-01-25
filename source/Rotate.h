#pragma once
#include "EnemyState.h"


class Rotate : public EnemyState
{
private:
	float _rotationLimit = 300.0f;
	float _speed = 6.0f;
	float _rotationSpeed = 1.0f;

public:
	


	Rotate(Transform* _tr)
		: EnemyState(_tr)
	{
		
	}
	
	Rotate(Transform* _tr, float rotationLimit, float rotationSpeed, float linearSpeed)
		: EnemyState(_tr)
	{
		_rotationLimit = rotationLimit;
		_rotationSpeed = rotationSpeed;
		_speed = linearSpeed;		
	}

	
	void CheckIfDone() {
	
		if (tr->rotation > _rotationLimit)
			Finish();
	}
	

	void Update() {
	
		tr->rotation += _rotationSpeed;

		float rad = tr->rotation * (3.14f / 180.0f);

		tr->position.x += cos(rad) * _speed;
		tr->position.y += sin(rad) * _speed;

		
		CheckIfDone();
	}
	
};
