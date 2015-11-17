#ifndef __Player__
#define __Player__

#include "Shoot.h"

class PlayerGuy{
	public:
	sf::CircleShape Body;
	sf::RectangleShape snipe;
	sf::Texture tx;
	sf::Texture btx;
	//sf::Time shoot;
	ShootPaint gun;
	sf::Color cor;
	int x =0;
	void animateBody(){

		Body.setTextureRect(sf::IntRect(x,0,21,21));
		x = (x + 21) % (13*21);
	}
};

class PlayerIn
{
	public:
	bool l1 = false;
	bool l2 = false;
	bool r1 = false;
	bool r2 = false;
	bool dual = false;

	float x;
	float y;
	float z;
	float r;

};



#endif