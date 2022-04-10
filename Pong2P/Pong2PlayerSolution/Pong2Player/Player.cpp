#include "Player.h"

Player::Player(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(5, 100));
	m_Shape.setPosition(m_Position);
}

sf::FloatRect Player::getPosition()
{
	return m_Shape.getGlobalBounds();
}

sf::RectangleShape Player::getShape()
{
	return m_Shape;
}

void Player::moveUp()
{
	m_MovingUp = true;
}

void Player::moveDown()
{
	m_MovingDown = true;
}

void Player::stopUp()
{
	m_MovingUp = false;
}

void Player::stopDown()
{
	m_MovingDown = false;
}

void Player::update(sf::Time Δt)
{
	if (m_MovingUp)
	{
		m_Position.y -= m_Speed * Δt.asSeconds();
	}
	if (m_MovingDown)
	{
		m_Position.y += m_Speed * Δt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}