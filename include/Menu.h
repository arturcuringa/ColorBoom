#ifndef __MENU__
#define __MENU__

#include <math.h>
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Player.h"
#include "Gameinterface.h"

class Menu{
	public:
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
		Menu() = default;

	static int mainmenu(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen);
	static int pausemenu(sf::RenderWindow& myWindow,sf::View& camera,PlayerGuy& Player,MAP& Map,ShipsPaint& ShipList,sf::Text& texto);
	static void rainbow(sf::Color &cor,int &corsect);
	static void menuinit(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen);
	static void menuopt(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen);
	static void gameover(sf::RenderWindow& myWindow, sf::View& camera);
	static void highScore(sf::RenderWindow& myWindow, sf::View& camera, long unsigned int score);
};

#endif