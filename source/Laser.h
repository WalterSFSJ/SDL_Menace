#include "Spawner.h"
#include "PowerUp.h"

class Laser : public PowerUp
{
public:
    bool moreBullets = false;

    Laser()
    {

    }

    void Update() override;
    bool PlayerColicion() override;
    void Change() override;
    void PowerUpEfect() override;
};