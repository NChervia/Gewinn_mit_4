#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include "DialogBoxGame.h"
#include "XO4.h"  //Game logic 
#include "Server.h" // Server socket class
#include "Client.h" // Client socket class

class gameUp
{
private:

	Server Server;//Class initialization
	Client Client;//Class initialization
	XO4 GameSTD;  //Class initialization
	DialogBoxGame  DialogBoxGame; //Class initialization

	sf::RenderWindow* window; // Create the render window

	sf::Event sfmlEvent;     // Event processing

	sf::Vector2i mousePosWindow; // Global mouse position data
	bool mousePressBool; //Mouse click data

	//Creating textures
	sf::Texture textureGameMap;
	sf::Texture textureScreen;
	
	sf::Texture textureChipA;
	sf::Texture textureChipB;
	sf::Texture textureChipZero;


	sf::Font inkFree; //Creating Font
	sf::Text guiText; //Creating Text

	sf::Sprite gameMap;		// Create a sprite. Game map
	sf::Sprite Screen;		// Create a sprite. Screen
	sf::Sprite gameChip;	// Create a sprite. Game chip


	std::vector <sf::Sprite> gameMapChips; // Create a vector of sprites. Chips on the game map
	
	int typeGame;  //1 - single player, 3 - server player, 4 - client player,

	float ChipsCoor[50][2]; //Chips coordinates

	int gameStep; // Game step number

	int numTextureChipA;  //Texture number of the first chip
	int numTextureChipB; // Texture number of the second chip

	//Private functions
	void initWindow();		// Initialize the render window
	void initVariables();	// Initialize variables
	void initTexture();		// Initialize textures
	void initTextureChipsAB(); // Initialize textures for chips A and B
	void initSprite();		// Initialize sprites
	void initFonts();		// Initialize fonts
	void initText();		// Initialize texts
	void initChipsCoor();   // Initialize chips coordinates
	void initGameMapChips();// Initialize a vector of sprites. Chips on the game map

public:
	//Constructor\Destructor
	gameUp();
	~gameUp();
	void pollEvents();	// Event handling

	void updateMousePositions(); // Update global mouse position data
	void UpdateGameMap(); //Update game map from GameSTD class
	void mouseTouch();	// Handle mouse touch
	void gameStepFunc(); //Game turn
	void gameFinish(); //Events after the finish
	int mousePres(); // Handle mouse click, out num chip
	void run(int TypeGame, int ChipsTextyreNum); // Start the game
	
	void renderGameMapChips(sf::RenderTarget* target);  // Render game chips
	void renderText(sf::RenderTarget* target);			// Render text

	void update(); // Updating
	void render(); // Rendering
};

