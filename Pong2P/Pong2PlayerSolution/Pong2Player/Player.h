#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(float startX, float startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();

	void update(sf::Time Δt);

private:
	sf::Vector2f m_Position;

	// A RectangleShape Object
	sf::RectangleShape m_Shape;

	float m_Speed = 800.f;
	bool m_MovingUp = false;
	bool m_MovingDown = false;
};