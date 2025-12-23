#pragma once
#include "Object.h"
#include "Vector2.h"
#include "TestObject.h"

class PowerUp : public Object
{
public:
	bool powerUpChange = false;
	PowerUp()
	{

	}

	virtual void Update() = 0;
	virtual bool PlayerColicion() = 0;
	virtual void Change() = 0;
	virtual void PowerUpEfect() = 0;

	Vector2 GetPosition()
	{
		return _transform->position;
	}
};

