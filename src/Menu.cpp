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

void Menu::menuinit(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen){
	sf::Color cor(255,0,0);
	sf::Color cor1(0,255,0);
	sf::Clock timer;
	sf::Time hourglass;

	sf::Clock title;
	sf::Time titleTime;

	sf::Music Song;
	if (!Song.openFromFile("data/Lyvo - Tell Me.ogg"))
	{
		std::cout<<"DAFUQ?!"<<std::endl;
	}
	Song.play();
	Song.setLoop(true);
	int corsect = 0;
	int corsect1 = 1;

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
	choice.setPosition(sf::Vector2f(290,490));

	sf::Sprite C;
	C.setTexture(Configuration::textures.get(Configuration::Textures::C), false);
	C.setPosition(sf::Vector2f(130,30) );

	sf::Sprite O;
	O.setTexture(Configuration::textures.get(Configuration::Textures::O), false);
	O.setPosition(sf::Vector2f(240,30) );

	sf::Sprite L;
	L.setTexture(Configuration::textures.get(Configuration::Textures::L), false);
	L.setPosition(sf::Vector2f(350,30) );

	sf::Sprite O2;
	O2.setTexture(Configuration::textures.get(Configuration::Textures::O2), false);
	O2.setPosition(sf::Vector2f(460,30) );

	sf::Sprite R;
	R.setTexture(Configuration::textures.get(Configuration::Textures::R), false);
	R.setPosition(sf::Vector2f(570,30) );

	sf::Sprite BOOM;
	BOOM.setTexture(Configuration::textures.get(Configuration::Textures::BOOM), false);
	BOOM.setScale(0.7,0.7);
	BOOM.setPosition(sf::Vector2f(160,280) );

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
		titleTime = title.getElapsedTime();

		if(hourglass.asSeconds()>0.005){
			timer.restart();
			Menu::rainbow(cor,corsect);
			choice.setColor(cor);
		}

		if (titleTime.asSeconds() > 0.05)
		{
			title.restart();
			Menu::rainbow(cor1,corsect1);
			C.setColor(cor1);
			Menu::rainbow(cor1,corsect1);
			O.setColor(cor1);
			Menu::rainbow(cor1,corsect1);
			L.setColor(cor1);
			Menu::rainbow(cor1,corsect1);
			O2.setColor(cor1);
			Menu::rainbow(cor1,corsect1);
			R.setColor(cor1);
		}


		myWindow.clear();
		myWindow.draw(choice);
		myWindow.draw(C);
		myWindow.draw(O);
		myWindow.draw(L);
		myWindow.draw(O2);
		myWindow.draw(R);
		myWindow.draw(BOOM);
		myWindow.display();
		sf::Joystick::update();
		if (sf::Joystick::isButtonPressed(0,9) || sf::Joystick::isButtonPressed(1,9))
		{
			Inp.start = true;
		}

		if (Inp.start == true)
			{
				Inp.start = false;
				opt = Menu::mainmenu(myWindow,ResolutionList,camera,i,fullscreen);
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

int Menu::mainmenu(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen){
	sf::Color cor2(0,255,0);
	sf::Clock timer;
	sf::Clock tiemu;
	sf::Clock after;

	sf::Time burn;
	sf::Time warudo;
	sf::Time hourglass;

	PlayerIn Inp;

	int corsect2 = 0;
	int selection = 0;
	int i2, fullscreen2;

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
		burn = after.getElapsedTime();

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
		if(Inp.B && burn.asSeconds()>0.2){
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
					if(Inp.A && burn.asSeconds()>0.2){
						i2=i;
						fullscreen2 = fullscreen;
						Menu::menuopt(myWindow,ResolutionList,camera,i,fullscreen);
						if(i!=i2 || fullscreen != fullscreen2){
							std::ofstream myfile("data/Conf");
							if (myfile.is_open()){
								myfile <<i<<"\n"<<fullscreen;
								myfile.close();
							}
							if(fullscreen == 0){
								myWindow.create(ResolutionList[i], "COLOR BOOOM", sf::Style::Fullscreen);

							}
							else{
								myWindow.create(ResolutionList[i], "COLOR BOOOM");
							}
							if(ResolutionList[i].width % ResolutionList[i].height == ResolutionList[i].width/4){
								camera.setCenter(sf::Vector2f(400,300));
								camera.setSize(sf::Vector2f(800,600));
							}
							if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*7){
								camera.setCenter(sf::Vector2f(400,300));
								camera.setSize(sf::Vector2f(1024,640));
							}
							if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*8){
								camera.setCenter(sf::Vector2f(400,300));
								camera.setSize(sf::Vector2f(1024,600));
							}
						}
						myWindow.setView(camera);
						burn = after.restart();
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
void Menu::menuopt(sf::RenderWindow& myWindow,std::vector<sf::VideoMode>& ResolutionList,sf::View& camera, int& i,int& fullscreen){
	sf::Color cor2(0,255,0);
	sf::Clock timer;
	sf::Clock tiemu;
	sf::Clock runner;
	sf::Time run;
	sf::Time warudo;
	sf::Time hourglass;

	PlayerIn Inp;

	std::string res;

	int corsect2 = 0;
	int selection = 0;
	int c=1;

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
	while(ResolutionList[0].width!=ResolutionList[c].width && ResolutionList[0].height != ResolutionList[c].height){
		c++;
	}

	while(start == false && myWindow.isOpen()){
		hourglass = timer.getElapsedTime();
		warudo = tiemu.getElapsedTime();
		run = runner.getElapsedTime();

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
			return;
		}
		
		switch(selection)
			{
				case 0:
					opt.setPosition(sf::Vector2f(30,130));
					opt.setSize(sf::Vector2f(240,40));
					myWindow.draw(opt);
					if(Inp.x>50 && run.asSeconds()>0.2){
						while(myWindow.isOpen()){
							i--;
							if(i<0){
							i = c - 1;
							}
							if(ResolutionList[i].width % ResolutionList[i].height == ResolutionList[i].width/4 && ResolutionList[i].width>=800 && ResolutionList[i].height>=600){
								break;
							}
							if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*7 && ResolutionList[i].width>=800 && ResolutionList[i].height>=600){
								break;
							}
							if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*8 && ResolutionList[i].width>=800 && ResolutionList[i].height>=600){
								break;
							}
						}
						run = runner.restart();
					}
					if(Inp.x<-50 && run.asSeconds()>0.2){
						while(myWindow.isOpen()){
							i++;
							i = i%c;
							if(ResolutionList[i].width % ResolutionList[i].height == ResolutionList[i].width/4 && ResolutionList[i].width>=800 && ResolutionList[i].height>=600){
								break;
							}
							if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*7 && ResolutionList[i].width>=800 && ResolutionList[i].height>=600){
								break;
							}
							if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*8 && ResolutionList[i].width>=800 && ResolutionList[i].height>=600){
								break;
							}
						}
						run = runner.restart();
					}
					break;
				case 1:
					opt.setPosition(sf::Vector2f(30,280));
					opt.setSize(sf::Vector2f(240,40));
					myWindow.draw(opt);
					if(Inp.x>50 && run.asSeconds()>0.2){
						run = runner.restart();
						fullscreen++;
						fullscreen = fullscreen % 2;
					}
					if(Inp.x<-50 && run.asSeconds()>0.2){
						run = runner.restart();
						fullscreen++;
						fullscreen = fullscreen % 2;
					}
					break;
				case 2:
					opt.setPosition(sf::Vector2f(350,430));
					opt.setSize(sf::Vector2f(120,40));
					myWindow.draw(opt);
					if(Inp.A){
						return;
					}
					break;
			}
		choice.setString("Resolution:");
		choice.setPosition(sf::Vector2f(40,140));
		myWindow.draw(choice);
		choice.setString("FullScreen:");
		choice.setPosition(sf::Vector2f(40,290));
		myWindow.draw(choice);
		choice.setString("EXIT");
		choice.setPosition(sf::Vector2f(360,440));
		myWindow.draw(choice);

		res+=static_cast<std::stringstream*>( &(std::stringstream() << ResolutionList[i].width) )->str();
		res+=" x ";
		res+=static_cast<std::stringstream*>( &(std::stringstream() << ResolutionList[i].height) )->str();

		choice.setString(res);
		choice.setPosition(sf::Vector2f(500,140));
		myWindow.draw(choice);

		res="";

		if(fullscreen == 0){
			choice.setString("ON");
			choice.setPosition(sf::Vector2f(500,290));
		}
		else{
			choice.setString("OFF");
			choice.setPosition(sf::Vector2f(500,290));
		}
		myWindow.draw(choice);
		//texto.setString( static_cast<std::stringstream*>( &(std::stringstream() << Player.Score) )->str() );


		myWindow.display();


	}
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
	screen.setSize(sf::Vector2f(1024,640));
	screen.setPosition(camera.getCenter()-sf::Vector2f(512,320));
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

	bool start= false;

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

void Menu::gameover(sf::RenderWindow& myWindow, sf::View& camera){

	PlayerIn control;

	sf::RectangleShape screen;
	screen.setSize(sf::Vector2f(1024,640));
	screen.setPosition(camera.getCenter()-sf::Vector2f(512,320));
	screen.setFillColor(sf::Color::Black);

	sf::Text over;
	over.setFont(Configuration::fonts.get(Configuration::Fonts::Arcade));
	over.setCharacterSize(40);
	over.setStyle(sf::Text::Bold);
	over.setColor(sf::Color::White);
	over.setString("GAME OVER");
	over.setPosition(screen.getPosition() + sf::Vector2f(100,100));
	myWindow.clear();
	myWindow.draw(over);
	myWindow.display();

	while(!control.start)
	{
		sf::Joystick::update();
		control.InputUpdate();

	}

}
void Menu::highScore(sf::RenderWindow& myWindow, sf::View& camera, long unsigned int score){

	PlayerIn control;

	sf::RectangleShape screen;
	screen.setSize(sf::Vector2f(1024,640));
	screen.setPosition(camera.getCenter()-sf::Vector2f(512,320));
	screen.setFillColor(sf::Color::Black);

	sf::Text High;
	High.setFont(Configuration::fonts.get(Configuration::Fonts::Arcade));
	High.setCharacterSize(40);
	High.setStyle(sf::Text::Bold);
	High.setColor(sf::Color::White);
	High.setString("NEW HIGH SCORE\n");
	High.setPosition(camera.getCenter()-sf::Vector2f(512,320));

	myWindow.draw(screen);
	myWindow.draw(High);
	myWindow.display();


	while(!control.start)
	{
		sf::Joystick::update();
		control.InputUpdate();

	}


}