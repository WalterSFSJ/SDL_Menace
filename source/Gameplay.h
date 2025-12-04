#pragma once
#include "Scene.h"
#include "TestObject.h"
#include "Ship.h"
#include "TextObject.h"
#include "Spawner.h"
#include "BackGround.h"
class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override {
	
		//BackGround* B_one = new BackGround(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2));

		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
		SPAWNER.SpawnObject(new BackGround(Vector2(RM->WINDOW_WIDTH + RM->WINDOW_WIDTH/2, RM->WINDOW_HEIGHT / 2)));
		//SPAWNER.SpawnObject(new Ship());
		_ui.push_back(new Ship());
		TextObject* text = new TextObject("Hola");
		text->GetTransform()->position.x = 200;
		text->GetTransform()->position.y = 200;
		_ui.push_back(text);
	}

	void OnExit() override { Scene::OnExit(); }

	void Update() override { Scene::Update(); }

	void Render() override { Scene::Render(); }

};
