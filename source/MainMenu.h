#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Button.h"
#define SPACE 19
class MainMenu : public Scene
{
public:
	MainMenu() = default;
	Button* playButton;
	Button* scoreButton;
	Button* exitButton;

	void OnEnter() {
	
		playButton = new Button([]() { SM.SetNextScene("Gameplay"); }, Vector2(RM->WINDOW_WIDTH / 2, 100));
		scoreButton = new Button([]() { SM.SetNextScene("ScoreBoard"); }, Vector2(RM->WINDOW_WIDTH / 2, 400));
		TextObject* playText = new TextObject("Play", Vector2(playButton->GetPos().x + SPACE, playButton->GetPos().y + SPACE));
		TextObject* scoreText = new TextObject("Score", Vector2(scoreButton->GetPos().x + SPACE, scoreButton->GetPos().y + SPACE));
		
		_ui.push_back(playButton);
		_ui.push_back(scoreButton);

		_ui.push_back(scoreText);
		_ui.push_back(playText);
	}

	void OnExit() override {
		
		Scene::OnExit();
	}

	void Update() override {
	
		if (IM->GetEvent(SDLK_SPACE, DOWN))
			playButton->OnClicked();

		Scene::Update();
	}

	void Render() override {
	
		Scene::Render();
	}
};
