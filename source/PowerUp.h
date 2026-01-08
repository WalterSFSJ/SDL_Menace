#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

#define OUTOFBOUNDS 350

class PowerUp : public ImageObject
{
public:
	float speed = 20.0f;
	Vector2 targetPosition;
	int is_powerUp;

	PowerUp(Vector2 spawnPos, std::string pngPath, Vector2 imageSize)
		: ImageObject(pngPath, Vector2(0.f, 0.f), imageSize)
	{
		_transform->position = spawnPos;
		_transform->scale = Vector2(1.5f, 1.5f);


		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);
	}

	void MoveHorizontallyTo(Vector2 targetPos) {

		_transform->position.x -= speed / 4;
	}

	void Update()
	{
		MoveHorizontallyTo(targetPosition);
		if (_transform->position.x < -OUTOFBOUNDS)
		{
			Destroy();
		}

		Object::Update();
	}

	void Change(Vector2 position)
	{
		switch (is_powerUp)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;

		default:
		}
	}
	virtual void PowerUpEfect() = 0;

	Vector2 GetPosition()
	{
		return _transform->position;
	}
};

