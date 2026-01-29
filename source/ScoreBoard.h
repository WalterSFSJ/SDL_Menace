#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Button.h"
#include "ScoreManager.h"
#include "RenderManager.h"
#include <string>

#define SPACE 19
#define ROW_HEIGHT 30

class ScoreBoard : public Scene
{
public:
	ScoreBoard() = default;
	Button* exitButton;
	std::vector<TextObject*> scoreLabels;

	~ScoreBoard() {
	
		delete(exitButton);
		exitButton = nullptr;
		for (auto t : scoreLabels) delete t;
		scoreLabels.clear();
	}

	void OnEnter() {
		int centerX = RM->WINDOW_WIDTH / 2;
		int startY = 100;
	
		exitButton = new Button([]() { SM.SetNextScene("MainMenu"); }, Vector2(centerX - 64, 450));
		TextObject* text = new TextObject("BACK", Vector2(exitButton->GetPos().x + SPACE, exitButton->GetPos().y + SPACE));
		
		_ui.push_back(exitButton);
		_ui.push_back(text);

		TextObject* title = new TextObject("TOP 10 PILOTS", Vector2(centerX - 80, 50));
		scoreLabels.push_back(title);
		_ui.push_back(title);

		const auto& scores = ScoreManager::Instance().GetScores();

		int rank = 1;

		for (const auto& s : scores) {
			std::string line = std::to_string(rank) + ". " + s.name + " ... " + std::to_string(s.score);

			int textOffset = line.length() * 5;

			TextObject* t = new TextObject(line, Vector2(centerX - 100, startY));

			scoreLabels.push_back(t);
			_ui.push_back(t);
			startY += 30; 
			rank++;
		}
	}

	void OnExit() override {
		
		Scene::OnExit();
		scoreLabels.clear();
	}

	void Update() override {
	
		Scene::Update();
	}

	void Render() override {
	
		Scene::Render();
	}
};
