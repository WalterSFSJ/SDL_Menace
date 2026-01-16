#pragma once
#include <queue>
#include "Object.h"
#include "Bubble.h"
#include "KillerWhale.h"
#include "HorizontalMedusa.h"
#include "VerticalMedusa.h"
#include "Beholder.h"
#include "Amoeba.h"
#include "KillerWhale.h"
#include "Chomper.h"
#include "Circler.h"
#include "CirclerProjectile.h"
#include "Biotitan.h"

#define SPAWNER Spawner::Instance()

class Spawner
{
public:

	int timesRead = 0;

	static Spawner& Instance() {
		static Spawner spawner;
		return spawner;		
	}

	void SpawnObject(Object* obj) { _spawnedObjects.push(obj); }
	bool AreObjectsPendingSpawn() { return !_spawnedObjects.empty(); }

	Object* GetSpawnedObject() {   //hace spawn de la queue
		if (!AreObjectsPendingSpawn())
			return nullptr;

		Object* temp = _spawnedObjects.front();
		_spawnedObjects.pop();
		return temp;
	}

	void ClearSpawner() {
		while (AreObjectsPendingSpawn()) {
			delete _spawnedObjects.front();
			_spawnedObjects.pop();
		}

	}

	void SpawnBubbles(int maxEnemies) {

		for (int i = 0; i < maxEnemies; i++)
		{
			SpawnObject(new Bubble(Vector2(RM->WINDOW_WIDTH + 100 * i, 100)));
		}
	}
	void SpawnWhales(int maxEnemies) {

		float pauseTime = 1.5f;

		for (int i = 0; i < maxEnemies; i ++)
		{
			SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 100, 30), 1, i * pauseTime));
			
			i++;
			
			SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 100, RM->WINDOW_HEIGHT - 30), -1, i * pauseTime));
		}

		
	}
	
	void SpawnAmoeba() {

		for (int i = 0; i < 8; i++)
		{
			SpawnObject(new Amoeba(i));

		}
	}
	
	void SpawnHorizontalMedusas(int maxEnemies) {

		for (int i = 0; i < maxEnemies; i++)
		{
			SpawnObject(new HorizontalMedusa());

		}
	}
	
	void SpawnVerticalMedusas(int maxEnemies) {

		for (int i = 0; i < maxEnemies; i++)
		{
			SpawnObject(new VerticalMedusa());

		}
	}
	
	void SpawnBeholders(int maxEnemies) {

		for (int i = 0; i < maxEnemies; i++)
		{
			Beholder* b = new Beholder(100 + i * 100);
			
			SpawnObject(b);
		}
	}
	
	void SpawnChompers() {

		for (int i = 0; i < 7; i++)
		{
			SpawnObject(new Chomper(40 + i * 100));
		}
	}
	
	void SpawnCircler() {
		
		Circler* circler = new Circler();

		for (int i = 0; i < 10; i++)
		{
			CirclerProjectile* cp = new CirclerProjectile(circler->GivePosition(), circler, circler->GiveSpeed(), 1);
			circler->BindProjectile(cp);
			SpawnObject(cp);
		}

		SpawnObject(circler);

	}

	void SpawnBiotitan() {

		

		SpawnObject(new Biotitan());
		
	}


	std::queue<Object*> GetSpawnedObjects() {
		return _spawnedObjects;
	}

private:
	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator=(const Spawner&) = delete;

	std::queue<Object*> _spawnedObjects;
};