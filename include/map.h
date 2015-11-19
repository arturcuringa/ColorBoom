#ifndef __MAP__
#define __Map__

#include <SFML/Graphics.hpp>

class MAP{

	public:
	sf::RectangleShape Body;
	sf::Texture sky;
	int blink;
	bool grow;
	MAP();
	void update(sf::Clock& hourglass);
	bool outside(sf::Vector2f Position, sf::FloatRect TestSub, sf::Vector2f& Correct);
};

#endif