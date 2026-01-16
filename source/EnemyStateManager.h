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
	int stateNumber = 0;
public:
	
	EnemyStateManager()
	{
		
	}
	
	EnemyStateManager(Transform* _tr)		
	{
		tr = _tr;
	}

	
	void Update() {
	
		if (!currentState->IsFinished())
			currentState->Update();
		else
			NextState(allStates[stateNumber]);
	}
	
	void AddState(EnemyState* es) {
		
		allStates.push_back(es);
		if (allStates.size() == 1)
		{
			currentState = allStates[0];
		}
	}
	void SetCurrentState(EnemyState* es) {

		currentState = es;
	}
	void NextState(EnemyState* es) {

		if (es == nullptr)
			return;

		currentState = es;

		stateNumber++;
	}

};
