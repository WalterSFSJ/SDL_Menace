#pragma once
#include <queue>
#include "Object.h"
#include "Bubble.h"
#include "KillerWhale.h"

#define SPAWNER Spawner::Instance()

class Spawner
{
public:
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

	void SpawnBubbles() {
		
		SpawnObject(new Bubble(Vector2(RM->WINDOW_WIDTH, 30)));
		SpawnObject(new Bubble(Vector2(RM->WINDOW_WIDTH + 100, 30)));
		SpawnObject(new Bubble(Vector2(RM->WINDOW_WIDTH + 200, 30)));
		SpawnObject(new Bubble(Vector2(RM->WINDOW_WIDTH + 300, 30)));
	}
	void SpawnWhales() {
		
		SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH, 30), 1));
		SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 600, RM->WINDOW_HEIGHT - 30), -1));
		SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 1200, 30), 1));
		SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 1800, RM->WINDOW_HEIGHT - 30), -1));
	}

private:
	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator=(const Spawner&) = delete;

	std::queue<Object*> _spawnedObjects;
};