#pragma once
#include "Transform.h"



class EnemyState
{
private:
	bool finished = false;
protected:
	Transform* tr;

public:
	
	
	
	EnemyState(Transform* _tr)
	{
		tr = _tr;
	}

	virtual void Update() {}
	
	~EnemyState() {
		delete(tr);
		tr = nullptr;
	}

	void NextState() {

	}

	void Finish() {

		finished = true;
	}
	
	bool IsFinished() {
		return finished;
	}
};
