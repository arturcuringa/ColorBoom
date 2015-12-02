#include "Menu.h"

void Menu::rainbow(sf::Color &cor,int &corsect){

			if(cor.r==255 && cor.g==0 && cor.b==0){
				corsect = 0;
			}
			if(cor.r==0 && cor.g==255 && cor.b==0){
				corsect = 2;
			}
			if(cor.r==0 && cor.g==0 && cor.b==255){
				corsect = 4;
			}
			if(cor.r==255 && cor.g==255 && cor.b==0){
				corsect = 1;
			}			
			if(cor.r==0 && cor.g==255 && cor.b==255){
				corsect = 3;
			}			
			if(cor.r==255 && cor.g==0 && cor.b==255){
				corsect = 5;
			}


			switch(corsect)
			{
				case 0:
					cor.g+=5;	
					break;
				case 1:
					cor.r-=5;		
					break;
				case 2:
					cor.b+=5;	
					break;
				case 3:
					cor.g-=5;	
					break;
				case 4:
					cor.r+=5;	
					break;
				case 5:
					cor.b-=5;		
					break;
			}
}

void Menu::menuinit(sf::RenderWindow& myWindow){
	sf::Color cor(255,0,0);
	sf::Clock timer;
	sf::Time hourglass;

	int corsect = 0;
	myWindow.clear();

	PlayerIn Inp;
	
	sf::Text choice;
	choice.setFont(Configuration::fonts.get(Configuration::Fonts::Arcade));
	choice.setCharacterSize(20);
	choice.setStyle(sf::Text::Bold);
	choice.setColor(sf::Color::White);
	choice.setString("PRESS START");
	choice.setColor(cor);
	choice.setPosition(sf::Vector2f(290,290));

	bool start=false;

	while(start == false && myWindow.isOpen()){

		hourglass = timer.getElapsedTime();

		if(hourglass.asSeconds()>0.005){
			timer.restart();
			Menu::rainbow(cor,corsect);

			choice.setColor(cor);
		}
		myWindow.clear();
		myWindow.draw(choice);
		myWindow.display();
		sf::Joystick::update();
		if (sf::Joystick::isButtonPressed(0,9))
		{
			Inp.start = true;
		}

		if (Inp.start == true)
			{
				Inp.start = false;
				if(Menu::mainmenu(myWindow)){
					return;
				}
			}
	}

}

bool Menu::mainmenu(sf::RenderWindow& myWindow){
	sf::Color cor(255,0,0);
	sf::Color cor2(0,255,0);
	sf::Clock timer;
	sf::Clock tiemu;
	sf::Time warudo;
	sf::Time hourglass;

	PlayerIn Inp;

	int corsect = 0;
	int corsect2 = 0;
	int selection = 0;

	sf::RectangleShape opt;
	opt.setOutlineThickness(3);

	sf::Text choice;
	choice.setFont(Configuration::fonts.get(Configuration::Fonts::Arcade));
	choice.setCharacterSize(20);
	choice.setStyle(sf::Text::Bold);
	choice.setColor(sf::Color::White);
	//choice.setString("PRESS START");
	//choice.setColor();
	//choice.setPosition(sf::Vector2f(290,290));

	bool start=false;

	while(start == false && myWindow.isOpen()){
		hourglass = timer.getElapsedTime();
		warudo = tiemu.getElapsedTime();


		if(hourglass.asSeconds()>0.005){
			timer.restart();

			Menu::rainbow(cor,corsect);
			Menu::rainbow(cor2,corsect2);
			opt.setOutlineColor(cor2);
			opt.setFillColor(cor);
		}

		sf::Joystick::update();
		Inp.x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
		Inp.y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
		Inp.z = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
		Inp.r = sf::Joystick::getAxisPosition(1, sf::Joystick::V);

		Inp.x += sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		Inp.y += sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		Inp.z += sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
		Inp.r += sf::Joystick::getAxisPosition(0, sf::Joystick::R);
		Inp.z += sf::Joystick::getAxisPosition(0, sf::Joystick::U);
		Inp.r += sf::Joystick::getAxisPosition(0, sf::Joystick::V);



		if(Inp.y>50 && warudo.asSeconds()>0.2){
			warudo = tiemu.restart();
			selection++;
			selection = selection % 3;
		}
		if(Inp.y<-50 && warudo.asSeconds()>0.2){
			warudo = tiemu.restart();
			selection--;
			if(selection<0){
				selection = 2;
			}
		}
		Inp.stateClear();
		

		if (sf::Joystick::isButtonPressed(1,5))
		{
			Inp.r1 = true;
		}
		if (sf::Joystick::isButtonPressed(1,4))
		{
			Inp.l1 = true;
		}
		if (sf::Joystick::isButtonPressed(1,7))
		{
			Inp.r2 = true;
		}
		if (sf::Joystick::isButtonPressed(1,6))
		{
			Inp.l2 = true;
		}
		if (sf::Joystick::isButtonPressed(0,5))
		{
			Inp.r1 = true;
		}
		if (sf::Joystick::isButtonPressed(0,4))
		{
			Inp.l1 = true;
		}
		if (sf::Joystick::isButtonPressed(0,7))
		{
			Inp.r2 = true;
		}
		if (sf::Joystick::isButtonPressed(0,6))
		{
			Inp.l2 = true;
		}
		if (sf::Joystick::isButtonPressed(0,9))
		{
			Inp.start = true;
		}

		if (sf::Joystick::isButtonPressed(1,9))
		{
			Inp.start = true;
		}
		if (sf::Joystick::isButtonPressed(0,0))
		{
			Inp.A = true;
		}

		if (sf::Joystick::isButtonPressed(1,0))
		{
			Inp.A = true;
		}
		if (sf::Joystick::isButtonPressed(0,1))
		{
			Inp.B = true;
		}

		if (sf::Joystick::isButtonPressed(1,1))
		{
			Inp.B = true;
		}	

		myWindow.clear();
		if(Inp.B){
			return false;
		}
		
		switch(selection)
			{
				case 0:
					opt.setPosition(sf::Vector2f(330,120));
					opt.setSize(sf::Vector2f(140,60));
					myWindow.draw(opt);
					if(Inp.A){
						return true;
					}
					break;
				case 1:
					opt.setPosition(sf::Vector2f(310,270));
					opt.setSize(sf::Vector2f(180,60));
					myWindow.draw(opt);
					if(Inp.A){
						myWindow.close();
					}
					break;
				case 2:
					opt.setPosition(sf::Vector2f(340,420));
					opt.setSize(sf::Vector2f(120,60));
					myWindow.draw(opt);
					if(Inp.A){
						myWindow.close();
					}
					break;
			}
		choice.setString("START");
		choice.setPosition(sf::Vector2f(350,140));
		myWindow.draw(choice);
		choice.setString("OPTIONS");
		choice.setPosition(sf::Vector2f(330,290));
		myWindow.draw(choice);
		choice.setString("EXIT");
		choice.setPosition(sf::Vector2f(360,440));
		myWindow.draw(choice);
		myWindow.display();


	}
}