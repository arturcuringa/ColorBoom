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

	int opt;

	sf::Event ev;
	
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
		while(myWindow.pollEvent(ev)){
			switch(ev.type){
			
			case sf::Event::JoystickConnected:
				std::cout<<"\nJoystickConnected!!\n";
				break;
			case sf::Event::Closed:
				myWindow.close();
				break;
			default:
					break;
			}
		}

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
		if (sf::Joystick::isButtonPressed(0,9) || sf::Joystick::isButtonPressed(1,9))
		{
			Inp.start = true;
		}

		if (Inp.start == true)
			{
				Inp.start = false;
				opt = Menu::mainmenu(myWindow);
				if(opt == 0)
				{
					return;
				}
				if(opt == 2)
				{
					myWindow.close();
					return;
				}
				
			}
	}

}

int Menu::mainmenu(sf::RenderWindow& myWindow){
	sf::Color cor2(0,255,0);
	sf::Clock timer;
	sf::Clock tiemu;
	sf::Time warudo;
	sf::Time hourglass;

	PlayerIn Inp;

	int corsect2 = 0;
	int selection = 0;

	sf::RectangleShape opt;
	opt.setOutlineThickness(3);

	sf::Event ev;

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

		while(myWindow.pollEvent(ev)){
			switch(ev.type){
			
			case sf::Event::JoystickConnected:
				std::cout<<"\nJoystickConnected!!\n";
				break;
			case sf::Event::Closed:
				myWindow.close();
				break;
			default:
					break;
			}
		}

		if(hourglass.asSeconds()>0.005){
			timer.restart();

			Menu::rainbow(cor2,corsect2);
			opt.setOutlineColor(cor2);
			opt.setFillColor(sf::Color(0,0,0,0));
		}
		Inp.stateClear();
		sf::Joystick::update();
		Inp.PlayerMove();
		Inp.InputUpdate();



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

		


		myWindow.clear();
		if(Inp.B){
			return 1;
		}
		
		switch(selection)
			{
				case 0:
					opt.setPosition(sf::Vector2f(330,120));
					opt.setSize(sf::Vector2f(140,60));
					myWindow.draw(opt);
					if(Inp.A){
						return selection;
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
						return selection;
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
	return false;
}
int Menu::pausemenu(sf::RenderWindow& myWindow,sf::View& camera,PlayerGuy& Player,MAP& Map,ShipsPaint& ShipList,sf::Text& texto){
	sf::Color cor(255,0,0,0);
	sf::Clock timer;
	sf::Clock tiemu;
	sf::Time warudo;
	sf::Time hourglass;

	PlayerIn Inp;

	sf::Event ev;

	int corsect = 0;
	int selection = 0;

	sf::RectangleShape screen;
	screen.setSize(sf::Vector2f(800,600));
	screen.setPosition(camera.getCenter()-sf::Vector2f(400,300));
	screen.setFillColor(cor);

	sf::RectangleShape opt;
	opt.setOutlineThickness(6);
	opt.setOutlineColor(sf::Color::Black);
	opt.setFillColor(sf::Color::White);

	sf::Text choice;
	choice.setFont(Configuration::fonts.get(Configuration::Fonts::Arcade));
	choice.setCharacterSize(20);
	choice.setStyle(sf::Text::Bold);
	choice.setColor(sf::Color::Black);
	//choice.setString("PRESS START");
	//choice.setColor();
	//choice.setPosition(sf::Vector2f(290,290));

	bool start=false;

	while(start == false && myWindow.isOpen()){

		while(myWindow.pollEvent(ev)){
			switch(ev.type){
			
			case sf::Event::JoystickConnected:
				std::cout<<"\nJoystickConnected!!\n";
				break;
			case sf::Event::Closed:
				myWindow.close();
				break;
			default:
					break;
			}
		}

		hourglass = timer.getElapsedTime();
		warudo = tiemu.getElapsedTime();
		while(cor.a<100){
			hourglass = timer.getElapsedTime();
			if(hourglass.asSeconds()>0.005){
				timer.restart();
				cor.a+=5;
				Menu::rainbow(cor,corsect);
				screen.setFillColor(cor);
			}
			myWindow.clear();
			myWindow.draw (Map.Body);
			ShipList.ShipsDraw(myWindow);
			Player.gun.ShootDraw(myWindow);
			myWindow.draw (Player.Body);
			myWindow.draw (Player.snipe);
			myWindow.draw (texto);
			myWindow.draw (screen);
			myWindow.display();

		}


		if(hourglass.asSeconds()>0.0005){
			timer.restart();

			Menu::rainbow(cor,corsect);
			screen.setFillColor(cor);

			//opt.setOutlineColor(cor2);
			//opt.setFillColor(cor);
		}

		Inp.stateClear();
		sf::Joystick::update();
		Inp.PlayerMove();
		Inp.InputUpdate();


		if(Inp.y>50 && warudo.asSeconds()>0.2){
			warudo = tiemu.restart();
			selection++;
			selection = selection % 4;
		}
		if(Inp.y<-50 && warudo.asSeconds()>0.2){
			warudo = tiemu.restart();
			selection--;
			if(selection<0){
				selection = 3;
			}
		}


		myWindow.clear();
			myWindow.draw (Map.Body);
			ShipList.ShipsDraw(myWindow);
			Player.gun.ShootDraw(myWindow);
			myWindow.draw (Player.Body);
			myWindow.draw (Player.snipe);
			myWindow.draw (texto);
			myWindow.draw (screen);

		if(Inp.B){
			return 0;
		}
		if(Inp.start){
			return 0;
		}
		
		switch(selection)
			{
				case 0:
					opt.setPosition(camera.getCenter() + sf::Vector2f(-70,-160));
					opt.setSize(sf::Vector2f(140,40));
					myWindow.draw(opt);
					if(Inp.A){
						return selection;
					}
					break;
				case 1:
					opt.setPosition(camera.getCenter() + sf::Vector2f(-60,-60));
					opt.setSize(sf::Vector2f(120,40));
					myWindow.draw(opt);
					if(Inp.A){
						return selection;
					}
					break;
				case 2:
					opt.setPosition(camera.getCenter() + sf::Vector2f(-200,40));
					opt.setSize(sf::Vector2f(420,40));
					myWindow.draw(opt);
					if(Inp.A){
						return selection;
					}
					break;
				case 3:
					opt.setPosition(camera.getCenter() + sf::Vector2f(-50,140));
					opt.setSize(sf::Vector2f(100,40));
					myWindow.draw(opt);
					if(Inp.A){
						return selection;
					}
					break;
			}
		choice.setString("RESUME");
		choice.setPosition(camera.getCenter() + sf::Vector2f(-60,-150));
		myWindow.draw(choice);

		choice.setString("RESET");
		choice.setPosition(camera.getCenter() + sf::Vector2f(-50,-50));
		myWindow.draw(choice);

		choice.setString("RETURN TO MAIN MENU");
		choice.setPosition(camera.getCenter() + sf::Vector2f(-190,50));
		myWindow.draw(choice);

		choice.setString("EXIT");
		choice.setPosition(camera.getCenter() + sf::Vector2f(-40,150));
		myWindow.draw(choice);
		myWindow.display();


	}
	return 0;
}