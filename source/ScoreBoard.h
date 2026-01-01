#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Button.h"
#define SPACE 19

class ScoreBoard : public Scene
{
public:
	ScoreBoard() = default;
	Button* exitButton;

	void OnEnter() {
	
		exitButton = new Button([]() { SM.SetNextScene("MainMenu"); }, Vector2(100, 100));
		TextObject* text = new TextObject("Play", Vector2(exitButton->GetPos().x + SPACE, exitButton->GetPos().y + SPACE));
		
		_ui.push_back(exitButton);
		_ui.push_back(text);
	}

	void OnExit() override {
		
		Scene::OnExit();
	}

	void Update() override {
	
		Scene::Update();
	}

	void Render() override {
	
		Scene::Render();
	}
};
