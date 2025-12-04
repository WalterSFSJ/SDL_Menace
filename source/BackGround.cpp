#include "BackGround.h"

void BackGround::Update()
{
	_transform->position.x -= 0.01f;

	if (_transform->position.x < -1360 / 2)
	{
		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH + RM->WINDOW_WIDTH/2, RM->WINDOW_HEIGHT/2)));
		GetDestroyed();
	}

	Object::Update();
}
