#include "Spawner.h"
#include "PowerUp.h"

class IncrementScore : public PowerUp
{
public:
	const int pointsUpgrade = 1000;

    IncrementScore()
    {
        
    }

    void Update() override;
    bool PlayerColicion() override;
    void Change() override;
    void PowerUpEfect() override;
};