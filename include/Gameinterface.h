#ifndef __COLORGAME__
#define __COLORGAME__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shoot.h"
#include "Player.h"
#include <math.h>

class GameInterface
{

	public:
		GameInterface();
		void Start();
	
	private:

	void render();
	void update(sf::Time deltaTime,sf::Clock &timer);
	void EventInput();
	void PlayerInput();
	void PlayerMove();
	sf::RenderWindow myWindow;
	PlayerGuy Player;
	PlayerIn Inp;


};




#endif
