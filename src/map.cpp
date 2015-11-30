#include "map.h"


MAP::MAP(){
	
	Body.setSize(sf::Vector2f(1280.f, 720.f));
	Body.setPosition(sf::Vector2f(0, 0));
	Body.setFillColor(sf::Color(0,0,0));
	Body.setOutlineThickness(10.f);
	Body.setOutlineColor(sf::Color::White);

	Body.setTexture(&Configuration::textures.get(Configuration::Textures::Mapa), false);
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

void
MAP::outside(sf::Vector2f Position, sf::FloatRect TestSub, sf::Vector2f& Correct){
	sf::FloatRect Result;

	Body.getGlobalBounds().intersects(TestSub, Result);



	if (Result != TestSub )
	{
		if (Result.width < TestSub.width)
		{
			if (Result.height == TestSub.height){
				Correct.y *=100;
			}

			if (Position.x > 10){
				if(Correct.x>0){
					Correct.x = 0;
				}
				else{
					Correct.x *=100;
				}
			}
			else{
				if(Correct.x<0){
					Correct.x = 0;
				}
				else{
					Correct.x *=100;
				}
			}
			
		}
		if (Result.height < TestSub.height)
		{
			if (Result.width == TestSub.width){
				Correct.x *=100;
			}

			if (Position.y > 10){
				if(Correct.y>0){
					Correct.y = 0;
				}
				else{
					Correct.y *=100;
				}
			}
			else{
				if(Correct.y<0){
					Correct.y = 0;
				}
				else{
					Correct.y *=100;
				}
			}
		}
		
	}
	else{
		Correct.y*=100;
		Correct.x*=100;
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
		
	return test;*/
	
	
}