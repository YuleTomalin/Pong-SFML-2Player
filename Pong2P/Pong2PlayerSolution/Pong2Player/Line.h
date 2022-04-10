#pragma once

#include <SFML/Graphics.hpp>

class Line
{
public:
	Line(float startX, float startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

private:

	sf::Vector2f m_Position;

	sf::RectangleShape m_Shape;
};

