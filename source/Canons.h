#include "Spawner.h"
#include "PowerUp.h"

class Canons : public PowerUp
{
public:
    bool moreBullets = false;

    Canons()
    {

    }

    void Update() override;
    bool PlayerColicion() override;
    void Change() override;
    void PowerUpEfect() override;
};