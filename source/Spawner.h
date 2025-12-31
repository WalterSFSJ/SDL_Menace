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
#include "../dependencies/xml/rapidxml_iterators.hpp"
#include "../dependencies/xml/rapidxml_utils.hpp"
#include "../dependencies/xml/rapidxml.hpp"
#include "../dependencies/xml/rapidxml_print.hpp"
#include <sstream>
#define SPAWNER Spawner::Instance()

class Spawner
{
public:

	rapidxml::xml_node<>* inside_node;
	rapidxml::xml_node<>* wave_node;

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

		for (int i = 0; i < maxEnemies; i += 2)
		{
			SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 600 * i, 30), 1));
			SpawnObject(new KillerWhale(Vector2(RM->WINDOW_WIDTH + 600 * (i+1), RM->WINDOW_HEIGHT - 30), -1));
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
			SpawnObject(new Beholder(100 + i * 100));
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

	void ReadWave() {
	
		rapidxml::xml_document<> doc;
		std::ifstream file("resources/files/wavesFile.xml");

		std::stringstream buffer;

		buffer << file.rdbuf();

		file.close();

		std::string content(buffer.str());

		doc.parse<0>(&content[0]);

		wave_node = doc.first_node()->first_node();
		for (int i = 0; i < timesRead; i++)
		{
			if (wave_node->next_sibling() != NULL)
				wave_node = wave_node->next_sibling();
		}


		inside_node = wave_node->first_node();

		if (std::stoi(inside_node->value()) == 1)
		{
			SpawnBubbles(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 2)
		{
			SpawnHorizontalMedusas(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 3)
		{
			SpawnVerticalMedusas(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 4)
		{
			SpawnBeholders(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 5)
		{
			SpawnAmoeba();
		}
		else if (std::stoi(inside_node->value()) == 6)
		{
			SpawnWhales(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 7)
		{
			SpawnChompers();
		}
		else if (std::stoi(inside_node->value()) == 8)
		{
			SpawnCircler();
		}

		timesRead++;
	}

private:
	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator=(const Spawner&) = delete;

	std::queue<Object*> _spawnedObjects;
};