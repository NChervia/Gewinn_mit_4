#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum StartLevel { BeginButton = 0, StartButton = 1, OptionButton = 3, Null = 666 };
class Start
{
private:

	//Variables

	sf::RenderWindow* window;//Window
	sf::Event sfmlEvent; //Event


	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mousePressBool; 

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

	int outTypeGame;
	
	StartLevel startLevel;
	StartLevel startLevelBuff;

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
	bool mouseDetect(sf::FloatRect bounds);
	void mousePress();

	void firstButtonEvent();
	void secondButtonEvent();
	void thirdButtonEvent();
	void changeButtons();


	int run();

	void update();
	void render();
	void renderButtons(sf::RenderTarget* target);
};

