#include "Rocked.h"

void Rocked::speed()
{
	speedX = 0;
	speedY = 0;
}

void Rocked::acceleration()
{
	accX = 0;
	accY = 0;
}

void Rocked::rotationRocket(sf::RenderWindow* window)
{
	sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));
	sf::Vector2f objectPosition = getPosition();
	sf::Vector2f direction = mousePosition - objectPosition;
	float angle = std::atan2(direction.y, direction.x) * 180.f / static_cast<float>(3.141592);
	setRotation(angle + 90.f);
    
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f acceleration = direction * 0.001f;
        speedX += acceleration.x;
        speedY += acceleration.y;
    }

   
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        accX = 0.f;
        accY = 0.f;
    }

    
    speedX += accX;
    speedY += accY;
    move(speedX, speedY);
}

int Rocked::scores(std::vector<Ater*> ast, std::vector<AnimatedAsset> coin)
{
    for (auto a : ast)
    {
        sf::FloatRect b = a->getGlobalBounds();
        if (getGlobalBounds().intersects(b))
        {
            score--;
        }
    }
    for (auto a : coin)
    {
        sf::FloatRect b = a.getGlobalBounds();
        if (getGlobalBounds().intersects(b))
        {
            score++;
        }
    }
        return score;
}

