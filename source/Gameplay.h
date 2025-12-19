#pragma once
#include "Scene.h"
#include "TestObject.h"
#include "Ship.h"
#include "TextObject.h"
#include "Spawner.h"
#include "BackGround.h"
#include "HorizontalMedusa.h"
#include "VerticalMedusa.h"
#include "Beholder.h"
#include "Bubble.h"
#include "KillerWhale.h"
#include "AudioManager.h"
#include "TestAnimation.h"
#include "Circle.h"

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override {
		srand(time(NULL));

		//BackGround* B_one = new BackGround(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2));

		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH + RM->WINDOW_WIDTH/2, RM->WINDOW_HEIGHT / 2)));
		
		_ui.push_back(new Ship());		
		_ui.push_back(new Circle(Vector2(0, 10)));

		/*
		_ui.push_back(new Bubble(Vector2(RM->WINDOW_WIDTH / 2, 500)));
		_ui.push_back(new Bubble(Vector2(RM->WINDOW_WIDTH / 2 + 200, 500)));
		_ui.push_back(new Bubble(Vector2(RM->WINDOW_WIDTH / 2 + 400, 500)));
		*/
		TextObject* text = new TextObject("Hola");
		text->GetTransform()->position.x = 200;
		text->GetTransform()->position.y = 200;
		_ui.push_back(text);
		SPAWNER.SpawnObject(new TestAnimation());
		AM->PlaySound("resources/audio/music/froggerSong.wav");
		//AM->PlaySoundLooping("resources/audio/sfx/defeat.wav");
	}

	void OnExit() override { Scene::OnExit(); }

	void Update() override { Scene::Update(); }

	void Render() override { Scene::Render(); }

};
