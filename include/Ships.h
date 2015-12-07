#ifndef __SHIPS__
#define __SHIPS__

#include <math.h>
#include <SFML/Graphics.hpp>
#include "Config.h"

class Shipnode{
public:
	Shipnode(){
		//body.setSize(sf::Vector2f(22.f,22.f));
		body.setTexture(Configuration::textures.get(Configuration::Textures::Ships));
		body.setTextureRect(sf::IntRect(0,0,22,22));
	}
	
	sf::Sprite body;
	
	Shipnode *next;
	Shipnode *prev;
};


class ShipsPaint : public  Shipnode{
	public:
	
		Shipnode * S_head;
		Shipnode * S_tail;
		ShipsPaint();
		~ShipsPaint();
		void ShipsUpdate(sf::Time& deltaTime, sf::Sprite target,bool slow);
		void ShipsDraw(sf::RenderWindow &myWindow);
		void ShipsAdd(sf::Vector2f origin,sf::Color cor);
		void ShipsRemove(Shipnode* rem);
		bool empty();
		void clear();
};



#endif