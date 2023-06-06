#include "Ater.h"
#include <cstdlib>
#include <ctime>

void Ater::speed()
{
	srand(time(NULL));
	speedX = rand() % 11 - 5;
	srand(time(NULL));
	speedY = rand() % 11 - 5;
	move(speedX, speedY);
}

void Ater::acceleration()
{
	accX = 0;
	accY = 0;

}

void Ater::IntRectAnimations()
{
	this->animations.emplace_back(1, 6, 46, 38);
	this->animations.emplace_back(49, 6, 47, 38);
	this->animations.emplace_back(98, 6, 45, 36);
	this->animations.emplace_back(145, 5, 46, 36);
}

void Ater::m()
{
	move(speedX, speedY);
}

Ater::Ater()
{
	speed();
}
