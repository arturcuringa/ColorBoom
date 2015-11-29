#include "Gameinterface.h"

GameInterface::GameInterface() : myWindow(sf::VideoMode(800,600), "COLOR BOOOM")
{	
	Configuration::initialize();
	
	if (!fonte.loadFromFile("ARCADE_N.TTF"))
	{
		std::cout<<"Deu ruim!";
	}
		
	texto.setFont(fonte);
	texto.setCharacterSize(20);
	texto.setStyle(sf::Text::Bold);
	texto.setColor(sf::Color::White);
	texto.setPosition(sf::Vector2f(0,0));


	Camera.setSize(sf::Vector2f(800,600));

	preload(10);
}

void GameInterface::Start()
{
	sf::Clock shoottime;
	sf::Clock clock;
	sf::Clock timer;
	sf::Clock tiemu;
	sf::Time PerFrame = sf::seconds(1.f/60.f);
	sf::Time SinceLastTry;
	while(myWindow.isOpen()){
		
		EventInput();
		
		SinceLastTry += clock.restart();
		while(SinceLastTry > PerFrame)
		{
			SinceLastTry -= PerFrame;
			EventInput();
			update(PerFrame,timer,tiemu,shoottime);
			
		}
		render();

	}
	
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

		myWindow.draw(texto);
	myWindow.display();
}

void GameInterface::PlayerInput()
{

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
			Player.Body.setFillColor(Player.cor);
			Player.snipe.setFillColor(Player.cor);
		}
	
}

void GameInterface::PlayerMove(){

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

		PlayerInput();
	
	
		PlayerMove();

	}

}

void GameInterface::collision(){

	if(ShipList.S_head->next == ShipList.S_tail){
		return;
	}
	else{
		int c=0;

		ShootPaint::Shootnode *auShoot;
		auShoot=Player.gun.S_head;
		sf::Time FaseTime = GameTime.getElapsedTime();
		Shipnode * auShip;
		auShip = ShipList.S_head;

		while(auShip != ShipList.S_tail){

			if( Player.Body.getGlobalBounds().intersects(auShip->next->body.getGlobalBounds())){
				ShipList.ShipsRemove(auShip->next);
				Player.Die();
				//Player.updateScore(100);
			}

			if(Player.gun.S_head->next!=nullptr){
				while(auShoot != Player.gun.S_tail){
					
					if( auShoot->next->ammo.getGlobalBounds().intersects(auShip->next->body.getGlobalBounds()) && auShoot->next->ammo.getFillColor() == auShip->next->body.getColor()){

						if(auShoot->next == Player.gun.S_tail)
						{
							Player.gun.S_tail = auShoot;
						}
						//std::cout<<"AQUI SEU ANIMAL!"<<std::endl;
						Player.gun.ShootRemove(auShoot, auShoot->next);
						ShipList.ShipsRemove(auShip->next);
						
						Player.updateScore(100 - (FaseTime.asSeconds() * 30 /60) );

						break;
					}

					else{
						auShoot = auShoot->next;
					}
				}
			}
			auShoot=Player.gun.S_head;
			c++;
			//std::cout<<c<<std::endl;
			auShip = auShip->next;


		}

	}
}

void GameInterface::preload(int enemys){

	float x1, y1;
	int i =0;

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

		GameTime.restart();
}


void GameInterface::update(sf::Time deltaTime,sf::Clock &timer,sf::Clock &tiemu,sf::Clock &shoottime){

	sf::Time watch = timer.getElapsedTime();
	sf::Time hourglass = tiemu.getElapsedTime();

	if (hourglass.asSeconds()>0.015)
	{
		Player.animateBody();
	}

	Map.update(tiemu);

	sf::Vector2f movement(0.f, 0.f);

	sf::Joystick::update();
	
	
	texto.setString( static_cast<std::stringstream*>( &(std::stringstream() << Player.Score) )->str() );
	
	
	sf::Vector2f center( Player.Body.getPosition() + sf::Vector2f(10.f, 10.f) );
	
	

	double tang =  atan2(Inp.r/100,  Inp.z/100);

	movement.x += 3* Inp.x/100;
	movement.y += 3* Inp.y/100;

	ShipList.ShipsUpdate(deltaTime, Player.Body);

	if (Inp.z <-50 || Inp.z>50 || Inp.r >50 || Inp.r<-50)
	{
		sf::Vector2f rot(10.f * cos(tang), 10.f * sin(tang) );

		Player.snipe.setPosition(center);
		
		Player.snipe.move ( rot );

		if(Player.cor!=sf::Color(0,0,0)&& watch.asSeconds()>0.1)
		{
			timer.restart();
			Player.gun.ShootAdd(  tang  ,  Player.Body.getPosition() + sf::Vector2f(5.f, 5.f) ,  Player.cor);
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
			texto.move(movement * deltaTime.asSeconds());
			Player.snipe.move(movement * deltaTime.asSeconds());
	}
	Player.gun.ShootUpdate(deltaTime,shoottime);

	Camera.setCenter(Player.Body.getPosition());


	collision();

	if (ShipList.empty())
	{

		preload(Player.Score/100);

	}	


}	

