#pragma once

#include <SFML/Graphics.hpp>
#include "textureManager.h"
#include "texture.h"
#include "snake.h"
class Game
{
private:
	int WEIGHT = 800;
	int HEIGHT = 600;
	int FPS_LIMIT = 30;
	sf::Clock clock;
	bool startGame = false;
	Snake snake;
	sf::Sprite menuBackground;
	sf::Sprite gameBackground;
	sf::RenderWindow window;
	TextureManager textureManager;

	void createWindow();
	void loadBackgrounds();
	void setDirection();
public:
	Game();
	~Game() = default;
	sf::RenderWindow& getWindow();
	TextureManager& getTextureManager();
	void draw();
	void update();
	void handleInput();
	void setGameState(bool gameState);
	bool& getGameState();
};

