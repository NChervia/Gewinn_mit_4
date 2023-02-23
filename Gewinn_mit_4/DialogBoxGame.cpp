#include "DialogBoxGame.h"

void DialogBoxGame::initWindow() // Initialize the render window
{
	this->window = new sf::RenderWindow(sf::VideoMode(400, 200), "Hello -Gewinn mit 4", sf::Style::Close | sf::Style::Titlebar);
}

void DialogBoxGame::initTexture() // Initialize textures
{
	if (!this->textureScreen.loadFromFile("Texture/ScreenDialogBox.png"))   std::cout << "Error Texture Screen.png\n";
	if (!this->textureButton.loadFromFile("Texture/ButtonH.png"))   std::cout << "Error Texture ButtonH.png\n";
}

void DialogBoxGame::initSprite() // Initialize sprites
{
	this->Screen.setTexture(this->textureScreen);
	this->Screen.setPosition(0.f, 0.f);


	this->SpButton.setTexture(this->textureButton);
	this->SpButton.setPosition(75.f, 90.f);
	//this->SpButton.scale(0.5f, 0.5f);
}

void DialogBoxGame::initFonts() // Initialize fonts
{
	if (!this->inkFree.loadFromFile("Fonts/inkfree.ttf"))std::cout << "Error Font inkfree.ttf\n";
}

void DialogBoxGame::initText() // Initialize texts
{
	this->guiText.setFont(this->inkFree);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(100);
	this->guiText.setPosition(200.f, 00.f);
	this->guiText.setOutlineThickness(1.f);
	this->guiText.setOutlineColor(sf::Color::White);
	this->guiText.setString(" ");


}

DialogBoxGame::DialogBoxGame()
{
	this->initTexture();	// Initialize textures
	this->initSprite();		// Initialize sprites
	this->initFonts();		// Initialize fonts
	this->initText();		// Initialize texts
}

DialogBoxGame::~DialogBoxGame()
{
}

void DialogBoxGame::updateMousePositions() // Update global mouse position data
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void DialogBoxGame::pollEvents() // Event handling
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
			if (this->sfmlEvent.key.code == sf::Keyboard::Enter)
			{
				this->window->close();
			}
			break;
		}
	}
}

void DialogBoxGame::mousePress()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if ((this->mousePosWindow.y > 90) && (this->mousePosWindow.y < 170) && (this->mousePosWindow.x > 75) && (this->mousePosWindow.x < 320))
		{
			std::cout << " y - " << this->mousePosWindow.y << " x - " << this->mousePosWindow.x << std::endl;
		}
	}
}

void DialogBoxGame::run()
{
	this->initWindow(); // Initialize the render window
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
	delete this->window;
}

void DialogBoxGame::renderText(sf::RenderTarget* target) // Render text
{
	target->draw(this->guiText); 
}

void DialogBoxGame::update() // Updating
{
	this->pollEvents();
	this->updateMousePositions();
	this->mousePress();

}

void DialogBoxGame::render() // Rendering
{
	this->window->clear();
	this->window->draw(this->Screen);
	this->window->draw(this->SpButton);
	this->renderText(window);
	this->window->display();
}


