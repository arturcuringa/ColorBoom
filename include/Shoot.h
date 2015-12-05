#ifndef __SHOOT__
#define __SHOOT__

#include <math.h>
#include <SFML/Graphics.hpp>
#include "Config.h"

class Shootnode{
public:
			int ani;
			double tang;
			sf::Vector2f total;
			sf::CircleShape ammo;
			Shootnode *next;
			Shootnode *prev;
};


class ShootPaint : public  Shootnode{
	public:
	
		Shootnode * S_head;
		Shootnode * S_tail;
		ShootPaint();
		~ShootPaint();
		void ShootUpdate(sf::Time& deltaTime,sf::Clock &shoottime);
		void ShootDraw(sf::RenderWindow &myWindow);
		void ShootAdd(double tangente,sf::Vector2f origin,sf::Color cor);
		void ShootRemove(Shootnode* rem);
		bool empty();
		void clear();

};



#endif