#pragma once
#include <queue>
#include "Object.h"
#include "Bubble.h"
#include "KillerWhale.h"
#include "HorizontalMedusa.h"
#include "VerticalMedusa.h"
#include "Beholder.h"
#include "../dependencies/xml/rapidxml_iterators.hpp"
#include "../dependencies/xml/rapidxml_utils.hpp"
#include "../dependencies/xml/rapidxml.hpp"
#include "../dependencies/xml/rapidxml_print.hpp"
#include <sstream>
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

	void SpawnBubbles(int maxEnemies) {

		for (int i = 0; i < maxEnemies; i++)
		{
			SpawnObject(new Bubble(Vector2(RM->WINDOW_WIDTH + 100 * i, 100)));
		}
	}
	void SpawnWhales(int maxEnemies) {

		for (int i = 0; i < maxEnemies; i++)
		{
			SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 600 * i, 30), 1));
			SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 600 * (i+1), RM->WINDOW_HEIGHT - 30), -1));
		}

		/*SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH, 30), 1));
		SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 600, RM->WINDOW_HEIGHT - 30), -1));
		SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 1200, 30), 1));
		SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 1800, RM->WINDOW_HEIGHT - 30), -1));*/
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
			SpawnObject(new Beholder(100 + i * 100));
		}
	}


	void ReadWave() {
	
		rapidxml::xml_document<> doc;
		std::ifstream file("resources/files/wavesFile.xml");

		std::stringstream buffer;

		buffer << file.rdbuf();

		file.close();

		std::string content(buffer.str());

		doc.parse<0>(&content[0]);

		std::cout << "Wave: " << doc.first_node()->first_node()->name() << std::endl; //wave 1
		std::cout << doc.first_node()->first_node()->first_node()->name(); //id name
		std::cout << doc.first_node()->first_node()->first_node()->value() << std::endl; //id value
		std::cout << doc.first_node()->first_node()->first_node()->next_sibling()->name(); //amount name
		std::cout << doc.first_node()->first_node()->first_node()->next_sibling()->value() << std::endl; //amount value


		if (std::stoi(doc.first_node()->first_node()->first_node()->value()) == 1)
		{
			SpawnBubbles(std::stoi(doc.first_node()->first_node()->first_node()->next_sibling()->value()));
		}
	
	}

private:
	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator=(const Spawner&) = delete;

	std::queue<Object*> _spawnedObjects;
};