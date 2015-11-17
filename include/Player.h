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
	bool ismovingUp = false;
	bool ismovingLeft = false;
	bool ismovingRight = false;
	bool ismovingDown = false;
};



#endif