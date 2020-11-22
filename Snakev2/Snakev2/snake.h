#pragma once
#include <vector>
#include<SFML/Graphics.hpp>
#include "direction.h"

class Snake
{
private:
	int FIELD_WEIGHT = 800;
	int FIELD_HEIGHT = 600;
	std::vector<sf::RectangleShape> snakeParts;
	Direction currentDirection;
	Direction newDirection;

	void createHead(sf::Vector2f position);
	Direction randomDirection();
	void orientateHead(sf::RectangleShape& head);
	void orientateHeadUp(sf::RectangleShape& head);
	void orientateHeadRight(sf::RectangleShape& head);
	void orientateHeadDown(sf::RectangleShape& head);
	void orientateHeadLeft(sf::RectangleShape& head);
	sf::Vector2f getNewHeadPosition();
	void moveBodyParts();
public:
	Snake();
	~Snake() = default;
	void draw(sf::RenderWindow& window);
	void snakeMove();
	Direction getDirection();
	void setNewDirection(Direction direction);
};

