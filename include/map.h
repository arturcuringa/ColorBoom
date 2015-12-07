#ifndef __MAP__
#define __Map__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.h" 
class MAP{

	public:
	// \brief Map "Rigid Body" 
	sf::RectangleShape Body;
	// \brief Collision Rectangle between Player and Map
	sf::RectangleShape colision;
	// \brief Intensity of White
	int blink;
	// \brief Change control
	bool grow;
	// \Brief Map constructor, Texture Set and Outline
	MAP();
	// \brief Map animation
	void update(sf::Clock& hourglass);
	// \brief Map collision test
	void outside(sf::Vector2f Position, sf::FloatRect TestSub, sf::Vector2f& Correct);
};

#endif