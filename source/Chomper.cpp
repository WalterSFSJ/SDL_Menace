#include "Chomper.h"

void Chomper::Rotate() {

	_transform->rotation += 1.0f * speed;

	float rad = _transform->rotation * (3.14f / 180.0f);

	_transform->position.x -= cos(rad) * speed + 2.0f;
	_transform->position.y += sin(rad) * speed;
}

void Chomper::Update() {

	Rotate();

	Enemy::Update();

}