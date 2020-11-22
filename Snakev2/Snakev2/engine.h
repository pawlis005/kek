#pragma once
#include "game.h"
class Engine
{
private:
	Game game;
	void gameLoop();
public:
	Engine()=default;
	~Engine() = default;
	void startGame();
};

