#ifndef __Shoot__
#define __Shoot__

#include <math.h>
#include <SFML/Graphics.hpp>

class ShootPaint{
	public:
		struct Shootnode
		{	
			double tang;
			sf::Vector2f total;
			sf::CircleShape ammo;
			Shootnode *next;
			
		};

		Shootnode * S_head;
		Shootnode * S_tail;
		ShootPaint();
		~ShootPaint();
		void ShootUpdate(sf::Time deltaTime);
		void ShootDraw(sf::RenderWindow &myWindow);
		void ShootAdd(double tangente,sf::Vector2f origin,sf::Color cor);
		void ShootRemove(Shootnode* prev,Shootnode* rem);


};

#endif