#include "Canons.h"

void Canons::Update()
{
	Canons::PowerUpEfect();
	Object::Update();
}

bool Canons::PlayerColicion()
{
	return true;
}

void Canons::Change()
{
	//Cambiar powerUp cuando recive un disparo
}

void Canons::PowerUpEfect()
{
	moreBullets = true;
}