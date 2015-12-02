#ifndef __Player__
#define __Player__

#include "Shoot.h"
#include "Config.h"

class PlayerGuy
{
	public:
	sf::Sprite Body;
	sf::Sprite snipe;
	//sf::Time shoot;
	ShootPaint gun;
	sf::Color cor;

	int x =0;
	unsigned int Life = 1;
	long unsigned int Score = 0;
	void animateBody();
	void Die();
	PlayerGuy();
	void updateScore(unsigned int points);
};

class PlayerIn
{
	public:
	bool l1 = false;
	bool l2 = false;
	bool r1 = false;
	bool r2 = false;
	bool dual = false;
	bool start = false;
	bool A = false;
	bool B = false;

	float x;
	float y;
	float z;
	float r;

	void stateClear(){
		A = false;
		B = false;
		start = false;
	}

};



#endif