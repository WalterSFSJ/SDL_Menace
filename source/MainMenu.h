#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Button.h"
class MainMenu : public Scene
{
public:
	MainMenu() = default;
	Button* button;

	void OnEnter() {
	
		button = new Button([]() { SM.SetNextScene("Gameplay"); });
		TextObject* text = new TextObject("Play");		
		text->GetTransform()->position.x = 119;
		text->GetTransform()->position.y = 119;
		
		_ui.push_back(button);
		_ui.push_back(text);
	}

	void OnExit() override {
		
		Scene::OnExit();
	}

	void Update() override {
	
		if (IM->GetEvent(SDLK_SPACE, DOWN))
			button->OnClicked();

		Scene::Update();
	}

	void Render() override {
	
		Scene::Render();
	}
};
