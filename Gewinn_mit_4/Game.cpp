#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Gewinn mit 4", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initVariables()
{
	this->mousePressBuff = 10;
	this->gameStep = 0;
	this->mouseTouchBuff = 10;
	this->numTextureFirstChip = 0;
	this->numTextureSecondChip = 1;
}

void Game::initTexture()
{
	if (!this->textureGameMap.loadFromFile("Texture/Game_map.png"))   std::cout << "Error Texture Game_map.png\n";
	if (!this->textureScreen.loadFromFile("Texture/Screen.png"))   std::cout << "Error Texture Screen.png\n";

	if (!this->textureGameChipA.loadFromFile("Texture/Zero.png"))   std::cout << "Error Texture Chip1.png\n";
	if (!this->textureGameChipB.loadFromFile("Texture/Zero.png"))   std::cout << "Error Texture Chip2.png\n";
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
	this->gameChipA.setPosition(0.0f, 0.0f);
	this->gameChipA.scale(0.296f, 0.296f);

	this->gameChipB.setTexture(this->textureGameChipB);
	this->gameChipB.setPosition(0.0f, 0.0f);
	this->gameChipB.scale(0.296f, 0.296f);
}

void Game::initFonts()
{
	if (!this->inkFree.loadFromFile("Fonts/inkfree.ttf"))std::cout << "Error Font inkfree.ttf\n";

}

void Game::initText()
{
	this->guiText.setFont(this->inkFree);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(100);
	this->guiText.setPosition(200.f, 00.f);
	this->guiText.setOutlineThickness(1.f);
	this->guiText.setOutlineColor(sf::Color::White);
	this->guiText.setString(" ");
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

void Game::initTextureChipsAB()
{

		if (this->numTextureFirstChip == 0)
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip5.png"))   std::cout << "Error Texture Chip1.png\n";
		}
		else if (this->numTextureFirstChip == 1)
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip1.png"))   std::cout << "Error Texture Chip1.png\n";
		}
		else if (this->numTextureFirstChip == 2)
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip2.png"))   std::cout << "Error Texture Chip2.png\n";
		}
		else if (this->numTextureFirstChip == 3)
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip3.png"))   std::cout << "Error Texture Chip3.png\n";
		}
		else if (this->numTextureFirstChip == 4) 
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip4.png"))   std::cout << "Error Texture Chip4.png\n";
		}
		else if (this->numTextureFirstChip == 5) 
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip5.png"))   std::cout << "Error Texture Chip5.png\n";
		}
		else if (this->numTextureFirstChip == 6) 
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip6.png"))   std::cout << "Error Texture Chip6.png\n";
		}
		else if (this->numTextureFirstChip == 7) 
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip7.png"))   std::cout << "Error Texture Chip7.png\n";
		}
		else if (this->numTextureFirstChip == 8) 
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip8.png"))   std::cout << "Error Texture Chip8.png\n";
		}
		else if (this->numTextureFirstChip == 9) 
		{
			if (!this->textureGameChipA.loadFromFile("Texture/Chip9.png"))   std::cout << "Error Texture Chip9.png\n";
		}
		else std::cout << "Error Texture\n";

		if (this->numTextureSecondChip == 0) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip6.png"))   std::cout << "Error Texture Chip6.png\n";
		}
		else if (this->numTextureSecondChip == 1) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip1.png"))   std::cout << "Error Texture Chip1.png\n";
		}
		else if (this->numTextureSecondChip == 2) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip2.png"))   std::cout << "Error Texture Chip2.png\n";
		}
		else if (this->numTextureSecondChip == 3) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip3.png"))   std::cout << "Error Texture Chip3.png\n";
		}
		else if (this->numTextureSecondChip == 4) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip4.png"))   std::cout << "Error Texture Chip4.png\n";
		}
		else if (this->numTextureSecondChip == 5) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip5.png"))   std::cout << "Error Texture Chip5.png\n";
		}
		else if (this->numTextureSecondChip == 6) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip6.png"))   std::cout << "Error Texture Chip6.png\n";
		}
		else if (this->numTextureSecondChip == 7) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip7.png"))   std::cout << "Error Texture Chip7.png\n";
		}
		else if (this->numTextureSecondChip == 8) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip8.png"))   std::cout << "Error Texture Chip8.png\n";
		}
		else if (this->numTextureSecondChip == 9) 
		{
			if (!this->textureGameChipB.loadFromFile("Texture/Chip9.png"))   std::cout << "Error Texture Chip9.png\n";
		}
		else std::cout << "Error Texture\n";

	
		this->textureGameChipB.setSrgb(true);
		this->textureGameChipA.setSrgb(false);
		if ((this->numTextureSecondChip == this->numTextureFirstChip) && (this->numTextureFirstChip != 0))
	{
		this->gameChipA.setColor(sf::Color(0, 255, 255, 255));
		this->gameChipB.setColor(sf::Color(255, 255, 0, 255));
		
	}
	else
	{
		this->gameChipA.setColor(sf::Color::White);
		this->gameChipB.setColor(sf::Color::White);
	}
}

Game::Game()
{
	this->initVariables();
	this->initTexture();
	this->initFonts();
	this->initText();
	this->initSprite();
	this->initChipsXY();
	this->initGameMapChips();
}

Game::~Game()
{
	//delete this->window;
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	
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
				this->gameMapChips[num].setColor(sf::Color::White);
			}
			else if (this->GameSTD.getMap(x, y) == 'O')
			{
			this->gameMapChips[num].setTexture(this->textureGameChipA);
			this->gameMapChips[num].setColor(sf::Color::White);
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
	this->updateMousePositions();

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
			int tempNum=10;
			if (this->mousePosWindow.x > 678)    tempNum = 6;
			else if (this->mousePosWindow.x > 565)tempNum = 5;
			else if (this->mousePosWindow.x > 452)tempNum = 4;
			else if (this->mousePosWindow.x > 339)tempNum = 3;
			else if (this->mousePosWindow.x > 226)tempNum = 2;
			else if (this->mousePosWindow.x > 113)tempNum = 1;
			else if (this->mousePosWindow.x > 0)  tempNum = 0;
			
			this->mouseTouchBuff = tempNum;
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
		this->mouseTouchBuff = 10;
		if (this->GameSTD.testFull())this->FinishFunc();
	}
}

void Game::FinishFunc()
{
	this->guiText.setString("Finish!");
	this->gameStep = 100;
}


void Game::renderText(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}


void Game::renderGameMapChips(sf::RenderTarget* target)
{
	for (auto i : this->gameMapChips)
	{
		target->draw(i);
	}
}

void Game::run(int TypeGame, int ChipsTextyreNum)
{
	this->initWindow();
	this->numTextureFirstChip = ChipsTextyreNum/10;
	this->numTextureSecondChip = ChipsTextyreNum%10;
	std::cout << "ChipsTextyreNum-" << ChipsTextyreNum << std::endl;
	std::cout << "numTextureFirstChip-" << this->numTextureFirstChip << std::endl;
	std::cout << "numTextureSecondChip-" << this->numTextureSecondChip << std::endl;
	this->initTextureChipsAB();
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
	this->guiText.setString(" ");
	this->gameStep = 0;
	this->GameSTD.newmap();
	delete this->window;
}

void Game::update()
{
	this->pollEvents();
	this->updateMousePositions();
	this->mouseTouch();
	if (this->gameStep < 100) this->mousePress();
	this->updateGameMapChips();
	this->shotGame();
}

void Game::render()
{
	this->window->clear();

	this->window->draw(this->Screen);
	this->renderGameMapChips(window);

	this->window->draw(this->gameChipB);
	this->window->draw(this->gameMap);
	this->renderText(window);
	this->window->display();
}
