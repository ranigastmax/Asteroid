#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
class AnimatedAsset :
    public sf::Sprite
{
protected:
    float speedX;
    float speedY;
    float accX;
    float accY;
    sf::Clock clock;
    int i = 0;
    std::vector<sf::IntRect> animations;
public:
    void loadTexture(std::string path, sf::Texture& textureName);
    void ContinousAnimation();

   
};

