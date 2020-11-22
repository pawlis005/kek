#include "engine.h"

void Engine::gameLoop()
{
	sf::RenderWindow& window = game.getWindow();
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		game.draw();
		game.handleInput();
		if (game.getGameState())
			game.update();
		window.display();
	}
}

void Engine::startGame()
{
	gameLoop();
}
