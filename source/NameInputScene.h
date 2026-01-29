#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "TextObject.h"
#include "InputManager.h"
#include "ScoreManager.h"

class NameInputScene : public Scene {
    TextObject* prompt;
    TextObject* nameText;
    int currentScore;

public:
    NameInputScene(int score) : currentScore(score) {
        int centerX = 512 / 2; 
        prompt = new TextObject("NEW RECORD! ENTER NAME:", Vector2(centerX - 150, 200));
        nameText = new TextObject("_", Vector2(centerX - 50, 280));

        _ui.push_back(prompt);
        _ui.push_back(nameText);
    }

    void OnEnter() override {
        IM->StartTextInput(); 
    }

    void OnExit() override {
        IM->StopTextInput(); 
    }

    void Update() override {
        Scene::Update();

        std::string currentName = IM->GetInputText();

        nameText->SetText(currentName + "_");

        if (IM->GetEvent(SDLK_RETURN, DOWN) || IM->GetEvent(SDLK_KP_ENTER, DOWN)) {
            if (currentName.empty()) currentName = "PILOT";

            ScoreManager::Instance().AddScore(currentName, currentScore);
            SM.SetNextScene("ScoreBoard");
        }
    }

    void Render() override { Scene::Render(); }
};