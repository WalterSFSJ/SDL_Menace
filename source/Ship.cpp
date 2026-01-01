#include "Ship.h"

void Ship::Update()
{
	if (IM->GetEvent(SDLK_S, DOWN)){
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
	Object::Update();
}

void Ship::Shoot() {
	if (IM->GetEvent(SDLK_SPACE, UP))
		SPAWNER.SpawnObject(new Projectile(_transform->position, this, 18, 1));
}

void Ship::GetHurt() {
	if (health > 0)
		health--;
	else
		Destroy();
}

