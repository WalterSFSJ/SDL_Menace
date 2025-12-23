#include "SpeedUpgrade.h"
#include "Ship.h"

void SpeedUpgrade::Update()
{
	SpeedUpgrade::PowerUpEfect();
	Object::Update;
}

bool SpeedUpgrade::PlayerColicion()
{
	return true;
}

void SpeedUpgrade::Change()
{
	//Cambiar powerUp cuando recive un disparo
}

void SpeedUpgrade::PowerUpEfect()
{
	//augmentar velocidad de ship
}