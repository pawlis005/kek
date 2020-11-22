#include "snake.h"

Snake::Snake()
{
    createHead(sf::Vector2f(FIELD_WEIGHT/2,FIELD_HEIGHT/2+20));
    currentDirection = randomDirection();
}
void Snake::createHead(sf::Vector2f position) {
    sf::RectangleShape head;
    head.setSize(sf::Vector2f(40, 40));
    head.setFillColor(sf::Color::Yellow);
    float width = head.getLocalBounds().width;
    float height = head.getLocalBounds().height;
    head.setPosition(position);
    snakeParts.push_back(head);
}

void Snake::draw(sf::RenderWindow& window) {
    for (int i = 0; i < snakeParts.size(); i++)
        window.draw(snakeParts[i]);

    int headIndex = snakeParts.size() - 1;
    sf::RectangleShape head = snakeParts.at(headIndex);
    //orientateHead(head);
    window.draw(head);
}

Direction Snake::randomDirection()
{
    return Direction(rand() % Direction::LAST);
}

void Snake::orientateHeadUp(sf::RectangleShape& head)
{
    float width = head.getLocalBounds().width;
    head.setOrigin(width, 0.0f);
    head.rotate(270);
}

void Snake::orientateHeadRight(sf::RectangleShape& head)
{
    head.setOrigin(0.0f, 0.0f);
    head.rotate(0);
}

void Snake::orientateHeadDown(sf::RectangleShape& head)
{
    float height = head.getLocalBounds().height;
    head.setOrigin(0.0f, height);
    head.rotate(90);
}

void Snake::orientateHeadLeft(sf::RectangleShape& head)
{
    float width = head.getLocalBounds().width;
    float height = head.getLocalBounds().height;
    head.setOrigin(width, height);
    head.rotate(180);
}

void Snake::orientateHead(sf::RectangleShape& head)
{
    switch (currentDirection)
    {
    case Direction::RIGHT:
        orientateHeadRight(head);
        break;

    case Direction::UP:
        orientateHeadUp(head);
        break;

    case Direction::DOWN:
        orientateHeadDown(head);
        break;

    case Direction::LEFT:
        orientateHeadLeft(head);
        break;

    case Direction::LAST:
        break;
    }
}

sf::Vector2f Snake::getNewHeadPosition()
{
    int headIndex = snakeParts.size() - 1;
    sf::RectangleShape head = snakeParts.at(headIndex);
    float xMovement = head.getLocalBounds().width;
    float yMovement = head.getLocalBounds().height;

    sf::Vector2f position = head.getPosition();
    if (currentDirection == Direction::RIGHT)
        position.x += xMovement;
    else if (currentDirection == Direction::DOWN)
        position.y += yMovement;
    else if (currentDirection == Direction::LEFT)
        position.x -= xMovement;
    else if (currentDirection == Direction::UP)
        position.y -= yMovement;

    return position;
}

void Snake::moveBodyParts() 
{
    for (unsigned int i = 0; i < snakeParts.size() - 1; ++i)
    {
            sf::Vector2f nextPos = snakeParts.at(i + 1).getPosition();
            snakeParts.at(i).setPosition(nextPos);
    }
}

void Snake::snakeMove()
{
    moveBodyParts();
    currentDirection = newDirection;
    sf::Vector2f position = getNewHeadPosition();

    unsigned int headIndex = snakeParts.size() - 1;
    sf::RectangleShape head = snakeParts.at(headIndex);
    head.setPosition(position.x, position.y);
    snakeParts.at(headIndex) = head;
}

Direction Snake::getDirection()
{
    return currentDirection;
}

void Snake::setNewDirection(Direction direction)
{
    this->newDirection = direction;
}