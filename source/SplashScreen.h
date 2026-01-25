#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Button.h"
#define SPACE 19
class SplashScreen : public Scene
{
private:
	float time = 0.0f;
	float maxTime = 3.0f;

public:
	SplashScreen() = default;
	

	~SplashScreen() {
		
	}

	void OnEnter() {
	
		ImageObject* img = new ImageObject("resources/images/space.png", Vector2(0.0f, 0.0f), Vector2(2376.0f, 1440.0f));

		img->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2);
		img->GetTransform()->scale = Vector2(15.5f, 10.5f);

		_ui.push_back(img);


		TextObject* text = new TextObject("The Game", Vector2((RM->WINDOW_WIDTH / 10) * 2, (RM->WINDOW_HEIGHT / 10) * 9));
		text->GetTransform()->scale = Vector2(5.0f, 5.0f);		
		_ui.push_back(text);
		
	}

	void OnExit() override {
		
		Scene::OnExit();
	}

	void Update() override {
	
		time += TIME.GetDeltaTime();

		if (time >= maxTime)
			SM.SetNextScene("MainMenu");

		Scene::Update();
	}

	void Render() override {
	
		Scene::Render();
	}
};
