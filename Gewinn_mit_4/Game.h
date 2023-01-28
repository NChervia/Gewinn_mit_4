#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include "XO4.h"



class Game
{
private:

	XO4 GameSTD;

	sf::RenderWindow* window;//Window
	sf::Event sfmlEvent; //Event


	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mousePressBool;
	int mouseTouchBuff;
	int mousePressBuff;

	sf::Texture textureGameMap;
	sf::Texture textureGameChipA;
	sf::Texture textureGameChipB;
	sf::Texture textureGameChipZero;
	sf::Texture textureScreen;
	
	sf::Font inkFree;
	sf::Text guiText;

	sf::Sprite gameMap;
	sf::Sprite Screen;
	sf::Sprite gameChipA;
	sf::Sprite gameChipB;

	std::vector <sf::Sprite> gameMapChips;

	float chipsXY[50][2];
	int gameStep;
	

	//Private functions
	void initWindow();
	void initVariables();
	void initSprite();
	void initTexture();
	void initFonts();
	void initText();
	void initChipsXY();
	void initGameMapChips(); 


public:
	//Constructor\Destructor
	Game();
	virtual ~Game();

	//Functions

	void updateMousePositions();
	void updateGameMapChips();
	void pollEvents();
	void mouseTouch();
	int  mousePress();
	void shotGame();
	void FinishFunc();

	void renderGameMapChips(sf::RenderTarget* target);
	void renderText(sf::RenderTarget* target);
	void run(int TypeGame);

	void update();
	void render();
};

