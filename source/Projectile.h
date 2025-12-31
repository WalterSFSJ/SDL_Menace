#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
class Projectile : public ImageObject
{
protected:

	Object* parent;
	int _direction;
	int _speed;
public:
	Projectile(Vector2 playerPos, Object* whoNotToKill, int speed, int direction)
		: ImageObject("resources/images/projectile.png", Vector2(0.f, 0.f), Vector2(900.f, 900.f))
	{
		// Posició random en tota la finestra
		Vector2 randomPosition = playerPos;
		//Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = randomPosition;
		_transform->scale = Vector2(0.5f, 0.5f);

		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);

		parent = whoNotToKill;
		_direction = direction;
		_speed = speed;
	 }

	virtual void Update();
	bool IsKillable(Object* who) {
		return who != parent;
	}
};
