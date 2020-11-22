#include "game.h"
#include <iostream>
Game::Game()
{
	createWindow();
	loadBackgrounds();
}

void Game::createWindow()
{
	window.create(sf::VideoMode(WEIGHT, HEIGHT), "Snake", sf::Style::Close);
	window.setFramerateLimit(FPS_LIMIT);
	window.setKeyRepeatEnabled(false);
}

void Game::loadBackgrounds()
{
	textureManager.addTexture(Texture::MENU_BACKGROUND);
	textureManager.addTexture(Texture::GAME_BACKGROUND);
	menuBackground.setTexture(textureManager.getTexture(Texture::MENU_BACKGROUND));
	gameBackground.setTexture(textureManager.getTexture(Texture::GAME_BACKGROUND));
}

void Game::draw()
{
	if (!startGame)
		window.draw(menuBackground);
	else if (startGame)
	{
		window.draw(gameBackground);
		snake.draw(window);
	}
}

void Game::handleInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				startGame = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if (startGame)
				setDirection();
			break;
		default:
			break;
		}
	}
}
void Game::update()
{
	int elapsedTime = clock.getElapsedTime().asMilliseconds();
	if ( elapsedTime>= 200)
	{
		snake.snakeMove();
		clock.restart();
	}
}
void Game::setDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getDirection() != Direction::RIGHT)
		snake.setNewDirection(Direction::LEFT);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getDirection() != Direction::DOWN)
		snake.setNewDirection(Direction::UP);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.getDirection() != Direction::LEFT)
		snake.setNewDirection(Direction::RIGHT);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getDirection() != Direction::UP)
		snake.setNewDirection(Direction::DOWN);
}

sf::RenderWindow& Game::getWindow()
{
	return window;
}

TextureManager& Game::getTextureManager()
{
	return textureManager;
}

void Game::setGameState(bool gameState)
{
	startGame = gameState;
}

bool& Game::getGameState()
{
	return startGame;
}
