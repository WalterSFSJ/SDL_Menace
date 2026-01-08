#include "Spawner.h"
#include "PowerUp.h"

class Laser : public PowerUp
{
public:
    bool moreBullets = false;

    Laser(Vector2 position)
        :PowerUp(position, "resources/images/horizontal.png", Vector2(1000.f, 1054.f))
    {
        is_powerUp = 1;
    }

    void PowerUpEfect() override;
};