#pragma once
#include "Spawner.h"
#define WM WaveManager::GetInstance()

#include "../dependencies/xml/rapidxml_iterators.hpp"
#include "../dependencies/xml/rapidxml_utils.hpp"
#include "../dependencies/xml/rapidxml.hpp"
#include "../dependencies/xml/rapidxml_print.hpp"
#include <sstream>

enum EnemyType {
	BUBBLE = 1,
	HORIZONTALMED = 2,
	VERTICALMED = 3,
	BEHOLDER = 4,
	AMOEBA = 5,
	WHALE = 6,
	CHOMPER = 7,
	CIRCLER = 8,
	BIOTITAN = 9,
	TORPEDO = 10,
	CHAINSAW = 11,
	KRABS = 12,
	NUKE = 13,
	MISSILE = 14,
	DANIEL = 15,
	UFO = 16,
	ANNOYER = 17,
	ANGRYGONS = 18,
	SPACEBOSS = 19
};

class WaveManager
{
public:
	static WaveManager* GetInstance()
	{
		static WaveManager instance;
		return &instance;
		
	}

	void Reset() {

		waveNumber = 0;
	}

	void SetLevel(int i) {
		level = i;
	}

	void ReadNextWave() {
		std::string fileRoute;
		switch (level)
		{
		case 1:
			fileRoute = "resources/files/wavesFile.xml";
			break;
		case 2:
			fileRoute = "resources/files/wavesFileTwo.xml";
			break;
		default:
			break;
		}

		rapidxml::xml_document<> doc;
		std::ifstream file(fileRoute);

		std::stringstream buffer;

		buffer << file.rdbuf();

		file.close();

		std::string content(buffer.str());

		doc.parse<0>(&content[0]);

		wave_node = doc.first_node()->first_node();
		for (int i = 0; i < waveNumber; i++)
		{
			if (wave_node->next_sibling() != NULL)
				wave_node = wave_node->next_sibling();
		}


		inside_node = wave_node->first_node();

		if (std::stoi(inside_node->value()) == BUBBLE)
		{
			SPAWNER.SpawnBubbles(std::stoi(inside_node->next_sibling()->value()));			
		}
  		else if (std::stoi(inside_node->value()) == HORIZONTALMED)
		{
			SPAWNER.SpawnHorizontalMedusas(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == VERTICALMED)
		{
			SPAWNER.SpawnVerticalMedusas(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == BEHOLDER)
		{
			SPAWNER.SpawnBeholders(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == AMOEBA)
		{
			SPAWNER.SpawnAmoeba();
		}
		else if (std::stoi(inside_node->value()) == WHALE)
		{
			SPAWNER.SpawnWhales(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == CHOMPER)
		{
			SPAWNER.SpawnChompers();
		}
		else if (std::stoi(inside_node->value()) == CIRCLER)
		{
			SPAWNER.SpawnCircler();
		}
		else if (std::stoi(inside_node->value()) == BIOTITAN)
		{
			SPAWNER.SpawnBiotitan();
		}
		else if (std::stoi(inside_node->value()) == TORPEDO)
		{
			SPAWNER.SpawnTorpedos(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == CHAINSAW)
		{
			SPAWNER.SpawnTurboChainsaw(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == KRABS)
		{
			SPAWNER.SpawnKrabs(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == NUKE)
		{
			SPAWNER.SpawnNukes(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == MISSILE)
		{
			SPAWNER.SpawnMissiles(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == DANIEL)
		{
			SPAWNER.SpawnDaniels(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == UFO)
		{
			SPAWNER.SpawnUfo(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == ANNOYER)
		{
			
		}
		else if (std::stoi(inside_node->value()) == ANGRYGONS)
		{
			SPAWNER.SpawnAngygons(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == SPACEBOSS)
		{
			SPAWNER.SpawnSpaceBoss();
		}

		 
		waveMembers = std::stoi(inside_node->next_sibling()->value());
		waveNumber++;
	}

	void EnemyDied() {
	
		waveMembers--;

		CheckAllDead();
	}

private:
	WaveManager() = default;
	WaveManager(WaveManager&) = delete;
	WaveManager& operator=(const WaveManager&) = delete;
	~WaveManager() {}

	int waveMembers = 0;
	int waveNumber = 0;

	rapidxml::xml_node<>* inside_node;
	rapidxml::xml_node<>* wave_node;

	void CheckAllDead() {
		if (waveMembers > 0)
			return;

		ReadNextWave();
	}

	int level;
};


