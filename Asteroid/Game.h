#pragma once

#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"Ater.h"
#include"Coin.h"
#include"Rocked.h"
class Game
{
	//class that act as game engine


	//objects
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	Coin coin1;
	Coin coin2;
	std::vector<Ater*> asteroids;
	Rocked rocked;
	sf::Texture tr;
	sf::Texture tc;
	sf::Texture ta;
	sf::Font font;
	sf::Text text;
	int score=0;
	std::vector<AnimatedAsset> coins;
	int speedX;
	int speedY;









	void initializeViriables();
	void initializeWindow();



public:

	Game();
	virtual ~Game();

	const bool running() const;

	void updateEvents();
	void render();
	void update();

};

