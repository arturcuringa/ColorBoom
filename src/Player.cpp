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

	SpecialFill.setFillColor(sf::Color::Green);

	SpecialBar.setFillColor(sf::Color::Transparent);
	SpecialBar.setOutlineThickness(1.f);
	SpecialBar.setOutlineColor(sf::Color::White);
	SpecialBar.setSize(sf::Vector2f(100.f, 10.f));
}


void PlayerGuy::animateBody()
{

	Body.setTextureRect(sf::IntRect(x,0,21,21));
	x = (x + 21) % (13*21);

}
void PlayerGuy::clear()
{
	Body.setPosition(380.f, 280.f);
	Body.setColor(sf::Color(255,255,255));

	Body.setTextureRect(sf::IntRect(0,0,22,22));

	snipe.setTextureRect(sf::IntRect(0,0,11,11));

	gun.clear();
 
	snipe.setPosition(Body.getPosition() + sf::Vector2f(20.f,10.f));
	snipe.setRotation(0);
	x = 0;
	Life = 3;
	Score = 0;
	PowerBar = 100;

}


bool PlayerGuy::Die()
{
	sf::Color cor = Body.getColor();
	cor.a = 0;
	Body.setColor(cor);
	snipe.setColor(cor);
	Life--;
	if (Life == 0)
	{
		return true;
	}
	return false;
}

void PlayerGuy::updateScore(unsigned int points)
{

	Score += points;
	if (Score >= 5000 * bonus )
	{
		Life++;
		bonus++;
	}

}

void PlayerGuy::GrowSpecialBar()
{
	PowerBar++;
}

void PlayerGuy::DecraseSpecialBar()
{
	PowerBar--;
}