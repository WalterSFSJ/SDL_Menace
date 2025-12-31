#include "Projectile.h"

void Projectile::Update()
{
	_transform->position.x += _speed * _direction;

	if (_transform->position.x > RM->WINDOW_WIDTH)
	{
		Destroy();
	}

	Object::Update();
}
