#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Ship.h"
#include "Scene.h"

#define OUTOFBOUNDS 350

class PowerUp : public ImageObject
{
public:
	int score = 100;
	float speed = 10;
	int lvl = 0;
	const int maxLevel = 5;
	int currentHits = 0;
	const int maxHits = 6;
	Scene* scene;

	std::vector<Renderer*> renderers;

	PowerUp()
		: ImageObject("resources/images/score.png", Vector2(0, 0), Vector2(512.0f, 512.0f))
	{
		_transform->position = Vector2(300, 300);

		std::vector<std::string> texturas = {
		"resources/images/score.png", 
		"resources/images/laser.png",
		"resources/images/canon.png",
		"resources/images/healt.png",
	    "resources/images/torrets.png",
		"resources/images/speed.png"
		};

		for (int i = 0; i < maxLevel; i++)
		{
			//WE CONSIDER SPRITES ARE ARRANGED IN A LINE AND ARE 128x64
			renderers.push_back(new ImageRenderer(this->_transform, texturas[i], Vector2(0, 0), Vector2(512.0f, 512.0f)));
		}
		delete _renderer;
		_renderer = renderers[lvl];
	}
	
	~PowerUp() {}

	void AddHit() {
		if (lvl == maxLevel)
			return;
		currentHits++;
		if (currentHits == maxHits) {
			//UPDATE SPRITE ACCORING TO LEVEL
			_renderer = renderers[++lvl];
			currentHits = 0;
		}
	}

	~PowerUp() {
		for (Renderer* r : renderers)
			delete r;
	}

public:
	void OnCollisionEnter(Object* other) {
		if (Ship* player = dynamic_cast<Ship*>(other)) {
			switch (lvl) {
			case 0:
				//Add score
				break;
			case 1:
				player->AddLaser();
				break;
			case 2:
				player->AddCannon();
				break;
			case 3:
				player->Heal();
				break;
			case 4:
				player->AddTurrets();
				break;
			case 5:
				player->AddSpeed();
				break;
			}
		}
		else if (Projectile* bullet = dynamic_cast<Projectile*>(other)) {
			bullet->Destroy();
			AddHit();
		}
	}

	void MoveHorizontallyTo() {

		_transform->position.x -= speed / 4;
	}

	void Update()
	{
		MoveHorizontallyTo();
		if (_transform->position.x < -OUTOFBOUNDS)
		{
			Destroy();
		}

		Object::Update();
	}
};