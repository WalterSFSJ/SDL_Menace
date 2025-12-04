#include "Ship.h"

void Ship::Update()
{
	if (IM->GetEvent(SDLK_S, DOWN))
		_transform->position.y += 0.05;
	
	else if (IM->GetEvent(SDLK_R, DOWN))
		physics->AddTorque(1.f);

	else if (IM->GetEvent(SDLK_W, DOWN))
		_transform->position.y -= 0.05;
	else if (IM->GetEvent(SDLK_A, DOWN))
		_transform->position.x -= 0.05;
	else if (IM->GetEvent(SDLK_D, DOWN))
		_transform->position.x += 0.05;

	Shoot();
	Object::Update();
}

void Ship::Shoot() {
	if (IM->GetEvent(SDLK_SPACE, UP))
		SPAWNER.SpawnObject(new Projectile(_transform->position));
}