#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(float startX, float startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	float getXVelocity();
	float getYVelocity();

	void reboundTop();

	void reboundBottom();

	void reboundBat();

	void reboundSides();

	void update(sf::Time Δt);

private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_Shape;

	float m_Speed = 2000.f;
	float m_DirectionX = .3f;
	float m_DirectionY = .3f;
};