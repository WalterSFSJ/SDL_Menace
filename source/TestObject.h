#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
class TestObject : public ImageObject
{
public:
	TestObject()
		: ImageObject("resources/xd.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f))
	{
		// Posició random en tota la finestra
		Vector2 randomPosition = Vector2(500.f, 500.f);
		//Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = randomPosition;
		_transform->scale = Vector2(1.5f, 1.5f);
		_transform->rotation = 30.f;

		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);
	 }

	void Update();
};
