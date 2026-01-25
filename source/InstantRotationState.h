#pragma once
#include "EnemyState.h"


class InstantRotationState : public EnemyState
{
private:

	float _f;
public:
	


	InstantRotationState(Transform* _tr, float f)
		: EnemyState(_tr)
	{
		_f = f;
	}
	
	

	


	void Update() {
	
		tr->rotation += _f;

		Finish();
	}
	
};
