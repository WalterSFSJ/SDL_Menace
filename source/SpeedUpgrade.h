#include "Spawner.h"
#include "PowerUp.h"

class SpeedUpgrade : public PowerUp
{
public:
    float upgrade = 0.2;

    SpeedUpgrade(Vector2 position)
        :PowerUp(position, "resources/images/horizontal.png", Vector2(1000.f, 1054.f))
    {
        is_powerUp = 4;
    }

    void PowerUpEfect() override;
};