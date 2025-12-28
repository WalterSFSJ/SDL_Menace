#pragma once
#include "PowerUp.h"

class Turrets : public PowerUp
{
public:
    Turrets() {}

    void Update() override;
    bool PlayerColicion() override; 
    void Change() override;
    void PowerUpEfect() override;
};