#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

#define OUTOFBOUNDS 350

class Enemy : public ImageObject
{
public:
	float speed = 20.0f;
	Vector2 targetPosition;
	int score;

	Enemy(Vector2 spawnPos, std::string pngPath, Vector2 imageSize)
		: ImageObject(pngPath, Vector2(0.f, 0.f), imageSize)
	{
		_transform->position = spawnPos;
		_transform->scale = Vector2(1.5f, 1.5f);
		

		physics->SetLinearDrag(0.1f);
		physics->SetAngularDrag(2.f);

		score = 100;
	 }

	int GiveScore() {

		return score;
	}

	void MoveHorizontallyTo(Vector2 targetPos) {
		
		//while _transform->position != target pos {  /%*   }
	}

	void Update() {
	
		/*_transform->rotation += 0.04f;

		float rad = _transform->rotation * (3.14f / 180.0f);

		_transform->position.x += cos(rad) / 10;
		_transform->position.y += sin(rad) / 10;*/

		if (_transform->position.x < -OUTOFBOUNDS)
		{
			Destroy();
		}


		Object::Update();
	}
};
