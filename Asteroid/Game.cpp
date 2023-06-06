#include "Game.h"

//private



void Game::initializeViriables()
{
	this->window = nullptr;
}
void Game::initializeWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "lab_9_psio");
	this->window->setFramerateLimit(90);
}


Game::Game()
{

	this->initializeViriables();
	this->initializeWindow();
	coin1.loadTexture("textures/coin.png", tc);
	coin2.loadTexture("textures/coin.png", tc);
	rocked.loadTexture("textures/rocket.png", tr);
	coin1.setPosition(rand() % 600+100, rand() % 600);
	coin2.setPosition(rand() % 500+100, rand() % 650);
	coin1.setTexture(tc);
	coin2.setTexture(tc);
	rocked.setTexture(tr);
	rocked.setPosition(400, 400);
	srand(time(NULL));
	if (!font.loadFromFile("textures/Arial.ttf")) {
		std::cerr << "Could not load font" << std::endl;
	}
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(10, 10);

	for (int i = 0; i < rand() % 10 + 5; i++)
	{
		Ater* aster = new Ater;
		aster->setTexture(ta);
		aster->setPosition(rand() % 600, i * 50);
		int randInt = rand() % 51 + 30; 
		float randomNum = static_cast<float>(randInt) / 100.0f;
		aster->scale(randomNum, randomNum);
		aster->loadTexture("textures/aster.png",ta);
		asteroids.push_back(aster);
	}
	coins.push_back(coin1);
	coins.push_back(coin2);
	rocked.scale(0.5, 0.5);
	speedX = rand() % 11 - 5;
	speedY = rand() % 11 - 5;
}


Game::~Game()
{
	delete this->window;

}



const bool Game::running() const
{
	return this->window->isOpen();
}
//public



void Game::updateEvents()
{
	while (this->window->pollEvent(this->ev))
	{

		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		}
	}
	rocked.rotationRocket(window);
	coin1.ContinousAnimation();
	coin2.ContinousAnimation();
	for (auto a : asteroids)
	{
		a->move(rand() % 11 - 5, rand() % 11 - 5);
		a->ContinousAnimation();
	}

}


void Game::render()
{
	//visualasions renders the game obj
	this->window->clear();
	//-----------------------------
	window->draw(rocked);
	for (auto b : asteroids)
	{
		window->draw(*b);
	}
	window->draw(coin1);
	window->draw(coin2);
	window->draw(text);
	this->window->display();
}

void Game::update()
{
	//there is game
	text.setString(std::to_string(rocked.scores(asteroids,coins)));
	this->updateEvents();


}
