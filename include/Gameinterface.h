#ifndef __COLORGAME__
#define __COLORGAME__

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Shoot.h"
#include "Player.h"
#include <math.h>
#include "map.h"
#include "Ships.h"
#include "pilha.h"
#include <sstream>
#include <string>

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
	PilhaVetor<sf::RenderWindow> ScreenStack;
	sf::RenderWindow myWindow;
	PlayerGuy Player;
	PlayerIn Inp;
	sf::View Camera;
	MAP Map;
	ShipsPaint ShipList;
	sf::Text texto;
	sf::Font fonte;
	void collision();
};




#endif
