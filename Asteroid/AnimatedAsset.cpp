#include "AnimatedAsset.h"
void AnimatedAsset::loadTexture(std::string path, sf::Texture& textureName)
{
    if (!textureName.loadFromFile(path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
}

void AnimatedAsset::ContinousAnimation()
{
    /*
    if (clock.getElapsedTime().asSeconds() > 0.33)
    {
        if (i >= animations.size()) {
            i = 0;
        }
        setTextureRect(animations[i]);
        i++;
        clock.restart();
    }
    */
    sf::FloatRect windowBounds(0.f, 0.f, 600.f, 800.f);
    sf::FloatRect objectBounds = getGlobalBounds();

    if (!windowBounds.contains(objectBounds.left, objectBounds.top))
    {
        sf::Vector2f oppositePosition = getPosition();

        if (objectBounds.left < 0.f)
            oppositePosition.x += windowBounds.width;
        else if (objectBounds.left + objectBounds.width > windowBounds.width)
            oppositePosition.x -= windowBounds.width;

        if (objectBounds.top < 0.f)
            oppositePosition.y += windowBounds.height;
        else if (objectBounds.top + objectBounds.height > windowBounds.height)
            oppositePosition.y -= windowBounds.height;

        setPosition(oppositePosition);
    }
}

