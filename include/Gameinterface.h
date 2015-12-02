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
#include "Config.h"

class GameInterface
{

	public:
		GameInterface();
		void Start();
	
	private:

	void render();
	void update(sf::Time deltaTime,sf::Clock &timer,sf::Clock &tiemu,sf::Clock &shoottime);
	void EventInput();
	void PlayerInput();
	void PlayerMove();
	sf::RenderWindow myWindow;
	PlayerGuy Player;
	PlayerIn Inp;
	sf::View Camera;
	MAP Map;
	ShipsPaint ShipList;
	sf::Text texto;
	sf::Font fonte;
	void collision();
	void preload(int enemys);
	void pausemenu();
	void menuopt(bool ingame);
	bool mainmenu();
	void menuinit();
	void rainbow(sf::Color &cor,int &corsect);
	sf::Clock GameTime;
};




#endif
