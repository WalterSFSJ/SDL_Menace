#pragma once
#include "EnemyState.h"


class GoCirclingState : public EnemyState
{
private:
	Transform* t;
	float speed;

public:
	
	~GoCirclingState() {}
	
	GoCirclingState(Transform* _tr, float _speed)
		: EnemyState(_tr)
	{
		t = _tr;
		speed = _speed;
	}

	
	

	

	void Update() {
	
		t->rotation += 1.0f * speed;

		float rad = t->rotation * (3.14f / 180.0f);

		t->position.x -= cos(rad) * speed + 2.0f;
		t->position.y += sin(rad) * speed;
	}
	
};
