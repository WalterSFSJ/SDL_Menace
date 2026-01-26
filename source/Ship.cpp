#include "Ship.h"

void Ship::Update()
{
	
	ListenInput();
	Object::Update();
}

void Ship::Shoot() {
	if (IM->GetEvent(SDLK_SPACE, UP))
	{
		SPAWNER.SpawnObject(new Projectile(_transform->position, this, 18, 1));
		if (addCannon == true)
		{
			SPAWNER.SpawnObject(new Projectile(_transform->position, this, 18, 3));
			SPAWNER.SpawnObject(new Projectile(_transform->position, this, 18, 4));
		}

		if (addLaser == true)
		{
			SPAWNER.SpawnObject(new Projectile(_transform->position, this, 18, -2));
		}
		
	}
}

void Ship::GetHurt() {
	
	if (health > 0) {
		health--;
		return;
	}

	lifes--;
	health = maxHealth;

	_transform->position = startingPos;

	if (lifes < 0)
		Destroy();
}

void Ship::ListenInput() {

	if (IM->GetEvent(SDLK_S, DOWN)) {
		if (_transform->position.y < RM->WINDOW_HEIGHT - 30)
			_transform->position.y += speed;
	}
	else if (IM->GetEvent(SDLK_R, DOWN))
		physics->AddTorque(1.f);

	else if (IM->GetEvent(SDLK_W, DOWN)) {
		if (_transform->position.y > 30)
			_transform->position.y -= speed;
	}
	else if (IM->GetEvent(SDLK_A, DOWN)) {
		if (_transform->position.x > 30)
			_transform->position.x -= speed;
	}
	else if (IM->GetEvent(SDLK_D, DOWN)) {
		if (_transform->position.x < RM->WINDOW_WIDTH - 30)
			_transform->position.x += speed;
	}

	Shoot();
}