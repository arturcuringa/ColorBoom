#ifndef __SHIPS__
#define __SHIPS__

#include <math.h>
#include <SFML/Graphics.hpp>

class ShipsPaint{
	public:
		struct Shipsnode
		{				
			sf::RectangleShape body;
			sf::Color;
			sf::Texture sprite;
			Shipsnode *next;
			Shipsnode *prev;
			
		};

		Shipsnode * S_head;
		Shipsnode * S_tail;
		ShipsPaint();
		~ShipsPaint();
		void ShootUpdate(sf::Time& deltaTime);
		void ShipDraw(sf::RenderWindow &myWindow);
		void ShipAdd(sf::Vector2f Position,sf::Vector2f origin,sf::Color cor);
		void ShipRemove(Shootnode* prev,Shootnode* rem);


};

#endif