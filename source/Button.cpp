#include "Button.h"
#define LIGHT "resources/images/button.png"
#define DARK "resources/images/button_1.png"
void Button::Update()
{
	if (!_isHovered && physics->CheckOverlappingPoint({ (float)IM->GetMouseX() , (float)IM->GetMouseY() }))
		OnHoverEnter();
	else if (_isHovered && !physics->CheckOverlappingPoint({ (float)IM->GetMouseX() , (float)IM->GetMouseY() }))
		OnHoverExit();
	else if (_isHovered && IM->GetLeftClick())
		OnClicked();

	Object::Update();
}

void Button::Render()
{
	Object::Render();
}

void Button::OnHoverEnter()
{
	ChangeImage(DARK);
	_isHovered = true;
}

void Button::OnHoverExit()
{
	ChangeImage(LIGHT);	
	_isHovered = false;
}
void Button::OnClicked()
{
	_onClick();
}