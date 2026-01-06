#pragma once
#include "ImageObject.h"
#include "IDamageable.h"
#include "RenderManager.h"
#include "InputManager.h"


#define OUTOFBOUNDSX 450
#define OUTOFBOUNDSY 50

class Enemy : public ImageObject, public IDamageable
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

	virtual void GetHurt() override{
		
		IDamageable::GetHurt();

		if (Dead())
		{
			Destroy();
		}
	}


	void Update() {

		if (_transform->position.x < -OUTOFBOUNDSX)
		{
			GetHurt();
		}
		else if (_transform->position.y < -OUTOFBOUNDSY) {
			GetHurt();
		}
		else if (_transform->position.y > RM->WINDOW_HEIGHT + OUTOFBOUNDSY) {
			GetHurt();
		}
		
		

		Object::Update();
	}
};
