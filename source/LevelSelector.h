#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Button.h"
#include "TextObject.h"

#define SPACE 19

class LevelSelector : public Scene
{
public:
	LevelSelector() = default;

	Button* buttonLvl1;
	Button* buttonLvl2;
	Button* buttonReturnToMenu;

	~LevelSelector() {
		if (buttonLvl1) { delete buttonLvl1; buttonLvl1 = nullptr; }
		if (buttonLvl2) { delete buttonLvl2; buttonLvl2 = nullptr; }
		if (buttonReturnToMenu) { delete buttonReturnToMenu; buttonReturnToMenu = nullptr; }
	}

	void OnEnter() override {

		buttonLvl1 = new Button([]() { SM.SetNextScene("Gameplay"); }, Vector2(RM->WINDOW_WIDTH / 2, 250));

		buttonLvl2 = new Button([]() {SM.SetNextScene("LevelTwo"); }, Vector2(RM->WINDOW_WIDTH / 2, 400));

		buttonReturnToMenu = new Button([]() { SM.SetNextScene("MainMenu"); }, Vector2(RM->WINDOW_WIDTH / 2, 600));

		TextObject* textLvl1_Top = new TextObject("Level", Vector2(buttonLvl1->GetPos().x + SPACE, buttonLvl1->GetPos().y + SPACE - 10));
		TextObject* textLvl1_Bot = new TextObject("1", Vector2(buttonLvl1->GetPos().x + SPACE + 20, buttonLvl1->GetPos().y + SPACE + 15));

		TextObject* textLvl2_Top = new TextObject("Level", Vector2(buttonLvl2->GetPos().x + SPACE, buttonLvl2->GetPos().y + SPACE - 10));
		TextObject* textLvl2_Bot = new TextObject("2", Vector2(buttonLvl2->GetPos().x + SPACE + 20, buttonLvl2->GetPos().y + SPACE + 15));

		TextObject* textBack = new TextObject("Back", Vector2(buttonReturnToMenu->GetPos().x + SPACE, buttonReturnToMenu->GetPos().y + SPACE));

		_ui.push_back(buttonLvl1);
		_ui.push_back(buttonLvl2);
		_ui.push_back(buttonReturnToMenu);

		_ui.push_back(textLvl1_Top);
		_ui.push_back(textLvl1_Bot);
		_ui.push_back(textLvl2_Top);
		_ui.push_back(textLvl2_Bot);
		_ui.push_back(textBack);
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