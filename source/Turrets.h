#pragma once
#include "PowerUp.h"

class Turrets : public PowerUp
{
public:
    Turrets(Vector2 position)
        :PowerUp(position, "resources/images/horizontal.png", Vector2(1000.f, 1054.f))
    {
        is_powerUp = 5;
    }
    void PowerUpEfect() override;
};