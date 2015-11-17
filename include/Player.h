#ifndef __Player__
#define __Player__

#include "Shoot.h"

class PlayerGuy{
	public:
	sf::CircleShape Body;
	sf::RectangleShape snipe;
	//sf::Time shoot;
	ShootPaint gun;
	sf::Color cor;
	
};

class PlayerIn
{
	public:
	bool l1 = false;
	bool l2 = false;
	bool r1 = false;
	bool r2 = false;

	float x;
	float y;
	float z;
	float r;

};



#endif