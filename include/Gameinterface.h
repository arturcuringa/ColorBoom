#ifndef __COLORGAME__
#define __COLORGAME__

#include <iostream>
#include <SFML/Graphics.hpp>

class GameInterface
{

	public:
		GameInterface();
		void Start();
	
	private:

	void render();
	void update(){};
	void EventInput();
	void PlayerInput(sf::Keyboard::Key key, bool press);
	sf::RenderWindow myWindow;
	sf::CircleShape Player;



};




#endif
