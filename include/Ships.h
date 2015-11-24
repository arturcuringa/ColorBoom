#ifndef __SHIPS__
#define __SHIPS__

#include <math.h>
#include <SFML/Graphics.hpp>


class Shipnode{
public:
	Shipnode(){
		body.setSize(sf::Vector2f(22.f,22.f));
		sprite.loadFromFile("ENEMY SHIPS2.png");
		body.setTexture(&sprite);
		body.setTextureRect(sf::IntRect(0,0,22,22));
	}
	
	sf::RectangleShape body;
	sf::Texture sprite;
	
	Shipnode *next;
	Shipnode *prev;
};


class ShipsPaint : public  Shipnode{
	public:
	
		Shipnode * S_head;
		Shipnode * S_tail;
		ShipsPaint();
		~ShipsPaint();
		void ShipsUpdate(sf::Time& deltaTime, sf::CircleShape target);
		void ShipsDraw(sf::RenderWindow &myWindow);
		void ShipsAdd(sf::Vector2f origin,sf::Color cor);
		void ShipsRemove(Shipnode* rem);
		bool empty();

};



#endif