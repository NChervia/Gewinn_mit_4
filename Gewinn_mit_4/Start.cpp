#include "Start.h"

void Start::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(425, 400), "Gewinn mit 4", sf::Style::Close | sf::Style::Titlebar);
}

void Start::initVariables()
{
}

void Start::initSprite()
{
	this->Screen.setTexture(this->MenuTexture);
	this->Screen.setPosition(0.f, 0.f);
	this->Screen.scale(0.2f, 0.2f);
	
	this->firstButton.setTexture(this->ButtonTexture);
	this->firstButton.setColor(sf::Color(128, 128, 128, 128));
	this->firstButton.setPosition(88.f, 126.f);
	this->firstButton.scale(0.2f, 0.2f);

	this->secondButton.setTexture(this->ButtonTexture);
	this->secondButton.setColor(sf::Color(128, 128, 128, 128));
	this->secondButton.setPosition(88.f, 197.f);
	this->secondButton.scale(0.2f, 0.2f);

	
	this->thirdButton.setTexture(this->ButtonTexture);
	this->thirdButton.setColor(sf::Color(128, 128, 128, 128));
	this->thirdButton.setPosition(88.f, 273.f);
	this->thirdButton.scale(0.2f, 0.2f);
}

void Start::initTexture()
{
	if (!this->MenuTexture.loadFromFile("Texture/Menu start.png"))   std::cout << "Error Texture Menu start.png\n";
	if (!this->ButtonTexture.loadFromFile("Texture/Button.png"))     std::cout << "Error Texture Button.png\n";
}

void Start::initFonts()
{
	if (!this->inkFree.loadFromFile("Fonts/inkfree.ttf"))   std::cout << "Error Font inkfree.ttf\n";
	
}

void Start::initText()
{
	
	this->secondButtonText;
	this->thirdButtonText;


	this->firstButtonText.setFont(this->inkFree);
	this->firstButtonText.setFillColor(sf::Color::Black);
	this->firstButtonText.setCharacterSize(52);
	this->firstButtonText.setPosition(150.f, 120.f);
	this->firstButtonText.setOutlineThickness(1.f);
	this->firstButtonText.setOutlineColor(sf::Color::White);
	this->firstButtonText.setString("Start");

	this->secondButtonText.setFont(this->inkFree);
	this->secondButtonText.setFillColor(sf::Color::Black);
	this->secondButtonText.setCharacterSize(52);
	this->secondButtonText.setPosition(140.f, 188.f);
	this->secondButtonText.setOutlineThickness(1.f);
	this->secondButtonText.setOutlineColor(sf::Color::White);
	this->secondButtonText.setString("Option");

	this->thirdButtonText.setFont(this->inkFree);
	this->thirdButtonText.setFillColor(sf::Color::Black);
	this->thirdButtonText.setCharacterSize(52);
	this->thirdButtonText.setPosition(170.f, 265.f);
	this->thirdButtonText.setOutlineThickness(1.f);
	this->thirdButtonText.setOutlineColor(sf::Color::White);
	this->thirdButtonText.setString("Exit");


}

Start::Start()
{
	this->initVariables();
	this->initWindow();
	this->initTexture();
	this->initFonts();
	this->initText();
	this->initSprite();
}

Start::~Start()
{
	delete this->window;
}

void Start::pollEvents()
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

void Start::updateMousePositions()
{
}

void Start::mousePress()
{
}

void Start::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Start::update()
{
	this->pollEvents();
	this->updateMousePositions();
	this->mousePress();
}

void Start::render()
{
	this->window->clear();
	this->window->draw(this->Screen);
	
	this->window->draw(this->firstButton);
	this->window->draw(this->secondButton);
	this->window->draw(this->thirdButton);

	this->window->draw(this->firstButtonText);
	this->window->draw(this->secondButtonText);
	this->window->draw(this->thirdButtonText);
	this->window->display();
}
