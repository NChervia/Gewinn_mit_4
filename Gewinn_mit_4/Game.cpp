#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Gewinn mit 4", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initVariables()
{
	this->gameStep = 0;
	this->mouseTouchBuff = 10;
}

void Game::initTexture()
{
	if (!this->textureGameMap.loadFromFile("Texture/Game_map.png"))   std::cout << "Error Texture Game_map.png\n";
	if (!this->textureScreen.loadFromFile("Texture/Screen.png"))   std::cout << "Error Texture Screen.png\n";
	if (!this->textureGameChipA.loadFromFile("Texture/ChipA.png"))   std::cout << "Error Texture ChipA.png\n";
	if (!this->textureGameChipB.loadFromFile("Texture/ChipB.png"))   std::cout << "Error Texture ChipB.png\n";
	if (!this->textureGameChipZero.loadFromFile("Texture/Zero.png"))   std::cout << "Error Texture Zero.png\n";
}

void Game::initSprite()
{

	this->Screen.setTexture(this->textureScreen);
	this->Screen.setPosition(0.f, 0.f);

	this->gameMap.setTexture(this->textureGameMap);
	this->gameMap.setPosition(0.f, 0.f);
	this->gameMap.scale(0.775f, 0.77f);
	
	this->gameChipA.setTexture(this->textureGameChipA);
	this->gameChipA.setPosition(235.68f, 446.68f);//50,32
	this->gameChipA.scale(0.296f, 0.296f);


	this->gameChipB.setTexture(this->textureGameChipB);
	this->gameChipB.setPosition(122.68f, 228.68f);
	this->gameChipB.scale(0.296f, 0.296f);

	/*
	this->line_1.setPosition(60.f, 0.f);//+113
	this->line_2.setPosition(173.f, 0.f);
	this->line_3.setPosition(286.f, 0.f);
	this->line_4.setPosition(399.f, 0.f);
	this->line_5.setPosition(512.f, 0.f);
	this->line_6.setPosition(625.f, 0.f);
	this->line_7.setPosition(738.f, 0.f);

	this->line0.setPosition(0.f, 61.f);//+109
	this->line1.setPosition(0.f, 170.f);
	this->line2.setPosition(0.f, 279.f);
	this->line3.setPosition(0.f, 388.f);
	this->line4.setPosition(0.f, 497.f);
	this->line5.setPosition(0.f, 606.f);
	this->line6.setPosition(0.f, 715.f);*/



}

void Game::initFonts()
{
}

void Game::initText()
{
}

void Game::initChipsXY()
{
	int num = 0;
	float posY = 10;
	float posX = 10;
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 7; y++)
		{

			this->chipsXY[num][0] = posX;
			this->chipsXY[num][1] = posY;
			num++;
			
			posX += 113;
		}
		posY += 109;
		posX = 10;
	}
}

void Game::initGameMapChips()
{
	for (int y = 0; y < 49; y++)
	{
		this->gameChipB.setPosition(this->chipsXY[y][0], this->chipsXY[y][1]);
		this->gameMapChips.push_back(gameChipB);
	}
	for (int y = 0; y < 7; y++)
	{
		this->gameMapChips[y].setTexture(this->textureGameChipZero);
	}
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTexture();
	this->initFonts();
	this->initText();
	this->initSprite();
	this->initChipsXY();
	this->initGameMapChips();
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

void Game::updateGameMapChips()
{
	int num = 7;
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			
			if (this->GameSTD.getMap(x, y) == '*')
			{
				this->gameMapChips[num].setTexture(this->textureGameChipZero);
			}
			else if (this->GameSTD.getMap(x, y) == 'X')
			{
				this->gameMapChips[num].setTexture(this->textureGameChipB);
			}
			else if (this->GameSTD.getMap(x, y) == 'O')
			{
			this->gameMapChips[num].setTexture(this->textureGameChipA);
			}
			else if (this->GameSTD.getMap(x, y) == 'x')
			{
				this->gameMapChips[num].setTexture(this->textureGameChipB);
				this->gameMapChips[num].setColor(sf::Color::Red);
			}
			else if (this->GameSTD.getMap(x, y) == 'y')
			{
				this->gameMapChips[num].setTexture(this->textureGameChipA);
				this->gameMapChips[num].setColor(sf::Color::Red);
			}
			num++;
		}
		
	}
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

void Game::mouseTouch()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
	if ((this->mousePosWindow.y > 20) && (this->mousePosWindow.y < 140))
	{
		if (this->gameStep % 2 == 0)this->gameChipB.setTexture(this->textureGameChipB);
		else this->gameChipB.setTexture(this->textureGameChipA);
		if (this->mousePosWindow.x > 678)this->gameChipB.setPosition(688.68f, 50.f);
		else if (this->mousePosWindow.x > 565)this->gameChipB.setPosition(575.68f, 50.f);
		else if (this->mousePosWindow.x > 452)this->gameChipB.setPosition(462.68f, 50.f);
		else if (this->mousePosWindow.x > 339)this->gameChipB.setPosition(349.68f, 50.f);
		else if (this->mousePosWindow.x > 226)this->gameChipB.setPosition(236.68f, 50.f);
		else if (this->mousePosWindow.x > 113)this->gameChipB.setPosition(123.68f, 50.f);
		else if (this->mousePosWindow.x > 0)this->gameChipB.setPosition(10.68f, 50.f);
	}
	else
	{
		this->gameChipB.setPosition(800.68f, 800.68f);
	}
	return;
}


int Game::mousePress()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if ((this->mousePosWindow.y > 20) && (this->mousePosWindow.y < 140) && (this->mousePressBool == false))
		{
			this->mousePressBool = true;
			int num;
			if (this->mousePosWindow.x > 678)    num = 6;
			else if (this->mousePosWindow.x > 565)num = 5;
			else if (this->mousePosWindow.x > 452)num = 4;
			else if (this->mousePosWindow.x > 339)num = 3;
			else if (this->mousePosWindow.x > 226)num = 2;
			else if (this->mousePosWindow.x > 113)num = 1;
			else if (this->mousePosWindow.x > 0)  num = 0;
			
			this->mouseTouchBuff = num;
		}
	}
	else
	{
		this->mousePressBool = false;
	}
	return 10;
}

void Game::shotGame()
{
	if (this->mouseTouchBuff != 10)
	{
		
		if (this->gameStep % 2 == 0)	this->GameSTD.shot('X', this->mouseTouchBuff);
		else this->GameSTD.shot('O', this->mouseTouchBuff);
		this->gameStep++;
		if (this->GameSTD.testFull())std::cout << "finish!";
		this->mouseTouchBuff = 10;
	}
}




void Game::renderGameMapChips(sf::RenderTarget* target)
{
	for (auto i : this->gameMapChips)
	{
		target->draw(i);
	}
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
	this->mouseTouch();
	this->updateGameMapChips();
	this->shotGame();


}

void Game::render()
{

	this->window->clear();

	this->window->draw(this->Screen);
	this->renderGameMapChips(window);
	//this->window->draw(this->gameChipA);
	this->window->draw(this->gameChipB);
	this->window->draw(this->gameMap);
	
	//this->renderSprite(this->window);
	this->window->display();
}
