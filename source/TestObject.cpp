#include "TestObject.h"

void TestObject::Update()
{
	if (IM->GetEvent(SDLK_S, DOWN))
		_transform->position.y += 0.05;
	
	else if (IM->GetEvent(SDLK_R, DOWN))
		physics->AddTorque(1.f);

	else if (IM->GetEvent(SDLK_W, DOWN))
		_transform->position.y -= 0.05;
	else if (IM->GetEvent(SDLK_A, DOWN))
		_transform->position.x -= 0.05;
	else if (IM->GetEvent(SDLK_D, DOWN))
		_transform->position.x += 0.05;

	Object::Update();
}
