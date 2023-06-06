#include "Coin.h"

void Coin::speed()
{
	speedX = 0;
	speedY = 0;

}

void Coin::acceleration()
{
	accX = 0;
	accY = 0;

}

void Coin::IntRectAnimations()
{
	this->animations.emplace_back(3,4,34,33);
	this->animations.emplace_back(41,4,31,35);
	this->animations.emplace_back(79,5,17,33);
	this->animations.emplace_back(41,46,17,34);
}

Coin::Coin()
{
	IntRectAnimations();
	setTextureRect(sf::IntRect(3, 4, 34, 33));
}
