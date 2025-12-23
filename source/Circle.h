#pragma once
#include "Enemy.h"
#include "Projectile.h"
#include "TimeManager.h"
#include <vector>

class Circle : public Enemy
{
public:
	float _shotTimer = 0.0f;
	float _shotInterval = 0.2f;

	float _angle = 0.0f;          
	float _radius = 100.0f;       
	float _orbitSpeed = 5.0f;     
	float _forwardSpeed = 150.0f; 

	float _centerY;

	Circle(Vector2 pos)
		: Enemy(pos, "resources/images/daniel.png", Vector2(1000.f, 1054.f))
	{
		_centerY = pos.y;
	}

	void CircleMovement() {

		float dt = TIME.GetDeltaTime();

		_transform->position.x += _forwardSpeed * dt;

		_angle += _orbitSpeed * dt;

		
		float offsetX = cos(_angle) * _radius;
		float offsetY = sin(_angle) * _radius;

		
		_transform->position.y = _centerY + offsetY;

		
		_transform->position.x += offsetX * dt * _orbitSpeed;

	}

	void LeaveTrail() {
		_shotTimer += TIME.GetDeltaTime();

		if (_shotTimer >= _shotInterval) {

			new Projectile(_transform->position);

			_shotTimer = 0.0f; 
		}
	}

	void Update() {

		CircleMovement();
		LeaveTrail();

		Enemy::Update();

	}
};
