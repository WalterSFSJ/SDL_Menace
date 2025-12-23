#include "Projectile.h"

void Projectile::Update()
{
	_transform->position.x += 18.0f;

	if (_transform->position.x > RM->WINDOW_WIDTH)
	{
		Destroy();
	}

	Object::Update();
}
