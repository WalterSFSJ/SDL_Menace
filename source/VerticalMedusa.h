#pragma once
#include "Enemy.h"
#include "TimeManager.h"

class VerticalMedusa : public Enemy
{
public:

	float moveY = 2.0f;
	int timeMove = 3; 
	float timePause = 3.0f; 
	float moveTimer = 0; 
    bool isMoving = true;
	
	VerticalMedusa()
		: Enemy(Vector2(rand()% 1000 + 100, RM->WINDOW_HEIGHT), "resources/images/up.png", Vector2(1000.f, 1054.f))
	{
		score = 50;
		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
	}

	void MoveVertical() {

        
		moveTimer += TIME.GetDeltaTime();


        if (moveTimer < 4.0f) {
			_transform->position.y -= moveY;
        }
        else if (moveTimer > 6.0f) {
			moveTimer = 0.0f;
		}
	}

	void Update() {

		MoveVertical();

		Enemy::Update();

	}
};
