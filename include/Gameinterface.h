#ifndef __COLORGAME__
#define __COLORGAME__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shoot.h"
#include "Player.h"
#include <math.h>
#include "map.h"

class GameInterface
{

	public:
		GameInterface();
		void Start();
	
	private:

	void render();
	void update(sf::Time deltaTime,sf::Clock &timer,sf::Clock &tiemu);
	void EventInput();
	void PlayerInput();
	void PlayerMove();
	sf::RenderWindow myWindow;
	PlayerGuy Player;
	PlayerIn Inp;
	sf::View Camera;
	MAP Map;

};




#endif
