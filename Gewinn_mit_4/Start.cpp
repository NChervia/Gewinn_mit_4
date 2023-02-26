#include "Start.h"

void Start::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(425, 400), "Gewinn mit 4", sf::Style::Close | sf::Style::Titlebar);
}

void Start::initVariables()
{
	this->startLevel = BeginButton;
	this->startLevelBuff = BeginButton;
	this->mousePressBool = true;
	this->outTypeGame = 0;
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
	//this->initWindow();
	this->initTexture();
	this->initFonts();
	this->initText();
	this->initSprite();
}

Start::~Start()
{
	
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
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
	
	if (this->mouseDetect(this->firstButton.getGlobalBounds()))
	{
		this->firstButton.setColor(sf::Color(128, 128, 128, 255));
	}
	else
	{
		this->firstButton.setColor(sf::Color(128, 128, 128, 128));
	}

	if (this->mouseDetect(this->secondButton.getGlobalBounds()))
	{
		this->secondButton.setColor(sf::Color(128, 128, 128, 255));
	}
	else
	{
		this->secondButton.setColor(sf::Color(128, 128, 128, 128));
	}

	if (this->mouseDetect(this->thirdButton.getGlobalBounds()))
	{
		this->thirdButton.setColor(sf::Color(128, 128, 128, 255));
	}
	else
	{
		this->thirdButton.setColor(sf::Color(128, 128, 128, 128));
	}


}

bool Start::mouseDetect(sf::FloatRect bounds)
{
	if ((this->mousePosWindow.x > bounds.left) && (this->mousePosWindow.x < (bounds.left + bounds.width)) && (this->mousePosWindow.y > bounds.top) && (this->mousePosWindow.y < (bounds.height + bounds.top)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Start::mousePress()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if ((this->mousePressBool != true) && (this->mouseDetect(this->firstButton.getGlobalBounds())))
		{
			this->mousePressBool = true;
			std::cout << "\n\n firstButtonEvent \n\n";
			this->firstButtonEvent();
		}
		else if ((this->mousePressBool != true) && (this->mouseDetect(this->secondButton.getGlobalBounds())))
		{
			this->mousePressBool = true;
			std::cout << "\n\n secondButtonEvent \n\n";
			this->secondButtonEvent();
		}
		else if ((this->mousePressBool != true) && (this->mouseDetect(this->thirdButton.getGlobalBounds())))
		{
			this->mousePressBool = true;
			std::cout << "\n\n thirdButtonEvent \n\n";
			this->thirdButtonEvent();
		}
		else
		{
			this->mousePressBool = true;
		}
	}
	else
	{
		this->mousePressBool = false;
	}
}

void Start::firstButtonEvent()
{
	if (this->startLevel == BeginButton)
	{
		this->startLevel = StartButton; 

	}
	else if (this->startLevel == StartButton)
	{
		this->startLevel = BeginButton; 
		this->outTypeGame=1;
		this->window->close();
		
		
	}
}

void Start::secondButtonEvent()
{
	if (this->startLevel == BeginButton)
	{
		this->outTypeGame = 2;
		this->window->close();
	}
	else if (this->startLevel == StartButton)
	{
		this->startLevel = BeginButton;
		this->outTypeGame = 3;
		this->window->close();
	}
}

void Start::thirdButtonEvent()
{
	
	if (this->startLevel == BeginButton)
	{
		this->startLevel = BeginButton;
		this->window->close();
	}
	else if (this->startLevel == StartButton)
	{
		this->startLevel = BeginButton;
		this->outTypeGame = 4;
		this->window->close();
	}
}

void Start::changeButtons()
{
	if (this->startLevel == this->startLevelBuff) return;
	else if (this->startLevel == BeginButton)
	{
		std::cout << "\n\n BeginButton \n\n";
		this->startLevelBuff = this->startLevel;

		this->firstButtonText.setPosition(150.f, 120.f);
		this->firstButtonText.setString("Start");
		this->secondButtonText.setPosition(140.f, 188.f);
		this->secondButtonText.setString("Option");

		this->thirdButtonText.setPosition(170.f, 265.f);
		this->thirdButtonText.setString("Exit");

		return;
	}
	else if (this->startLevel == StartButton)
	{
		std::cout << "\n\n StartButton \n\n";
		this->startLevelBuff = this->startLevel;

		this->firstButtonText.setPosition(150.f, 120.f);
		this->firstButtonText.setString("Alone");

		this->secondButtonText.setPosition(140.f, 188.f);
		this->secondButtonText.setString("Server");

		this->thirdButtonText.setPosition(150.f, 265.f);
		this->thirdButtonText.setString("Client");

		return;
	}

}

int Start::run()
{
	//delete this->window;
	this->initWindow();
	this->initVariables();
	this->initText();
	while (this->window->isOpen())
	{
	this->update();
	this->render();
	}

	delete this->window;
	return this->outTypeGame;
}

void Start::update()
{
	this->pollEvents();
	this->updateMousePositions();
	this->mousePress();
	this->changeButtons();
}

void Start::render()
{
	this->window->clear();
	this->window->draw(this->Screen);
	this->renderButtons(this->window);
	this->window->display();
}

void Start::renderButtons(sf::RenderTarget* target)
{
	target->draw(this->firstButton);
	target->draw(this->secondButton);
	target->draw(this->thirdButton);

	target->draw(this->firstButtonText);
	target->draw(this->secondButtonText);
	target->draw(this->thirdButtonText);
}
