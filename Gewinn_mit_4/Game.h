#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>



class Game
{
private:


	sf::RenderWindow* window;//Window
	sf::Event sfmlEvent; //Event


	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//sf::Texture test;

	//sf::Font inkFree;
	//sf::Text guiText;

	//sf::Sprite XorO;

	//std::vector <sf::Sprite> GameMap;



	//Private functions
	void initWindow();
	void initVariables();
	void initSprite();
	void initTexture();
	void initFonts();
	void initText();
	


public:
	//Constructor\Destructor
	Game();
	virtual ~Game();

	//Functions

	void updateMousePositions();
	void pollEvents();
	

	int mousePress();

	//void renderSprite(sf::RenderTarget* target);
	//void renderText(sf::RenderTarget* target);
	
	void run();

	void update();
	void render();
};

