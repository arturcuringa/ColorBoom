#include "Gameinterface.h"

GameInterface::GameInterface() : myWindow(sf::VideoMode(800,600), "COLOR BOOOM")
{	
	

	Camera.setSize(sf::Vector2f(800,600));
}

void GameInterface::Start()
{
	sf::Clock clock;
	sf::Clock timer;
	sf::Clock tiemu;
	while(myWindow.isOpen()){
		sf::Time deltaTime = clock.restart();
		EventInput();
		update(deltaTime,timer,tiemu);
		render();

	}
	
}

void GameInterface::render()
{
	myWindow.clear();
	myWindow.draw(Map.Body);
	myWindow.setView(Camera);
	Player.gun.ShootDraw(myWindow);
	myWindow.draw(Player.Body);
	myWindow.draw(Player.snipe);
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

void GameInterface::update(sf::Time deltaTime,sf::Clock &timer,sf::Clock &tiemu){

	sf::Time watch = timer.getElapsedTime();
	sf::Time hourglass = tiemu.getElapsedTime();

	if (hourglass.asSeconds()>0.015)
	{
		Player.animateBody();
	}

	Map.update(tiemu);

	sf::Vector2f movement(0.f, 0.f);

	sf::Joystick::update();
	
	
	
	
	sf::Vector2f center( Player.Body.getPosition() + sf::Vector2f(10.f, 10.f) );
	
	

	double tang =  atan2(Inp.r/100,  Inp.z/100);

	movement.x += 3* Inp.x/100;
	movement.y += 3* Inp.y/100;


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
		if (!Map.outside(Player.Body.getPosition() + movement, Player.Body.getGlobalBounds(), movement))
		{	
			movement.x += 3* Inp.x;
			movement.y += 3* Inp.y;
			Player.Body.move(movement * deltaTime.asSeconds());

			Player.snipe.move(movement * deltaTime.asSeconds());
		}
		else{

			
			
			Player.Body.move(movement * deltaTime.asSeconds());

			Player.snipe.move(movement * deltaTime.asSeconds());
		}
	}
	Player.gun.ShootUpdate(deltaTime);

	Camera.setCenter(Player.Body.getPosition());
}	

