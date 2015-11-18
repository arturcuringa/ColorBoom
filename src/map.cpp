#include "map.h"


MAP::MAP(){
	
	Body.setSize(sf::Vector2f(1280.f, 720.f));
	Body.setPosition(sf::Vector2f(-112.f, -134));
	Body.setFillColor(sf::Color(0,0,0));
	Body.setOutlineThickness(10.f);
	Body.setOutlineColor(sf::Color::White);

	sky.loadFromFile("Sky.png");
	Body.setTexture(&sky, false);
	blink = 0;
	grow = true;

}

void
MAP::update(sf::Clock& hourglass){
	sf::Time t = hourglass.getElapsedTime();
	if(t.asSeconds()>0.015)
	{
		hourglass.restart();
		
		if(blink == 255)
		{
			grow = false;
		}
		if(blink == 0)
		{
			grow = true;
		}
		if(grow==true)
		{
			blink = blink + 5;
		}
		else
		{
			blink = blink - 5;
		}
		Body.setFillColor(sf::Color(blink,blink,blink));

	}

}

bool
MAP::outside(sf::Vector2f Position, sf::FloatRect TestSub){

	if (!Body.getGlobalBounds().contains(Position  - sf::Vector2f(10.f,10.f) ))
	{
		return true;
	}

	if (!Body.getGlobalBounds().contains(sf::Vector2f(Position.x + TestSub.width + 10.f, Position.y) ) )
	{
		return true;
	}
	if (!Body.getGlobalBounds().contains(Position.x , Position.y + TestSub.height + 10.f))
	{
		return true;
	}

	return false;
}