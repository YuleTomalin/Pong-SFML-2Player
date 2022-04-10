#include "Line.h"

Line::Line(float startX, float startY)
{
	m_Position.x = static_cast<float>(1920 / 2);
	m_Position.y = 1;

	m_Shape.setSize(sf::Vector2f(1080, 1));
	m_Shape.setPosition(m_Position);
}

sf::FloatRect Line::getPosition()
{
	return m_Shape.getGlobalBounds();
}

sf::RectangleShape Line::getShape()
{
	return m_Shape;
}
