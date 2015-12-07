#ifndef __COLORGAME__
#define __COLORGAME__

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
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
#include <vector>

class GameInterface
{

	public:
		GameInterface();
		void GameLoop();
		static void GameOver();
	private:

	void Start();
	void render();
	void update(sf::Time deltaTime,sf::Clock &timer,sf::Clock &tiemu,sf::Clock &shoottime, sf::Clock &SpecialClock);
	void EventInput();
	void PlayerInput();
	void PlayerMove();
	std::vector<sf::VideoMode> ResolutionList;
	sf::RenderWindow myWindow;
	PlayerGuy Player;
	PlayerIn Inp;
	sf::View Camera;
	MAP Map;
	ShipsPaint ShipList;
	sf::Text Score;
	sf::Text Life;

	
	int i;
	bool ingame;
	int fullscreen;
	void clear();
	void collision();
	void preload(int enemys);
	void menuopt(bool ingame);
	sf::Clock GameTime;
	sf::Time FaseTime;
};




#endif
