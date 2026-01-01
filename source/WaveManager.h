#pragma once
#include "Spawner.h"
#define WM WaveManager::GetInstance()

#include "../dependencies/xml/rapidxml_iterators.hpp"
#include "../dependencies/xml/rapidxml_utils.hpp"
#include "../dependencies/xml/rapidxml.hpp"
#include "../dependencies/xml/rapidxml_print.hpp"
#include <sstream>

class WaveManager
{
public:
	static WaveManager* GetInstance()
	{
		static WaveManager instance;
		return &instance;
		
	}

	void ReadNextWave() {

		rapidxml::xml_document<> doc;
		std::ifstream file("resources/files/wavesFile.xml");

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

		if (std::stoi(inside_node->value()) == 1)
		{
			SPAWNER.SpawnBubbles(std::stoi(inside_node->next_sibling()->value()));						
		}
		else if (std::stoi(inside_node->value()) == 2)
		{
			SPAWNER.SpawnHorizontalMedusas(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 3)
		{
			SPAWNER.SpawnVerticalMedusas(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 4)
		{
			SPAWNER.SpawnBeholders(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 5)
		{
			SPAWNER.SpawnAmoeba();
		}
		else if (std::stoi(inside_node->value()) == 6)
		{
			SPAWNER.SpawnWhales(std::stoi(inside_node->next_sibling()->value()));
		}
		else if (std::stoi(inside_node->value()) == 7)
		{
			SPAWNER.SpawnChompers();
		}
		else if (std::stoi(inside_node->value()) == 8)
		{
			SPAWNER.SpawnCircler();
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
};


