#include "BackGround.h"

void BackGround::Update()
{
	_transform->position.x -= 1.0f;

	if (_transform->position.x < -600.0f)
	{
		_transform->position.x = RM->WINDOW_WIDTH / 2 * 3;
	}

	Object::Update();
}
