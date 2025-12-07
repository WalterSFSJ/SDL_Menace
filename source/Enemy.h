#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
class Enemy : public ImageObject
{
public:
	Enemy()
		: ImageObject("resources/xd.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f))
	{
		_transform->position = Vector2(500.f, 200.f);
		_transform->scale = Vector2(1.5f, 1.5f);
		

		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);
	 }

	void Update() {
	
		_transform->rotation += 0.04f;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) / 10;
		_transform->position.y += sin(rad) / 10;

		Object::Update();
	}
};
