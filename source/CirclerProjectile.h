#pragma once
#include "Projectile.h"

class CirclerProjectile : public Projectile
{
private:

	bool start;
	bool alreadyCollided;

public:
	CirclerProjectile(Vector2 startingPos, Object* whoNotToKill, int speed, int direction)
		: Projectile(startingPos, whoNotToKill, speed, direction)
	{
		start = false;
		alreadyCollided = false;
	}
	

	void Start() {
	
		start = true;
	}


	void MoveRotating() {
	
		_transform->rotation += 2.0f;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) * _speed;
		_transform->position.y += sin(rad) * _speed;
	}

	virtual void Update() override {
	
		if (start == false)
			return;

		MoveRotating();


		Object::Update();

	}
	
	void SelfDestruct() {
	
		Destroy();
	}

	bool AlreadyCollided() {
		return alreadyCollided;
	}
	virtual void Destroy() {
	
		alreadyCollided = true;
		Object::Destroy();
	}

};
