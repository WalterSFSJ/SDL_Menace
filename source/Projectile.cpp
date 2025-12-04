#include "Projectile.h"

void Projectile::Update()
{
	_transform->position.x += 0.05;

	if (_transform->position.x > RM->WINDOW_WIDTH)
	{
		GetDestroyed();
	}

	Object::Update();
}
