#include "Spawner.h"
#include "PowerUp.h"

class Canons : public PowerUp
{
public:
    bool moreBullets = false;

    Canons(Vector2 position)
        :PowerUp(position, "resources/images/horizontal.png", Vector2(1000.f, 1054.f))
    {
        is_powerUp = 2;
    }
    void PowerUpEfect() override;
};