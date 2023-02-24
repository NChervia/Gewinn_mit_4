#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class DialogBoxGame
{
private:

	sf::RenderWindow* window; // Create the render window

	sf::Event sfmlEvent;     // Event processing

	sf::Vector2i mousePosWindow; // Global mouse position data

	

	//Creating textures
	sf::Texture textureScreen;
	sf::Texture textureButton;


	sf::Font inkFree;    //Creating Font
	sf::Text guiText;    //Creating Text
	sf::Text buttonText; //Creating Text on button

	sf::Sprite Screen;		// Create a sprite. Screen
	sf::Sprite SpButton;	// Create a sprite. Button


	//Private functions
	void initWindow();		// Initialize the render window
	void initTexture();		// Initialize textures
	void initSprite();		// Initialize sprites
	void initFonts();		// Initialize fonts
	void initText();		// Initialize texts
	

public:
	//Constructor\Destructor
	DialogBoxGame();
	~DialogBoxGame();

	//Functions
	void updateMousePositions(); // Update global mouse position data
	void pollEvents();	// Event handling
	void mousePress();	// Handle mouse click
	void run(); // Start the game
	void run(int type); // Start the game with text box and text button

	void renderText(sf::RenderTarget* target);	// Render text

	void update(); // Updating
	void render(); // Rendering
};

