#pragma once
#include "Spawner.h"

class Rounds
{
public:

    void Reset() { _currentRound = 1; }

    void NextRound() {
        SpawnRound(_currentRound);
        _currentRound++;
    }

    void SpawnRound(int roundNumber) {

        SPAWNER.ClearSpawner();

        switch (roundNumber) {
        case 1:
            SPAWNER.SpawnBubbles();
            break;
        case 2:
            SPAWNER.SpawnWhales();
            break;
        case 3:
            SPAWNER.SpawnHorizontalMedusas();
            break;
        case 4:
            SPAWNER.SpawnVerticalMedusas();
            SPAWNER.SpawnBubbles(); 
            break;
        case 5:
            SPAWNER.SpawnBeholders();
            break;
        }
    }

    int GetCurrentRound() const { return _currentRound; }

private:
    Rounds() : _currentRound(1) {}
    int _currentRound;
};