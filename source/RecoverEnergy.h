#include "Spawner.h"
#include "PowerUp.h"

class RecoverEnergy : public PowerUp
{
public:
    float upgrade = 0.2;

    RecoverEnergy()
    {

    }

    void Update() override;
    bool PlayerColicion() override;
    void Change() override;
    void PowerUpEfect() override;
};