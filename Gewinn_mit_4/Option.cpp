#include "Option.h"

void Option::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Option", sf::Style::Close | sf::Style::Titlebar);
}

void Option::initVariables()
{
	this->mousePressBool = true;
	this->choisChipNum = 0;
	this->numTextureFirstChip = 0;
	this->numTextureSecondChip = 0;
	this->ChipAB = true;
}

void Option::initSprite()
{
	this->Screen.setTexture(this->textureScreen);
	this->Screen.setPosition(0.f, 0.f);


	this->ChoisChip.setTexture(this->textureChips);
	this->ChoisChip.setPosition(150.f, 250.f);
	this->ChoisChip.scale(0.5f, 0.5f);

	this->firstChip.setTexture(this->textureChip1);
	this->firstChip.setPosition(100.0f, 20.0f);
	this->firstChip.scale(0.4f, 0.4f);

	this->secondChip.setTexture(this->textureChip1);
	this->secondChip.setPosition(520.0f, 20.0f);
	this->secondChip.scale(0.4f, 0.4f);


}

void Option::initTexture()
{
	if (!this->textureScreen.loadFromFile("Texture/Screen.png"))   std::cout << "Error Texture Screen.png\n";
	if (!this->textureChips.loadFromFile("Texture/Chips.png"))   std::cout << "Error Texture Chips.png\n";

	if (!this->textureChip1.loadFromFile("Texture/Chip1.png"))   std::cout << "Error Texture Chip1.png\n";
	if (!this->textureChip2.loadFromFile("Texture/Chip2.png"))   std::cout << "Error Texture Chip2.png\n";
	if (!this->textureChip3.loadFromFile("Texture/Chip3.png"))   std::cout << "Error Texture Chip3.png\n";
	if (!this->textureChip4.loadFromFile("Texture/Chip4.png"))   std::cout << "Error Texture Chip4.png\n";
	if (!this->textureChip5.loadFromFile("Texture/Chip5.png"))   std::cout << "Error Texture Chip5.png\n";
	if (!this->textureChip6.loadFromFile("Texture/Chip6.png"))   std::cout << "Error Texture Chip6.png\n";
	if (!this->textureChip7.loadFromFile("Texture/Chip7.png"))   std::cout << "Error Texture Chip7.png\n";
	if (!this->textureChip8.loadFromFile("Texture/Chip8.png"))   std::cout << "Error Texture Chip8.png\n";
	if (!this->textureChip9.loadFromFile("Texture/Chip9.png"))   std::cout << "Error Texture Chip9.png\n";

	if (!this->textureChipZero.loadFromFile("Texture/Zero.png"))   std::cout << "Error Texture Zero.png\n";


	
}

void Option::initFonts()
{
	if (!this->inkFree.loadFromFile("Fonts/inkfree.ttf"))   std::cout << "Error Font inkfree.ttf\n";

}

void Option::initText()
{
	this->textFirstChip.setFont(this->inkFree);
	this->textFirstChip.setFillColor(sf::Color::Black);
	this->textFirstChip.setCharacterSize(52);
	this->textFirstChip.setPosition(70.f, 150.f);
	this->textFirstChip.setOutlineThickness(1.f);
	this->textFirstChip.setOutlineColor(sf::Color::White);
	this->textFirstChip.setString("First Chip");

	this->textSecondChip.setFont(this->inkFree);
	this->textSecondChip.setFillColor(sf::Color::Black);
	this->textSecondChip.setCharacterSize(52);
	this->textSecondChip.setPosition(470.f, 150.f);
	this->textSecondChip.setOutlineThickness(1.f);
	this->textSecondChip.setOutlineColor(sf::Color::White);
	this->textSecondChip.setString("SecondChip");
}

Option::Option()
{
	this->initVariables();
	this->initTexture();
	this->initFonts();
	this->initText();
	this->initSprite();
}

Option::~Option()
{

}

void Option::pollEvents()
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

void Option::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);


}

int Option::mouseDetect()
{
	int pozition = 0;
	if ((this->mousePosWindow.x > 160) && (this->mousePosWindow.x < 310))      pozition = 1;
	else if ((this->mousePosWindow.x > 320) && (this->mousePosWindow.x < 475)) pozition = 2;  //Y
	else if ((this->mousePosWindow.x > 485) && (this->mousePosWindow.x < 640)) pozition = 3;
	else return 0;

	if ((this->mousePosWindow.y > 260) && (this->mousePosWindow.y < 410))        pozition += 0;
	else if ((this->mousePosWindow.y > 425) && (this->mousePosWindow.y < 575))  pozition += 3; //X
	else if ((this->mousePosWindow.y > 590) && (this->mousePosWindow.y < 745))  pozition += 6;
	else return 0;

	return pozition;
}

void Option::mousePress()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int pozition = this->mouseDetect();
		if ((this->mousePressBool == true)&&(pozition != 0))
		{
			this->mousePressBool = false;
			if (this->ChipAB == true)
			{
				this->ChipAB = false;
				this->numTextureFirstChip = pozition;
			}
			else
			{
				this->ChipAB = true;
				this->numTextureSecondChip = pozition;
			}
		}
	}
	else
	{
		this->mousePressBool = true;
	}
}

void Option::mouseTouch()
{
	this->ChageTextures(this->mouseDetect());

}

void Option::ChageTextures(int num)
{
	int ChipA = num;
	int ChipB = num;

	if (this->numTextureFirstChip != 0)ChipA = this->numTextureFirstChip;
	if (ChipA == 0)this->firstChip.setTexture(this->textureChipZero);
	else if (ChipA == 1)this->firstChip.setTexture(this->textureChip1);
	else if (ChipA == 2)this->firstChip.setTexture(this->textureChip2);
	else if (ChipA == 3)this->firstChip.setTexture(this->textureChip3);
	else if (ChipA == 4)this->firstChip.setTexture(this->textureChip4);
	else if (ChipA == 5)this->firstChip.setTexture(this->textureChip5);
	else if (ChipA == 6)this->firstChip.setTexture(this->textureChip6);
	else if (ChipA == 7)this->firstChip.setTexture(this->textureChip7);
	else if (ChipA == 8)this->firstChip.setTexture(this->textureChip8);
	else if (ChipA == 9)this->firstChip.setTexture(this->textureChip9);

	if (this->numTextureSecondChip != 0)ChipB = this->numTextureSecondChip;
	if (ChipB == 0)this->secondChip.setTexture(this->textureChipZero);
	else if (ChipB == 1)this->secondChip.setTexture(this->textureChip1);
	else if (ChipB == 2)this->secondChip.setTexture(this->textureChip2);
	else if (ChipB == 3)this->secondChip.setTexture(this->textureChip3);
	else if (ChipB == 4)this->secondChip.setTexture(this->textureChip4);
	else if (ChipB == 5)this->secondChip.setTexture(this->textureChip5);
	else if (ChipB == 6)this->secondChip.setTexture(this->textureChip6);
	else if (ChipB == 7)this->secondChip.setTexture(this->textureChip7);
	else if (ChipB == 8)this->secondChip.setTexture(this->textureChip8);
	else if (ChipB == 9)this->secondChip.setTexture(this->textureChip9);
	
	if ((this->numTextureSecondChip == this->numTextureFirstChip) && (this->numTextureFirstChip != 0))
	{
		this->firstChip.setColor(sf::Color(0, 255, 255, 255));
		this->secondChip.setColor(sf::Color(255, 255, 0, 255));
	}
	else
	{
		this->firstChip.setColor(sf::Color::White);
		this->secondChip.setColor(sf::Color::White);
	}
}





int Option::run()
{
	this->initWindow();
	this->initVariables();
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
	delete this->window;

	int ret = this->numTextureFirstChip * 10;
	ret += this->numTextureSecondChip;
	std::cout << "X-" << ret << std::endl;
	return ret;
}

void Option::update()
{
	this->pollEvents();
	this->updateMousePositions();
	this->mousePress();
	this->mouseTouch();
}

void Option::render()
{
	this->window->clear();
	this->window->draw(this->Screen);
	this->window->draw(this->ChoisChip);
	
	this->window->draw(this->textFirstChip);
	this->window->draw(this->textSecondChip);

	this->window->draw(this->firstChip);
	this->window->draw(this->secondChip);
	
	this->renderButtons(this->window);
	this->window->display();
}

void Option::renderButtons(sf::RenderTarget* target)
{

}

