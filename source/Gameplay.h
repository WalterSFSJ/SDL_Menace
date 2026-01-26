#pragma once
#include "Scene.h"
#include "TestObject.h"
#include "Ship.h"
#include "TextObject.h"
#include "BackGround.h"
#include "SceneManager.h"
#include "PowerUp.h"

#include "AudioManager.h"
#include "TestAnimation.h"


enum GameState { GOING, PAUSED, DEAD, GAMEOVER };

class Gameplay : public Scene
{
private:
	GameState currentState;
	int lives = 2;
public:
	Gameplay() = default;

	TextObject* scoreText;

	~Gameplay() {
	
		delete(scoreText);
		scoreText = nullptr;		

		
	}

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
		AM->PlaySoundLooping("resources/audio/music/froggerSong.wav");
		//AM->PlaySoundLooping("resources/audio/sfx/defeat.wav");
	}

	void OnExit() override { Scene::OnExit(); }

	void Update() override { 


		Scene::Update(); 
		

		// 3) Comprovar col·lisions i si es mort
		int size = _objects.size();
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < _objects.size(); j++) {
				if (_objects[i]->GetRigidBody()->CheckCollision(_objects[j]->GetRigidBody())) {
					if (dynamic_cast<Ship*>(_objects[i]) && dynamic_cast<Enemy*>(_objects[j]))
					{
						dynamic_cast<Ship*>(_objects[i])->GetHurt();
						dynamic_cast<Enemy*>(_objects[j])->GetHurt();
					}
					else if (dynamic_cast<Enemy*>(_objects[i]) && dynamic_cast<Projectile*>(_objects[j]))
					{
						if (dynamic_cast<Projectile*>(_objects[j])->IsKillable(_objects[i]))
						{
							score += dynamic_cast<Enemy*>(_objects[i])->GiveScore();
							dynamic_cast<Enemy*>(_objects[i])->GetHurt();
							_objects[j]->Destroy();
						}
					}
					else if (dynamic_cast<Ship*>(_objects[i]) && dynamic_cast<Projectile*>(_objects[j]))
					{
						if (dynamic_cast<Projectile*>(_objects[j])->IsKillable(_objects[i]))
						{
							dynamic_cast<Ship*>(_objects[i])->GetHurt();

							_objects[j]->Destroy();

						}
					}
					else if (dynamic_cast<Ship*>(_objects[i]) && dynamic_cast<PowerUp*>(_objects[j]))
					{
						dynamic_cast<PowerUp*>(_objects[j])->OnCollisionEnter(_objects[i]);
						_objects[j]->Destroy();
					}
					else if (dynamic_cast<PowerUp*>(_objects[i]) && dynamic_cast<Ship*>(_objects[j]))
					{
						dynamic_cast<PowerUp*>(_objects[i])->OnCollisionEnter(_objects[j]);
						_objects[j]->Destroy();
					}
					else if (dynamic_cast<Projectile*>(_objects[i]) && dynamic_cast<PowerUp*>(_objects[j]))
					{
						dynamic_cast<PowerUp*>(_objects[j])->OnCollisionEnter(_objects[i]);
					}
					else if (dynamic_cast<PowerUp*>(_objects[i]) && dynamic_cast<Projectile*>(_objects[j]))
					{
						dynamic_cast<PowerUp*>(_objects[i])->OnCollisionEnter(_objects[j]);
					}
				}
			}

			if (dynamic_cast<Enemy*>(_objects[i])) {
				if (dynamic_cast<Enemy*>(_objects[i])->Dead()) {
					WM->EnemyDied();
					SPAWNER.SpawnObject(new PowerUp(this));
				}
			}

			if (dynamic_cast<Ship*>(_objects[i])){
				if (dynamic_cast<Ship*>(_objects[i])->IsPendingDestroy())				
					End();
			}

			if (dynamic_cast<Biotitan*>(_objects[i])) {
				if (dynamic_cast<Biotitan*>(_objects[i])->IsPendingDestroy()) {
					End();
				}
			}
		}

		scoreText->SetText(std::to_string(score)); 
	}

	void End() {
	
		score = 0;
		AM->HaltAudio();
		SM.SetNextScene("MainMenu");
		WM->Reset();
	}

	void Render() override { Scene::Render(); }


	void PlayerDead() {
		currentState = DEAD;
	}
};
