#pragma once
#include "Enemy.h"
#include "TimeManager.h"
#include "CirclerProjectile.h"

#define SPD 10


class Circler : public Enemy
{
private:
	std::vector<CirclerProjectile*> _projectiles;
	float time;
public:

	float _angle = 0.0f;
	float _radius = 100.0f;
	float _orbitSpeed = 5.0f;
	float _forwardSpeed = 150.0f;

	
	Circler()
		: Enemy(Vector2(600, 110), "resources/images/circle.png", Vector2(1000.f, 1054.f))
	{

		time = 0.0f;
	}

	void LeaveTrail();
	
	void Circling() {
		_transform->rotation += 2.0f;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) * SPD;
		_transform->position.y += sin(rad) * SPD;
	}


	void Update() {

		time += TIME.GetDeltaTime();
		
		if (time > 6.0f)
		{
			_projectiles[9]->Start();
		}
		else if (time > 5.5f)
		{
			_projectiles[8]->Start();
		}
		else if (time > 5.0f)
		{
			_projectiles[8]->Start();
		}
		else if (time > 4.5f)
		{
			_projectiles[7]->Start();
		}
		else if (time > 4.0f)
		{
			_projectiles[7]->Start();
		}
		else if (time > 3.5f)
		{
			_projectiles[6]->Start();
		}
		else if (time > 3.0f)
		{
			_projectiles[5]->Start();
		}
		else if (time > 2.5f)
		{
			_projectiles[4]->Start();
		}
		else if (time > 2.0f)
		{
			_projectiles[3]->Start();
		}
		else if (time > 1.5f)
		{
			_projectiles[2]->Start();
		}
		else if (time > 1.0f)
		{
			_projectiles[1]->Start();
		}
		else if (time > 0.5f)
		{
			_projectiles[0]->Start();
		}
		

		Circling();

		Enemy::Update();

	}

	Vector2 GivePosition() {
	
		return _transform->position;
	}
	
	int GiveSpeed() {
	
		return SPD;
	}

	void BindProjectile(CirclerProjectile* p) {
	
		_projectiles.push_back(p);
	}

	virtual void Destroy() override {

		for (CirclerProjectile* o : _projectiles)
		{
			o->Destroy();
		}

		_projectiles.clear();

		Object::Destroy();

	}
};
