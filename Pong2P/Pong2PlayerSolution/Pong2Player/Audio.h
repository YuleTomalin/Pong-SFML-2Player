#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

struct Audio
{
	sf::SoundBuffer buffer;
	sf::Sound sound;

	void delay_ms(int ms)
	{
		sf::Clock Timer;
		while (Timer.getElapsedTime().asMilliseconds() < ms);
	}

	void beepSound()
	{
		sf::SoundBuffer buffer;
		if (!buffer.loadFromFile("audio/pong-hit1.wav")) std::cerr << "Error while loading sound file" << std::endl;

		sf::Sound sound;
		sound.sf::Sound::setBuffer(buffer);
		sound.play();

		// Set Pitch
		//sound.setPitch(1.4f);
	}
};