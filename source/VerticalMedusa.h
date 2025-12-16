#pragma once
#include "Enemy.h"
#include "TimeManager.h"

class VerticalMedusa : public Enemy
{
public:

	float moveY = 0.01;
	int timeMove = 3; 
	float timePause = 3.0f; 
	int moveTimer = 0; 
    bool isMoving = true;
	
	VerticalMedusa()
		: Enemy(Vector2(rand()% 1000 + 100, RM->WINDOW_HEIGHT + 100), "resources/images/up.png", Vector2(1000.f, 1054.f))
	{

		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
	}

	void MoveVertical() {

        
		moveTimer = TIME.GetDeltaTime();


        if (isMoving) {

			_transform->position.y -= moveY;

            if (moveTimer % timeMove < 0.2f) {
                isMoving = false;

            }
        }
        else if (moveTimer % timeMove >= 0.2f) {
			isMoving = true;

		}
	}

	void Update() {

		MoveVertical();

		Enemy::Update();

	}
};
