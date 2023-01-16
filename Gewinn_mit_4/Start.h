#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Start
{
private:

	sf::RenderWindow* window;//Window
	sf::Event sfmlEvent; //Event


	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	sf::Texture MenuTexture;
	sf::Texture ButtonTexture;

	sf::Sprite Screen;
	sf::Sprite firstButton;
	sf::Sprite secondButton;
	sf::Sprite thirdButton;

	sf::Font inkFree;

	sf::Text firstButtonText;
	sf::Text secondButtonText;
	sf::Text thirdButtonText;
	

	//Private functions
	void initWindow();
	void initVariables();
	void initSprite();
	void initTexture();
	void initFonts();
	void initText();





public:
	Start();
	~Start();


	void pollEvents();

	void updateMousePositions();
	void mousePress();


	void run();

	void update();
	void render();
};

