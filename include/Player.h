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
	long unsigned int Score = 0;
	void animateBody(){

		Body.setTextureRect(sf::IntRect(x,0,21,21));
		x = (x + 21) % (13*21);
	}
	PlayerGuy()
	{
		Body.setRadius(10.f);
		Body.setPosition(380.f, 280.f);
		Body.setFillColor(sf::Color(255,255,255));
		
		btx.loadFromFile("LJ FINAL white.png");

		Body.setTexture(&btx, false);
		Body.setTextureRect(sf::IntRect(0,0,22,22));


		tx.loadFromFile("ARROWS.png");
		snipe.setTexture(&tx, false);
		snipe.setTextureRect(sf::IntRect(0,0,11,11));
		snipe.setSize(sf::Vector2f(10.f,10.f));
		snipe.setPosition(Body.getPosition() + sf::Vector2f(20.f,10.f));
		snipe.setOrigin(0.f , 5.f);

	}
	void updateScore(unsigned int points){

		Score += points;

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