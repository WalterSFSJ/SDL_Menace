#include "BackGround.h"

void BackGround::Update()
{
	_transform->position.x -= 1.0f;



	Object::Update();
}
