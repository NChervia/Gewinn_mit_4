#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include "XO4.h"  //Game logic class
#include "DialogBoxGame.h" //Dialog box class


class Game
{
private:

	XO4 GameSTD; //Class initialization
	DialogBoxGame DialogBoxGame;  //Class initialization
	//Server Server;//Class initialization
	
	sf::RenderWindow* window; // Create the render window
	
	sf::Event sfmlEvent;     // Event processing

	sf::Vector2i mousePosWindow; // Global mouse position data

	bool mousePressBool; //Mouse click data
	int mouseTouchBuff;  //Mouse position data, touch
	int mousePressBuff;  //Mouse position data, press


	//Creating textures
	sf::Texture textureGameMap;
	sf::Texture textureGameChipA;
	sf::Texture textureGameChipB;
	sf::Texture textureGameChipZero;
	sf::Texture textureScreen;

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
		
	sf::Font inkFree; //Creating Font
	sf::Text guiText; //Creating Text


	sf::Sprite gameMap;		// Create a sprite. Game map
	sf::Sprite Screen;		// Create a sprite. Screen
	sf::Sprite gameChipA;	// Create a sprite. Game chip
	sf::Sprite gameChipB;	// Create a sprite. Pointing chip

	std::vector <sf::Sprite> gameMapChips; // Create a vector of sprites. Chips on the game map

	float chipsXY[50][2]; 
	int gameStep;
	int numTextureFirstChip;
	int numTextureSecondChip;

	//Private functions
	void initWindow();		// Initialize the render window
	void initVariables();	// Initialize variables
	void initSprite();		// Initialize sprites
	void initTexture();		// Initialize textures
	void initFonts();		// Initialize fonts
	void initText();		// Initialize texts
	void initChipsXY();
	void initGameMapChips(); 
	void initTextureChipsAB();


public:
	//Constructor\Destructor
	Game();
	~Game();

	//Functions

	void updateMousePositions(); // Update global mouse position data
	void updateGameMapChips();
	void pollEvents();	// Event handling
	void mouseTouch();	// Handle mouse touch
	int  mousePress();	// Handle mouse click
	void shotGame();	
	void FinishFunc();	// Handling the finish

	void run(int TypeGame, int ChipsTextyreNum); // Start the game


	void renderGameMapChips(sf::RenderTarget* target);  // Render game chips
	void renderText(sf::RenderTarget* target);			// Render text
	 
	

	void update(); // Updating
	void render(); // Rendering
};

