#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Option
{

private:

	//Variables

	sf::RenderWindow* window;//Window
	sf::Event sfmlEvent; //Event


	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mousePressBool;

	sf::Texture textureScreen;
	sf::Texture textureChips;

	sf::Texture textureChip1;
	sf::Texture textureChip2;
	sf::Texture textureChip3;
	sf::Texture textureChip4;
	sf::Texture textureChip5;
	sf::Texture textureChip6;
	sf::Texture textureChip7;
	sf::Texture textureChip8;
	sf::Texture textureChip9;
	sf::Texture textureChipZero;

	sf::Sprite Screen;
	sf::Sprite firstChip;
	sf::Sprite secondChip;
	sf::Sprite ChoisChip;

	sf::Font inkFree;

	sf::Text textFirstChip;
	sf::Text textSecondChip;

	int numTextureFirstChip;
	int numTextureSecondChip;
	int choisChipNum;
	bool ChipAB;

	
	//Private functions
	void initWindow();
	void initVariables();
	void initSprite();
	void initTexture();
	void initFonts();
	void initText();





public:
	Option();
	~Option();


	void pollEvents();

	void updateMousePositions();
	int mouseDetect();
	void mousePress();
	void mouseTouch();
	void ChageTextures(int num);

	int run();

	void update();
	void render();
	void renderButtons(sf::RenderTarget* target);
};

