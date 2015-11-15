#ifndef __Shoot__
#define __Shoot__

#include <math.h>
#include <SFML/Graphics.hpp>

class ShootPaint{
	public:
		struct Shootnode
		{	
			double tang;
			sf::Vector2f orig;
			sf::CircleShape ammo;
			Shootnode *next;
			
		};

		Shootnode * head;
		Shootnode * tail;
		ShootPaint();
		~ShootPaint();
		void ShootUpdate();
		void ShootAdd(double tangente,sf::Vector2f origin,sf::Color cor);
		void ShootRemove(Shootnode* prev,Shootnode* rem);


};

#endif