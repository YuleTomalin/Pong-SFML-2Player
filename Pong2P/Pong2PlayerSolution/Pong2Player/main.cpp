/*
* Yule Tomalin, 2022
* SFML project - 2 Player Pong Game
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "Player.h"
#include "Ball.h"
#include "Audio.h"
#include "Line.h" // Do later!!

#undef main

int main()
{
	sf::VideoMode vm(1920, 1080);

	sf::RenderWindow window(vm, "Pong", sf::Style::Fullscreen);

	Player p1(1920 - 30, 1080 / 2);		// Start at positions: X = 1890, Y = 540
	Player p2(1920 - 1890, 1080 / 2);	// Start at positions: X = 30, Y = 540

	Ball ball(static_cast<float>(rand() % (1920 / 2)), static_cast<float>(rand() % 960));		// Start at positions: X = 960, Y = random positions within 960 by X-values

	// Line line(static_cast<float>(1920 / 2), 0);

	// Load Audio from Audio.h
	Audio aud;

	// Score
	int score1 = 0;
	int score2 = 0;

	/*
	* HUD for P1
	*/

	sf::Text hud1;
	sf::Font font1;
	font1.loadFromFile("fonts/ds_digital/DS-DIGIB.TTF");
	hud1.setFont(font1);
	hud1.setCharacterSize(115);
	hud1.setFillColor(sf::Color::White);
	hud1.setPosition(700, 20);

	/*
	* HUD for P2
	*/

	sf::Text hud2;
	sf::Font font2;
	font2.loadFromFile("fonts/ds_digital/DS-DIGIB.TTF");
	hud2.setFont(font2);
	hud2.setCharacterSize(115);
	hud2.setFillColor(sf::Color::White);
	hud2.setPosition(1050, 20);

	sf::Clock clock;

	while (window.isOpen())
	{
		// Handle Player Input
		sf::Event e;

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close(); // Quiting

		// First player 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) p1.moveUp(); else p1.stopUp();		// Up Arrow Key
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) p1.moveDown(); else p1.stopDown();	// Down Arrow Key

		// Second player
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) p2.moveUp(); else p2.stopUp();			// W Key
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) p2.moveDown(); else p2.stopDown();		// S Key

		// Update the 2 Players and the Ball
		sf::Time Δt = clock.restart();
		p1.update(Δt);
		p2.update(Δt);
		ball.update(Δt);

		// Update the HUD Text
		std::stringstream ss1;
		std::stringstream ss2;
		ss1 << score1;
		ss2 << score2;
		hud1.setString(ss1.str());
		hud2.setString(ss2.str());

		// Handle Ball hitting the top and bottom
		if (ball.getPosition().top < 0)
		{
			ball.reboundTop();
		}
		if (ball.getPosition().top + ball.getPosition().width > window.getSize().y)
		{
			ball.reboundBottom();
		}

		// Handle Ball hitting sides
		if (ball.getPosition().left < 0)
		{
			ball.reboundBat();
			ball.reboundSides();

			score2++;
		}
		if (ball.getPosition().left + ball.getPosition().height > window.getSize().x)
		{
			ball.reboundBat();
			ball.reboundSides();

			score1++;
		}

		// Handle ball hitting the two players
		if (ball.getPosition().intersects(p1.getPosition()))
		{
			ball.reboundBat();
			aud.beepSound();
			
		}
		if (ball.getPosition().intersects(p2.getPosition()))
		{
			ball.reboundBat();
			aud.beepSound();
			
		}

		// Draw the hud, the players, the ball, and the line between
		window.clear();
		window.draw(hud1);
		window.draw(hud2);
		// window.draw(line.getShape());
		window.draw(p1.getShape());
		window.draw(p2.getShape());
		window.draw(ball.getShape());
		window.display();
	}


	return 0;
}