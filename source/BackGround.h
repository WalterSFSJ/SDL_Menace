#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Spawner.h"
class BackGround : public ImageObject
{
public:
	BackGround(Vector2 pos)
		: ImageObject("resources/images/background.png", Vector2(0.f, 0.f), Vector2(1920.f, 1080.f))
	{
		// Posició random en tota la finestra
		//Vector2 randomPosition = Vector2(RM->WINDOW_WIDTH/2, RM->WINDOW_HEIGHT/2);
		//Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = pos;
		_transform->scale = Vector2(15.5f, 10.5f);

		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);
	 }

	void Update();
};
