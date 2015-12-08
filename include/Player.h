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
	sf::RectangleShape SpecialFill;
	sf::RectangleShape SpecialBar;

	int PowerBar = 100;
	bool SpecialTrigger = false;

	int x =0;
	
	unsigned int Life = 3;
	long unsigned int Score = 0;
	unsigned int bonus = 1;

	void animateBody();
	void clear();
	bool Die();
	PlayerGuy();
	void updateScore(unsigned int points);
	void GrowSpecialBar();
	void DecraseSpecialBar();
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
	void InputUpdate(){

		if (sf::Joystick::isButtonPressed(1,5))
		{
			 r1 = true;
		}
		if (sf::Joystick::isButtonPressed(1,4))
		{
			 l1 = true;
		}
		if (sf::Joystick::isButtonPressed(1,7))
		{
			 r2 = true;
		}
		if (sf::Joystick::isButtonPressed(1,6))
		{
			 l2 = true;
		}
		if (sf::Joystick::isButtonPressed(0,5))
		{
			 r1 = true;
		}
		if (sf::Joystick::isButtonPressed(0,4))
		{
			 l1 = true;
		}
		if (sf::Joystick::isButtonPressed(0,7))
		{
			 r2 = true;
		}
		if (sf::Joystick::isButtonPressed(0,6))
		{
			 l2 = true;
		}
		if (sf::Joystick::isButtonPressed(0,9))
		{
			 start = true;
		}

		if (sf::Joystick::isButtonPressed(1,9))
		{
			 start = true;
		}
		if (sf::Joystick::isButtonPressed(0,0))
		{
			 A = true;
		}

		if (sf::Joystick::isButtonPressed(1,0))
		{
			 A = true;
		}
		if (sf::Joystick::isButtonPressed(0,1))
		{
			 B = true;
		}

		if (sf::Joystick::isButtonPressed(1,1))
		{
			 B = true;
		}

	}

	void PlayerMove(){

	 x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
	 y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
	 z = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
	 r = sf::Joystick::getAxisPosition(1, sf::Joystick::V);

	 x += sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	 y += sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	 z += sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
	 r += sf::Joystick::getAxisPosition(0, sf::Joystick::R);
	 z += sf::Joystick::getAxisPosition(0, sf::Joystick::U);
	 r += sf::Joystick::getAxisPosition(0, sf::Joystick::V);
}

};



#endif