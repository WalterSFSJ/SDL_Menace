#pragma once
#include "Scene.h"
#include "TestObject.h"
#include "Ship.h"
#include "TextObject.h"
#include "BackGround.h"


#include "AudioManager.h"
#include "TestAnimation.h"


enum GameState { GOING, PAUSED, DEAD, GAMEOVER };

class Gameplay : public Scene
{
private:
	GameState currentState;

public:
	Gameplay() = default;

	TextObject* scoreText;


	void OnEnter() override {
		srand(time(NULL));

		currentState = GOING;

		//BackGround* B_one = new BackGround(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2));

		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH + RM->WINDOW_WIDTH/2, RM->WINDOW_HEIGHT / 2)));
		
		SPAWNER.SpawnObject(new Ship());
		
		WM->ReadNextWave();

		scoreText = new TextObject("0", Vector2(100, 100));
		_ui.push_back(scoreText);
		//SPAWNER.SpawnObject(new TestAnimation());
		AM->PlaySound("resources/audio/music/froggerSong.wav");
		//AM->PlaySoundLooping("resources/audio/sfx/defeat.wav");
	}

	void OnExit() override { Scene::OnExit(); }

	void Update() override { 


		Scene::Update(); 
		
		scoreText->SetText(std::to_string(score)); 
	}

	void Render() override { Scene::Render(); }


	void PlayerDead() {
		currentState = DEAD;
	}
};
