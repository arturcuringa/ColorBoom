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

	static bool mainmenu(sf::RenderWindow& myWindow);
	static void rainbow(sf::Color &cor,int &corsect);
	static void menuinit(sf::RenderWindow& myWindow);
};

#endif