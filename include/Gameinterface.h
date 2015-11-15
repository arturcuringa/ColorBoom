#ifndef __COLORGAME__
#define __COLORGAME__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <math.h>

class GameInterface
{

	public:
		GameInterface();
		void Start();
	
	private:

	void render();
	void update(sf::Time deltaTime);
	void EventInput();
	void PlayerInput(sf::Keyboard::Key key, bool press);
	sf::RenderWindow myWindow;
	PlayerGuy Player;



};




#endif
