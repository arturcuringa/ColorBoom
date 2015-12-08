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
#include <list>

// \brief All Game Interface Object with all resourcer and features
class GameInterface
{

	public:
		// \breif Game Constructor
		GameInterface();
		// \brief Game Loops with Menus
		void GameLoop();
		static void GameOver();
	private:
	// \brief Starts the game
	void Start();
	// \brief Render all stuff
	void render();
	// \brief Update and control game in delta time
	void update(sf::Time deltaTime,sf::Clock &timer,sf::Clock &tiemu,sf::Clock &shoottime, sf::Clock &SpecialClock);
	// \brief Event hadle cotains PlayerInput and PlayerMove and ControllerInput
	void EventInput();
	// \brief Player Custom Input Handle
	void PlayerInput();
	// \brief Player Analogic Input Handle
	void PlayerMove();
	// \brief Monitor Possible Resolution's
	std::vector<sf::VideoMode> ResolutionList;
	// \brief Game windown
	sf::RenderWindow myWindow;
	// \brief Player Character
	PlayerGuy Player;
	// \Brief Player Controller 
	PlayerIn Inp;
	// \brief Games Camera
	sf::View Camera;
	// \brief Game Map
	MAP Map;
	// \brief Enemy List 
	ShipsPaint ShipList;
	// \brief HUD Score
	sf::Text Score;
	// \brief HUD Life
	sf::Text Life;
	// \brief List of sounds
	std::list<sf::Sound> Sounds;
	// \brief Static Sound comparator, "Close sounds"
	static bool soundoff(const sf::Sound& test);
	// \brief Resolution List Default Index
	int i;
	// \brief Game in progress
	bool ingame;
	// \brief Game window FullScreen Status
	int fullscreen;
	// \brief Clear the game
	void clear();
	// \brief Collision system
	void collision();
	// \brief Preload Fase
	void preload(int enemys);
	// \brief sets the points acording to the time:
	int points;
};




#endif