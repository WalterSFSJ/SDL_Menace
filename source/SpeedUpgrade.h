#include "Spawner.h"
#include "PowerUp.h"

class SpeedUpgrade : public PowerUp
{
public:
    float upgrade = 0.2;

    SpeedUpgrade()
    {

    }

    void Update() override;
    bool PlayerColicion() override;
    void Change() override;
    void PowerUpEfect() override;
};