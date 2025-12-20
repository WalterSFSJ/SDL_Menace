#pragma once
#include "Enemy.h"
#include "TimeManager.h"

#define MAX 101
#define HALF 50
#define CUSHIONSPEED 5

class Beholder : public Enemy
{
public:

	Vector2 direction = Vector2(0.5f * CUSHIONSPEED, 0.5f * CUSHIONSPEED);
	int timeMove = 2; 
	float timePause = 3.0f; 
	float moveTimer = 0; 
    bool isMoving = true;
	
	Beholder(float f)
		: Enemy(Vector2(f, 300), "resources/images/beholder.png", Vector2(1238.f, 760.f))
	{
		_transform->scale = Vector2(0.7f, 0.7f);
		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
	}

	void MoveAnywhere() {

        
		moveTimer += TIME.GetDeltaTime();


        if (isMoving) {

			_transform->position.x += direction.x;
			_transform->position.y += direction.y;

            if (moveTimer > timeMove) {

                isMoving = false;
            }
        }
        else if (moveTimer >= timePause) {
			isMoving = true;
			moveTimer = 0.0f;
			float percentX = rand() % MAX - HALF;
			float percentY = rand() % MAX - HALF;

			float norm = sqrt(percentX * percentX + percentY * percentY);

			direction = Vector2((percentX / norm) * CUSHIONSPEED, (percentY / norm) * CUSHIONSPEED);
		}
	}

	void Update() {

		MoveAnywhere();

		Enemy::Update();

	}
};
