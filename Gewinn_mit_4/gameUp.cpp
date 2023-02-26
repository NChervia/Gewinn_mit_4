#include "gameUp.h"

// Initialize the render window
void gameUp::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Gewinn mit 4", sf::Style::Close | sf::Style::Titlebar);
}

// Initialize variables
void gameUp::initVariables()
{
	this->typeGame = 0;
	this->gameStep = 0;
	this->numTextureChipA = 1;
	this->numTextureChipB = 8;
}

// Initialize textures
void gameUp::initTexture()
{
	if (!this->textureGameMap.loadFromFile("Texture/Game_map.png"))   std::cout << "Error Texture Game_map.png\n";
	if (!this->textureScreen.loadFromFile("Texture/Screen.png"))   std::cout << "Error Texture Screen.png\n";
	if (!this->textureChipZero.loadFromFile("Texture/Zero.png"))   std::cout << "Error Texture Zero.png\n";
	
}

// Initialize textures for chips A and B
void gameUp::initTextureChipsAB()
{
	switch (this->numTextureChipA)
	{
	case 1:	if (!this->textureChipA.loadFromFile("Texture/Chip1.png"))   std::cout << "Error Texture Chip1.png\n"; break;
	case 2:	if (!this->textureChipA.loadFromFile("Texture/Chip2.png"))   std::cout << "Error Texture Chip2.png\n"; break;
	case 3:	if (!this->textureChipA.loadFromFile("Texture/Chip3.png"))   std::cout << "Error Texture Chip3.png\n"; break;
	case 4:	if (!this->textureChipA.loadFromFile("Texture/Chip4.png"))   std::cout << "Error Texture Chip4.png\n"; break;
	case 5:	if (!this->textureChipA.loadFromFile("Texture/Chip5.png"))   std::cout << "Error Texture Chip5.png\n"; break;
	case 6:	if (!this->textureChipA.loadFromFile("Texture/Chip6.png"))   std::cout << "Error Texture Chip6.png\n"; break;
	case 7:	if (!this->textureChipA.loadFromFile("Texture/Chip7.png"))   std::cout << "Error Texture Chip7.png\n"; break;
	case 8:	if (!this->textureChipA.loadFromFile("Texture/Chip8.png"))   std::cout << "Error Texture Chip8.png\n"; break;
	case 9:	if (!this->textureChipA.loadFromFile("Texture/Chip9.png"))   std::cout << "Error Texture Chip9.png\n"; break;
	default:if (!this->textureChipA.loadFromFile("Texture/Chip1.png"))   std::cout << "Error Texture Chip1.png\n"; break;
	}

	switch (this->numTextureChipB)
	{
	case 1:	if (!this->textureChipB.loadFromFile("Texture/Chip1.png"))   std::cout << "Error Texture Chip1.png\n"; break;
	case 2:	if (!this->textureChipB.loadFromFile("Texture/Chip2.png"))   std::cout << "Error Texture Chip2.png\n"; break;
	case 3:	if (!this->textureChipB.loadFromFile("Texture/Chip3.png"))   std::cout << "Error Texture Chip3.png\n"; break;
	case 4:	if (!this->textureChipB.loadFromFile("Texture/Chip4.png"))   std::cout << "Error Texture Chip4.png\n"; break;
	case 5:	if (!this->textureChipB.loadFromFile("Texture/Chip5.png"))   std::cout << "Error Texture Chip5.png\n"; break;
	case 6:	if (!this->textureChipB.loadFromFile("Texture/Chip6.png"))   std::cout << "Error Texture Chip6.png\n"; break;
	case 7:	if (!this->textureChipB.loadFromFile("Texture/Chip7.png"))   std::cout << "Error Texture Chip7.png\n"; break;
	case 8:	if (!this->textureChipB.loadFromFile("Texture/Chip8.png"))   std::cout << "Error Texture Chip8.png\n"; break;
	case 9:	if (!this->textureChipB.loadFromFile("Texture/Chip9.png"))   std::cout << "Error Texture Chip9.png\n"; break;
	default: if (!this->textureChipB.loadFromFile("Texture/Chip8.png"))   std::cout << "Error Texture Chip8.png\n"; break;
	}
}

// Initialize sprites
void gameUp::initSprite()
{

	this->Screen.setTexture(this->textureScreen);
	this->Screen.setPosition(0.f, 0.f);

	this->gameMap.setTexture(this->textureGameMap);
	this->gameMap.setPosition(0.f, 0.f);
	this->gameMap.scale(0.775f, 0.77f);

	this->gameChip.setTexture(this->textureChipZero);
	this->gameChip.setPosition(0.0f, 0.0f);
	this->gameChip.scale(0.296f, 0.296f);


}

// Initialize fonts
void gameUp::initFonts()
{
	if (!this->inkFree.loadFromFile("Fonts/inkfree.ttf"))std::cout << "Error Font inkfree.ttf\n";

}

// Initialize texts
void gameUp::initText()
{
	this->guiText.setFont(this->inkFree);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(100);
	this->guiText.setPosition(200.f, 00.f);
	this->guiText.setOutlineThickness(1.f);
	this->guiText.setOutlineColor(sf::Color::White);
	this->guiText.setString(" ");
}

// Initialize chips coordinates
void gameUp::initChipsCoor()
{
	int num = 0;
	float posY = 10;
	float posX = 10;
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 7; y++)
		{

			this->ChipsCoor[num][0] = posX;
			this->ChipsCoor[num][1] = posY;
			num++;

			posX += 113;
		}
		posY += 109;
		posX = 10;
	}
}

// Initialize a vector of sprites. Chips on the game map
void gameUp::initGameMapChips()
{
	for (int y = 0; y < 49; y++)
	{
		this->gameChip.setPosition(this->ChipsCoor[y][0], this->ChipsCoor[y][1]);
		this->gameMapChips.push_back(this->gameChip);
	}
	for (int y = 0; y < 7; y++)
	{
		this->gameMapChips[y].setTexture(this->textureChipZero);
	}
}

gameUp::gameUp()
{
	this->initWindow();		// Initialize the render window
	this->initVariables();	// Initialize variables
	this->initTexture();		// Initialize textures
	this->initTextureChipsAB(); // Initialize textures for chips A and B
	this->initSprite();		// Initialize sprites
	this->initFonts();		// Initialize fonts
	this->initText();		// Initialize texts
	this->initChipsCoor();   // Initialize chips coordinates
	this->initGameMapChips();// Initialize a vector of sprites. Chips on the game map
}

gameUp::~gameUp()
{
delete this->window;
}

// Update global mouse position data
void gameUp::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

//Update game map from GameSTD class
void gameUp::UpdateGameMap()
{
	int num = 7;
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 7; y++)
		{

			if (this->GameSTD.getMap(x, y) == '*')
			{
				this->gameMapChips[num].setTexture(this->textureChipZero);
			}
			else if (this->GameSTD.getMap(x, y) == 'X')
			{
				this->gameMapChips[num].setTexture(this->textureChipB);
				this->gameMapChips[num].setColor(sf::Color::White);
			}
			else if (this->GameSTD.getMap(x, y) == 'O')
			{
				this->gameMapChips[num].setTexture(this->textureChipA);
				this->gameMapChips[num].setColor(sf::Color::White);
			}
			else if (this->GameSTD.getMap(x, y) == 'x')
			{
				this->gameMapChips[num].setTexture(this->textureChipB);
				this->gameMapChips[num].setColor(sf::Color::Red);
			}
			else if (this->GameSTD.getMap(x, y) == 'y')
			{
				this->gameMapChips[num].setTexture(this->textureChipA);
				this->gameMapChips[num].setColor(sf::Color::Red);
			}
			num++;
		}

	}
}

// Handle mouse touch
void gameUp::mouseTouch()
{
	
	if ((this->mousePosWindow.y > 20) && (this->mousePosWindow.y < 140))
	{
		if (this->gameStep % 2 == 0)this->gameChip.setTexture(this->textureChipB);
		else this->gameChip.setTexture(this->textureChipA);
		if (this->mousePosWindow.x > 678)this->gameChip.setPosition(688.68f, 50.f);
		else if (this->mousePosWindow.x > 565)this->gameChip.setPosition(575.68f, 50.f);
		else if (this->mousePosWindow.x > 452)this->gameChip.setPosition(462.68f, 50.f);
		else if (this->mousePosWindow.x > 339)this->gameChip.setPosition(349.68f, 50.f);
		else if (this->mousePosWindow.x > 226)this->gameChip.setPosition(236.68f, 50.f);
		else if (this->mousePosWindow.x > 113)this->gameChip.setPosition(123.68f, 50.f);
		else if (this->mousePosWindow.x > 0)this->gameChip.setPosition(10.68f, 50.f);
	}
	else
	{
		this->gameChip.setPosition(800.68f, 800.68f);
	}
}

//Game turn
void gameUp::gameStepFunc()
{
	if (this->gameStep % 2 == 0);

}

// Event handling
void gameUp::pollEvents()
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

// Start the game
void gameUp::run(int TypeGame, int ChipsTextyreNum)
{
	
	this->numTextureChipA = ChipsTextyreNum / 10;
	this->numTextureChipB = ChipsTextyreNum % 10;
	this->initTextureChipsAB();
	this->typeGame = TypeGame;

	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
	
}

// Render game chips
void gameUp::renderGameMapChips(sf::RenderTarget* target)
{
	for (auto i : this->gameMapChips)
	{
		target->draw(i);
	}
}

// Render text
void gameUp::renderText(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

// Updating
void gameUp::update()
{
	this->pollEvents();// Event handling
	this->updateMousePositions(); // Update global mouse position data
	this->UpdateGameMap(); //Update game map from GameSTD class
	this->mouseTouch();	// Handle mouse touch
	this->gameStepFunc(); //Game turn
}

// Rendering
void gameUp::render()
{
	this->window->clear();

	this->window->draw(this->Screen);
	
	this->window->draw(this->gameChip);
	
	this->renderGameMapChips(window);

	this->window->draw(this->gameMap);
	
	this->renderText(window);

	this->window->display();
}

