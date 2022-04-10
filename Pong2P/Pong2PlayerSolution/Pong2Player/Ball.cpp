#include <SFML/Audio.hpp>
#include <iostream>

#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(15, 15));
	m_Shape.setPosition(m_Position);
}

sf::FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return m_Shape;
}

float Ball::getXVelocity()
{
	return m_DirectionX;
}

float Ball::getYVelocity()
{
	return m_DirectionY;
}

void Ball::reboundTop()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundBat()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundSides()
{
	m_Position.x = 1920 / 2;
	m_Position.y = static_cast<float>(rand() % 960);
	m_DirectionX = -m_DirectionX;
}

void Ball::update(sf::Time Δt)
{
	// Update the Balls position
	m_Position.y += m_DirectionY * m_Speed * Δt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * Δt.asSeconds();

	// Move the ball
	m_Shape.setPosition(m_Position);
}