#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(675, 675), "Game Life", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initVariables()
{

}

void Game::initSprite()
{
}

void Game::initTexture()
{
}

void Game::initFonts()
{
}

void Game::initText()
{
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTexture();
	this->initFonts();
	this->initText();
	this->initSprite();
}

Game::~Game()
{
	delete this->window;
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{

		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		}
	}
}


int Game::mousePress()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int pozition = 10;

		if ((this->mousePosWindow.x > 110) && (this->mousePosWindow.x < 235))      pozition = 0;
		else if ((this->mousePosWindow.x > 285) && (this->mousePosWindow.x < 410)) pozition = 1;  //Y
		else if ((this->mousePosWindow.x > 450) && (this->mousePosWindow.x < 575)) pozition = 2;
		else return 10;

		if ((this->mousePosWindow.y > 90) && (this->mousePosWindow.y < 235))        pozition += 0;
		else if ((this->mousePosWindow.y > 270) && (this->mousePosWindow.y < 415))  pozition += 3; //X
		else if ((this->mousePosWindow.y > 445) && (this->mousePosWindow.y < 590))  pozition += 6;
		else return 10;




	}
	return 10;
}




void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::update()
{
	this->pollEvents();
	this->updateMousePositions();
	this->mousePress();


}

void Game::render()
{

	this->window->clear();
	//this->renderSprite(this->window);
	this->window->display();
}
