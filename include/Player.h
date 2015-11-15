#ifndef __Player__
#define __Player__


class PlayerGuy{
	public:
	sf::CircleShape Body;
	sf::RectangleShape snipe;
	//sf::Time shoot;
	bool ismovingUp = false;
	bool ismovingLeft = false;
	bool ismovingRight = false;
	bool ismovingDown = false;
};



#endif