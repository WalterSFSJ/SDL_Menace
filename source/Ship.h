#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Spawner.h"
#include "Projectile.h"
class Ship : public ImageObject
{
private:
	float speed;
	int health;
	int maxHealth;
	bool addLaser;
	bool addCannon;

	int lifes;

	Vector2 startingPos;

	void ListenInput();

public:
	

	Ship()
		: ImageObject("resources/images/ship.png", Vector2(0.f, 0.f), Vector2(433.f, 409.f))
	{

		Vector2 randomPosition = Vector2(100.f, 200.f);
		
		startingPos = randomPosition;

		_transform->position = startingPos;
		_transform->scale = Vector2(1.f, 1.f);

		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);

		speed = 10.0f;

		maxHealth = 3;
		health = maxHealth;

		addLaser = false;
		addCannon = false;

		lifes = 3;
	}
	void GetHurt();
	void Update();
	void Shoot();	
	void AddLaser() { addLaser = true; }
	void AddCannon() { addCannon = true; }
	void Heal() { health = 3; }
	void AddTurrets() {};
	void AddSpeed() { speed++; }
	
};
