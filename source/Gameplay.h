#pragma once
#include "Scene.h"
#include "TestObject.h"
#include "Ship.h"
#include "TextObject.h"
#include "Spawner.h"
#include "BackGround.h"


#include "AudioManager.h"
#include "TestAnimation.h"

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	TextObject* scoreText;


	void OnEnter() override {
		srand(time(NULL));

		//BackGround* B_one = new BackGround(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2));

		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH + RM->WINDOW_WIDTH/2, RM->WINDOW_HEIGHT / 2)));
		
		SPAWNER.SpawnObject(new Ship());
		
		SPAWNER.ReadWave();

		
		scoreText = new TextObject("000");
		scoreText->GetTransform()->position.x = 300;
		scoreText->GetTransform()->position.y = 300;
		_ui.push_back(scoreText);
		//SPAWNER.SpawnObject(new TestAnimation());
		AM->PlaySound("resources/audio/music/froggerSong.wav");
		//AM->PlaySoundLooping("resources/audio/sfx/defeat.wav");
	}

	void OnExit() override { Scene::OnExit(); }

	void Update() override { 
		Scene::Update(); 
		CheckForEnemies();
		scoreText->SetText(std::to_string(score)); 
	}

	void Render() override { Scene::Render(); }

};
