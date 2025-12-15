#pragma once
#include "Enemy.h"
#include "TimeManager.h"

class VerticalMedusa : public Enemy
{
public:

	float moveY = 0.01;
	float timeMove = 3.0f; 
	float timePause = 3.0f; 
	float moveTimer = 0.0f; 
    bool isMoving = true;

	VerticalMedusa()
		: Enemy(Vector2(rand()% 1000 + 100, 100 ))
	{

		//GetRigidBody()->SetVelocity(	Vector2(		((float)(rand() % 41) + 10), (float)0		)	);
	}

	void MoveVertical() {

        
        

        if (isMoving) {

			_transform->position.y += moveY;

            if (moveTimer >= timeMove) {
                isMoving = false;
                moveTimer = 0.0f; 
            }
        }
        else {

            if (moveTimer >= timePause) {
                isMoving = true;
                moveTimer = 0.0f; 
            }
        }
	}

	void Update() {

		MoveVertical();

		Enemy::Update();

	}
};
