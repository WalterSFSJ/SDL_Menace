#pragma once
#include "Transform.h"
#include "EnemyState.h"
#include <vector>

class EnemyStateManager
{
private:
	Transform* tr;
	std::vector<EnemyState*> allStates;
	EnemyState* currentState;

public:
	
	
	
	EnemyStateManager()		
	{
		
	}

	
	void Update() {
	
	
	}
	
};
