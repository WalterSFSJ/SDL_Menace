#pragma once
#include "ImageObject.h"
#include "InputManager.h"
#include <functional>
class Button : public ImageObject
{
public:
	typedef std::function<void()> OnClick;

	Button(OnClick onClick) 
		: ImageObject("resources/images/fist_0.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f)) 
	{
		_onClick = onClick;

		// Test
		_transform->position = Vector2(100.f, 100.f);
		_transform->scale = Vector2(1.f, 1.f);


		physics->AddCollider(new AABB(_transform->position, _transform->size));
	}


	virtual void Update() override;

	virtual void Render() override;

	void OnHoverEnter();

	void OnHoverExit();

	void OnClicked();

private:
	bool _isHovered = false;
	OnClick _onClick;
};
