#pragma once
#include "AnimatedImageObject.h"

class TestAnimation : public AnimatedImageObject
{
public:
	TestAnimation()
		: AnimatedImageObject("resources/images/sample_spritesheet.png", Vector2(0.0f, 0.0f), Vector2(96.0f,128.0f), 12, 3, 32.0f, 32.0f, true) {

		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_HEIGHT, rand() % RM->WINDOW_HEIGHT);
		_transform->position = randomPosition;
		_transform->scale = Vector2(2.0f, 2.0f);
	}

	void Update() override {
	
		Object::Update();
	}
};