#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

class BackGround : public ImageObject
{
public:
	BackGround(Vector2 pos)
		: ImageObject("resources/images/background.png", Vector2(0.f, 0.f), Vector2(1920.f, 1080.f))
	{
		// Posició random en tota la finestra

		_transform->position = pos;
		_transform->scale = Vector2(15.5f, 10.5f);

		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);
	 }

	void Update();
};
