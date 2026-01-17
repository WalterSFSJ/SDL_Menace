#include "Biotitan.h"
#include "Spawner.h"
void Biotitan::Shoot() {

	currentTime += TIME.GetDeltaTime();

	if (currentTime < shootingTime)
		return;
	int projectiles = rand() % 5 + 3;

	for (int i = 0; i < projectiles; i++)
	{
		SPAWNER.SpawnObject(new Projectile(Vector2(RM->WINDOW_WIDTH - 100, rand() % RM->WINDOW_HEIGHT / 2), this, 7, -1));
	}

	currentTime = 0.0f;
}