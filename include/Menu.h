#ifndef __MENU__
#define __MENU__

#include <math.h>
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Player.h"
#include "Gameinterface.h"
#include <SFML/Audio/Music.hpp>
 // \class Static Menus 
class Menu{
	public:
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
		Menu() = default;
	// \brief Main Manu wiht Options exit and start
	static int mainmenu(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen);
	// \brief Menu Pause 
	static int pausemenu(sf::RenderWindow& myWindow,sf::View& camera,PlayerGuy& Player,MAP& Map,ShipsPaint& ShipList,sf::Text& texto);
	// \brief Random Color animation 
	static void rainbow(sf::Color &cor,int &corsect);
	// \brief Press Start Menu
	static void menuinit(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen);
	// \brief Option Menu
	static void menuopt(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen);
	// \brief Credits
	static void credits(sf::RenderWindow& myWindow, sf::View& camera);
	// \brief Game Over Screen
	static void gameover(sf::RenderWindow& myWindow, sf::View& camera);
	// \brief Set Name and HighScore
	static void highScore(sf::RenderWindow& myWindow, sf::View& camera, long unsigned int score);
};

#endif