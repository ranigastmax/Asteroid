#pragma once
#include"AnimatedAsset.h"
#include<math.h>
#include"Ater.h"
class Rocked :
    public AnimatedAsset
{
    int score;

public:
    void speed();
    void acceleration();
    void rotationRocket(sf::RenderWindow* window);
    int scores(std::vector<Ater*> ast, std::vector<AnimatedAsset> coin);
};

