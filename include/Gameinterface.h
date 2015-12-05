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
#include "Menu.h"
#include "Score.h"

class GameInterface
{

	public:
		GameInterface();
		void GameLoop();
		static void GameOver();
	private:

	void Start();
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
	bool ingame;
	void clear();
	void collision();
	void preload(int enemys);
	void menuopt(bool ingame);
	sf::Clock GameTime;
	sf::Time FaseTime;
};




#endif
