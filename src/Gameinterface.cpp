#include "Gameinterface.h"

GameInterface::GameInterface()
{	
	ResolutionList = sf::VideoMode::getFullscreenModes() ;

	std::ifstream myfile("data/Conf");

	if (myfile.is_open())
	{
		std::string line;
		std::string::size_type sz;
		std::getline(myfile,line);
		i =	std::stoi(line, &sz);
		std::getline(myfile,line);
		fullscreen = std::stoi(line, &sz);
		myfile.close();
	}
	/*while(i<ResolutionList.size()-1){
		if(ResolutionList[i].width >= 800 && ResolutionList[i].height >= 600 ){
			std::cout<<i<<" "<<ResolutionList[i].width<<" "<<ResolutionList[i].height<<std::endl;
		}
		i++;
	}*/
	if(fullscreen==0){
		myWindow.create(ResolutionList[i], "COLOR BOOOM", sf::Style::Fullscreen);
	}
	else{
		myWindow.create(ResolutionList[i], "COLOR BOOOM");
	}
		
	Score.setFont(Configuration::fonts.get(Configuration::Fonts::Arcade));
	Score.setCharacterSize(20);
	Score.setStyle(sf::Text::Bold);
	Score.setColor(sf::Color::White);

	Life.setFont(Configuration::fonts.get(Configuration::Fonts::Arcade));
	Life.setCharacterSize(20);
	Life.setStyle(sf::Text::Bold);
	Life.setColor(sf::Color::White);



	if(ResolutionList[i].width % ResolutionList[i].height == ResolutionList[i].width/4){
		Camera.setCenter(sf::Vector2f(400,300));
		Camera.setSize(sf::Vector2f(800,600));
		Score.setPosition(Camera.getCenter() + sf::Vector2f(-400,-300));
		Life.setPosition(Camera.getCenter() + sf::Vector2f( 360,-300));
	}
	if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*7){
		Camera.setCenter(sf::Vector2f(400,300));
		Camera.setSize(sf::Vector2f(1024,640));
		Score.setPosition(Camera.getCenter() + sf::Vector2f(-512,-320));
		Life.setPosition(Camera.getCenter() + sf::Vector2f(472,-320));
	}
	if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*8){
		Camera.setCenter(sf::Vector2f(400,300));
		Camera.setSize(sf::Vector2f(1024,600));
		Score.setPosition(Camera.getCenter() + sf::Vector2f(-512,-300));
		Life.setPosition(Camera.getCenter() + sf::Vector2f(472,-300));

	}
	myWindow.setView(Camera);

	points = 100;

}
void GameInterface::clear(){
	Player.clear();
	ShipList.clear();
	Map.blink = 0;
	Map.grow = true;

	if(ResolutionList[i].width % ResolutionList[i].height == ResolutionList[i].width/4){
		Camera.setCenter(sf::Vector2f(400,300));
		Camera.setSize(sf::Vector2f(800,600));
		Score.setPosition(Camera.getCenter() + sf::Vector2f(-400,-300));
		Life.setPosition(Camera.getCenter() + sf::Vector2f( 360,-300));
	}
	if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*7){
		Camera.setCenter(sf::Vector2f(400,300));
		Camera.setSize(sf::Vector2f(1024,640));
		Score.setPosition(Camera.getCenter() + sf::Vector2f(-512,-320));
		Life.setPosition(Camera.getCenter() + sf::Vector2f(472,-320));
	}
	if(ResolutionList[i].width % ResolutionList[i].height == (ResolutionList[i].width/16)*8){
		Camera.setCenter(sf::Vector2f(400,300));
		Camera.setSize(sf::Vector2f(1024,600));
		Score.setPosition(Camera.getCenter() + sf::Vector2f(-512,-300));
		Life.setPosition(Camera.getCenter() + sf::Vector2f(472,-300));
	}

	myWindow.setView(Camera);
	myWindow.clear();

}

void GameInterface::GameLoop(){
	while(myWindow.isOpen()){
		clear();

		sf::Music Song;

		if (!Song.openFromFile("data/Lyvo - Tell Me.ogg"))
		{
			std::cout<<"DAFUQ?!"<<std::endl;
		}

		Song.play();
		Song.setLoop(true);

		Menu::menuinit(myWindow,ResolutionList,Camera,i,fullscreen);

		Song.stop();

		if(myWindow.isOpen()){
			clear();
		}

		if(myWindow.isOpen()){
			sf::Sound Enter(Configuration::SoundEffects.get(Configuration::Sounds::select) );
			Enter.play();
			Start();
		}
		if(myWindow.isOpen()){
			sf::Sound Tick(Configuration::SoundEffects.get(Configuration::Sounds::Menu) );
			Tick.play();
			if (Score::checkScore(Player.Score))
			{
				Menu::highScore(myWindow,Camera, Player.Score);
			}
			else{
				Menu::gameover(myWindow, Camera);
			}
		}
	}
}

void GameInterface::Start()
{	
	sf::Sound Tick(Configuration::SoundEffects.get(Configuration::Sounds::Menu) );
	ingame = true;
	int opt;

	sf::Clock shoottime;
	sf::Clock clock;
	sf::Clock timer;
	sf::Clock tiemu;
	sf::Clock GameTime;

	sf::Time PointTime;
	sf::Time PerFrame = sf::seconds(1.f/60.f);
	sf::Time SinceLastTry;
	sf::Clock SpecialClock;

	sf::Music Song;
	if (!Song.openFromFile("data/On the Run.ogg"))
	{
		std::cout<<"DAFUQ?!"<<std::endl;
	}
	Song.play();
	Song.setLoop(true); 

	while(ingame){
		PointTime = GameTime.getElapsedTime();

		if(PointTime.asSeconds()>1){
			GameTime.restart();
			points = points - 5;
			if(points<30){
				points =30;
			}
		}
		
		Inp.stateClear();
		SinceLastTry += clock.restart();
		while(SinceLastTry > PerFrame)
		{
			SinceLastTry -= PerFrame;
			EventInput();
			update(PerFrame,timer,tiemu,shoottime, SpecialClock);
		}

		if(Inp.start){
				
				opt = Menu::pausemenu(myWindow,Camera,Player,Map,ShipList,Score);
				Tick.play();
				if(opt == 1)
				{
					clear();
				}
				if(opt == 2)
				{
					ingame = false;
				}
				if(opt == 3)
				{
					ingame = false;
					myWindow.close();
				}
				clock.restart();
				shoottime.restart();
				GameTime.restart();
				timer.restart();
				tiemu.restart();
			}
		render();
		if(!myWindow.isOpen()){
			ingame = false;
		}

	}
	Song.stop();
	
}

void GameInterface::render()
{
	myWindow.clear();

	myWindow.draw(Map.Body);
	myWindow.setView(Camera);
	Player.gun.ShootDraw(myWindow);
	ShipList.ShipsDraw(myWindow);
	myWindow.draw(Player.Body);
	myWindow.draw(Player.snipe);

	myWindow.draw(Score);
	myWindow.draw(Life);

	myWindow.draw(Player.SpecialFill);
	myWindow.draw(Player.SpecialBar);
	myWindow.display();
}

void GameInterface::PlayerInput()
{

		if (Inp.l1 && Inp.l2 && Inp.r2)
		{
			Inp.l1 = false;
			Inp.l2 = false;
			Inp.r2 = false;
			return ;
		}

		if (Inp.l1 && Inp.l2)
		{
			Player.cor = sf::Color(255,255,0);
			Inp.l1 = false;
			Inp.l2 = false;
			
		}else if (Inp.l1 && Inp.r2)
		{
			Player.cor = sf::Color(255,0,255);
			Inp.l1 = false;
			Inp.r2 = false;
			
		}else if (Inp.l2 && Inp.r2)
		{
			Player.cor = sf::Color(0,255,255);
			Inp.l2 = false;
			Inp.r2 = false;
			
		}else if (Inp.l1)
		{
			Player.cor = sf::Color(255,0,0);
			Inp.l1 = false;
		}else if (Inp.l2)
		{
			Player.cor = sf::Color(0,255,0);
			Inp.l2 = false;
		}else if (Inp.r2)
		{
			Player.cor = sf::Color(50,50,255);
			Inp.r2 = false;
		}
		if(Player.cor!=sf::Color(0,0,0))
		{
			Player.Body.setColor(Player.cor);
			Player.snipe.setColor(Player.cor);
		}

		if (Inp.B)
		{
			Player.SpecialTrigger= true;
		}
	
}


void GameInterface::EventInput()
{

	sf::Event ev;

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

		Inp.InputUpdate();
	
		Inp.PlayerMove();

	}

}

void GameInterface::collision(){


	if(ShipList.S_head->next == ShipList.S_tail){
		return;
	}
	else{

		ShootPaint::Shootnode *auShoot;
		auShoot=Player.gun.S_head->next;
		Shipnode * auShip;
		auShip = ShipList.S_head->next;



		while(auShip != ShipList.S_tail ){


			if( Player.Body.getGlobalBounds().intersects(auShip->body.getGlobalBounds())){

				ShipList.ShipsRemove(auShip);
				Sounds.push_back(sf::Sound(Configuration::SoundEffects.get(Configuration::Sounds::PExplo) ) );
				Sounds.back().setVolume(55);
				Sounds.back().play();
				ShipList.clear();
				Player.gun.clear();
				Player.PowerBar = 100;
				if (Player.Die())
				{
					
					ingame = false;

				}
				return;
			}

			else if(Player.gun.S_head->next!=Player.gun.S_tail){
				while(auShoot != Player.gun.S_tail){
					
					if( auShoot->ammo.getGlobalBounds().intersects(auShip->body.getGlobalBounds()) && auShoot->ammo.getFillColor() == auShip->body.getColor()){

						Player.gun.ShootRemove(auShoot);
						ShipList.ShipsRemove(auShip);	
						Sounds.push_back(sf::Sound(Configuration::SoundEffects.get(Configuration::Sounds::Explo) ) );
						Sounds.back().setVolume(55);
						Sounds.back().play();

						Player.updateScore(points);
						if (Player.PowerBar<100)
						{
							Player.GrowSpecialBar();
						}
							
						collision();
						return;
					}

					else{
						auShoot = auShoot->next;
					}
				}
			}
			if(auShip->next == nullptr){
				break;
			}
			auShoot=Player.gun.S_head;
			//std::cout<<c<<std::endl;
			auShip = auShip->next;


		}

	}
}

void GameInterface::preload(int enemys){

	float x1, y1;
	int i =0;
	points = 100;

		while(i<enemys){
			x1 = rand() % 1280;
			y1 = rand() % 720;	

			while(sqrt(pow(Player.Body.getPosition().x - x1, 2) + pow(Player.Body.getPosition().y - y1, 2) ) < 300.f){
				x1 = rand() % 1280;
				y1 = rand() % 720;
			}

			int cor = static_cast<int>(x1) % 6;

			switch(cor)
			{
				case 0:
					ShipList.ShipsAdd(sf::Vector2f(x1,y1),sf::Color(255,255,0));				
					break;
				case 1:
					ShipList.ShipsAdd(sf::Vector2f(x1,y1),sf::Color(255,0,255));				
					break;
				case 2:
					ShipList.ShipsAdd(sf::Vector2f(x1,y1),sf::Color(0,255,255));				
					break;
				case 3:
					ShipList.ShipsAdd(sf::Vector2f(x1,y1),sf::Color(255,0,0));				
					break;
				case 4:
					ShipList.ShipsAdd(sf::Vector2f(x1,y1),sf::Color(0,255,0));				
					break;
				case 5:
					ShipList.ShipsAdd(sf::Vector2f(x1,y1),sf::Color(50,50,255));				
					break;
		
			}

			i++;

		}

}

bool GameInterface::soundoff(const sf::Sound& test){ return (test.getStatus() != sf::SoundSource::Status::Playing);}


void GameInterface::update(sf::Time deltaTime,sf::Clock &timer,sf::Clock &tiemu,sf::Clock &shoottime,sf::Clock&  SpecialClock){


	PlayerInput();

	sf::Time watch = timer.getElapsedTime();
	sf::Time hourglass = tiemu.getElapsedTime();
	sf::Time SpecialTime = SpecialClock.getElapsedTime();

	if (hourglass.asSeconds()>0.015)
	{
		Player.animateBody();
	}

	Map.update(tiemu);

	sf::Vector2f movement(0.f, 0.f);

	sf::Joystick::update();
	
	
	Score.setString( static_cast<std::stringstream*>( &(std::stringstream() << Player.Score) )->str() );
	Life.setString(static_cast<std::stringstream*>( &(std::stringstream() << Player.Life) )->str() );
	
	sf::Vector2f center( Player.Body.getPosition() + sf::Vector2f(10.f, 10.f) );
	
	if ((sf::Joystick::isButtonPressed(0,1) || sf::Joystick::isButtonPressed(1,1) ) && Player.PowerBar >0 && SpecialTime.asSeconds() >0.05)
	{
		SpecialClock.restart();
		Player.SpecialTrigger = true;
		Player.DecraseSpecialBar();
	}

	if (!(sf::Joystick::isButtonPressed(0,1) || sf::Joystick::isButtonPressed(1,1) ) || !(Player.PowerBar >0) )
	{
		Player.SpecialTrigger = false;
	}
	

	double tang =  atan2(Inp.r/100,  Inp.z/100);

	movement.x += 3* Inp.x/100;
	movement.y += 3* Inp.y/100;

	ShipList.ShipsUpdate(deltaTime, Player.Body, Player.SpecialTrigger);

	if (Inp.z <-50 || Inp.z>50 || Inp.r >50 || Inp.r<-50)
	{
		sf::Vector2f rot(10.f * cos(tang), 10.f * sin(tang) );

		Player.snipe.setPosition(center);
		
		Player.snipe.move ( rot );

		if(Player.cor!=sf::Color(0,0,0)&& watch.asSeconds()>0.1)
		{
			timer.restart();
			Sounds.push_back(sf::Sound(Configuration::SoundEffects.get(Configuration::Sounds::shot) ) );
			Sounds.back().setVolume(55);
			Sounds.back().play();
			Player.gun.ShootAdd(  tang  ,  Player.Body.getPosition() ,  Player.cor);
		}


		if(Inp.z<0){

			Player.snipe.setRotation( 180 * tang/(3.14159)  );
		}
		else
		{
			Player.snipe.setRotation( ( (90 * tang/(3.14159/2) )  )  );
		}
	}

	if (Inp.x <-50 || Inp.x>50 || Inp.y >50 || Inp.y<-50)
	{
			Map.outside(Player.Body.getPosition() + movement, Player.Body.getGlobalBounds(), movement);
			Player.Body.move(movement * deltaTime.asSeconds());
			Score.move(movement * deltaTime.asSeconds());
			Life.move(movement * deltaTime.asSeconds());
			Player.snipe.move(movement * deltaTime.asSeconds());
	}
	Player.gun.ShootUpdate(deltaTime,shoottime);

	Camera.setCenter(Player.Body.getPosition());


	if (ShipList.empty())
	{

		preload(Player.Score/200 + 3);

	}	
		collision();

	
	Player.SpecialFill.setPosition(Life.getPosition() + sf::Vector2f(-100, 30.f));
	Player.SpecialBar.setPosition(Life.getPosition() + sf::Vector2f(-100, 30.f));

	Player.SpecialFill.setSize(sf::Vector2f(Player.PowerBar,10.f));
	Sounds.remove_if(GameInterface::soundoff);
	//std::cout<<Sounds.size()<<std::endl;
}	

