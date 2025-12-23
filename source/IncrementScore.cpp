#include "IncrementScore.h"

void IncrementScore::Update()
{
	IncrementScore::PowerUpEfect();
	Object::Update;
}

bool IncrementScore::PlayerColicion()
{
	return true;
}

void IncrementScore::Change()
{
	//Cambiar powerUp cuando recive un disparo
}

void IncrementScore::PowerUpEfect()
{
	//Augmentar puntuacion en 1000
}