#include "map.h"


MAP::MAP(){
	
	Body.setSize(sf::Vector2f(1280.f, 720.f));
	Body.setPosition(sf::Vector2f(0, 0));
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
MAP::outside(sf::Vector2f Position, sf::FloatRect TestSub, sf::Vector2f& Correct){
	bool test = false;

	sf::FloatRect Result;

	Body.getGlobalBounds().intersects(TestSub, Result);



	if (Result != TestSub )
	{
		if (Result.width < TestSub.width)
		{
			test =true;
			Correct.y *=150;

			if (Position.x > 10)
				Correct.x = -1;
			else
				Correct.x = 1;
			
		}
		if (Result.height < TestSub.height)
		{
			test =true;
			Correct.x *=150;

			if (Position.y > 10)
				Correct.y = -1;
			else
				Correct.y = 1;
			
		}
		
	}


	/*
	//Up Test
	if (!Body.getGlobalBounds().contains(Position.x + TestSub.width/2 , Position.y ))
	{
		Correct.y = 0;
		Correct.x *=150;
		test = true;
	}

	//Right Test
	if (!Body.getGlobalBounds().contains(Position.x + TestSub.width , Position.y + TestSub.height/2))
	{
		Correct.x = 0;
		Correct.y *=150;
		test = true;
	}

	//Left test
	if (!Body.getGlobalBounds().contains(Position.x , Position.y + TestSub.height/2 ))
	{
		Correct.x = 0;
		Correct.y *=150;
		test =true;
	}

	//Down Test
	if (!Body.getGlobalBounds().contains(Position.x + TestSub.width/2 , Position.y + TestSub.height ))
	{
		Correct.y = 0;
		Correct.x *=150;
		test = true;
	}
		*/
	return test;
	
	
}