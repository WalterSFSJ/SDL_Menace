#pragma once
#include "Enemy.h"
#include "TimeManager.h"

#define MAX 101
#define HALF 50
#define CUSHIONSPEED 100

class Beholder : public Enemy
{
public:

	Vector2 direction = Vector2(0.5f, 0.5f);
	int timeMove = 2; 
	float timePause = 3.0f; 
	int moveTimer = 0; 
    bool isMoving = true;
	
	Beholder()
		: Enemy(Vector2(300, 300), "resources/images/beholder.png", Vector2(160.f, 163.f))
	{

		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
	}

	void MoveAnywhere() {

        
		moveTimer = TIME.GetDeltaTime();


        if (isMoving) {

			_transform->position.x += direction.x;
			_transform->position.y += direction.y;

            if (moveTimer % timeMove < 0.2f) {
                isMoving = false;

            }
        }
        else if (moveTimer % timeMove >= 0.2f) {
			isMoving = true;
			
			float percentX = rand() % MAX - HALF;
			float percentY = rand() % MAX - HALF;

			float norm = sqrt(percentX * percentX + percentY * percentY);

			direction = Vector2((percentX / norm) / CUSHIONSPEED, (percentY / norm) / CUSHIONSPEED);
		}
	}

	void Update() {

		MoveAnywhere();

		Enemy::Update();

	}
};
