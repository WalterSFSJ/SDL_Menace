#include "Laser.h"

void Laser::Update()
{
	Laser::PowerUpEfect();
	Object::Update;
}

bool Laser::PlayerColicion()
{
	return true;
}

void Laser::Change()
{
	//Cambiar powerUp cuando recive un disparo
}

void Laser::PowerUpEfect()
{
	moreBullets = true;
}