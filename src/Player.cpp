#include "Player.h"

PlayerGuy::PlayerGuy()
{
	//Body.setRadius(10.f);
	Body.setPosition(380.f, 280.f);
	Body.setColor(sf::Color(255,255,255));


	Body.setTexture(Configuration::textures.get(Configuration::Textures::Player), false);
	Body.setTextureRect(sf::IntRect(0,0,22,22));

	snipe.setTexture(Configuration::textures.get(Configuration::Textures::Gun), false);
	snipe.setTextureRect(sf::IntRect(0,0,11,11));
	//snipe.setSize(sf::Vector2f(10.f,10.f));
	snipe.setPosition(Body.getPosition() + sf::Vector2f(20.f,10.f));
	snipe.setOrigin(0.f , 5.f);

}


void PlayerGuy::animateBody()
{

	Body.setTextureRect(sf::IntRect(x,0,21,21));
	x = (x + 21) % (13*21);

}


void PlayerGuy::Die()
{
	sf::Color cor = Body.getColor();
	cor.a = 0;
	Body.setColor(cor);
	snipe.setColor(cor);
}

void PlayerGuy::updateScore(unsigned int points)
{

	Score += points;

}