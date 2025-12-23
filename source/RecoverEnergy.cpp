#include "RecoverEnergy.h"
#include "Ship.h"

void RecoverEnergy::Update()
{
	RecoverEnergy::PowerUpEfect();
	Object::Update();
}

bool RecoverEnergy::PlayerColicion()
{
	return true;
}

void RecoverEnergy::Change()
{
	//Cambiar powerUp cuando recive un disparo
}

void RecoverEnergy::PowerUpEfect()
{
	//recuperar la vida de ship
}