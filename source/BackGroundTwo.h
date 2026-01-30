#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

class BackGroundTwo : public ImageObject
{
public:
	BackGroundTwo(Vector2 pos)
		: ImageObject("resources/images/cave.png", Vector2(0.f, 0.f), Vector2(1920.f, 1080.f))
	{
		// Posició random en tota la finestra

		_transform->position = pos;
		_transform->scale = Vector2(15.5f, 10.5f);

		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);
	 }

	void Update() {
	
		_transform->position.x -= 1.0f;

		if (_transform->position.x < -600.0f)
		{
			_transform->position.x = RM->WINDOW_WIDTH / 2 * 3;
		}

		Object::Update();
	}
};
