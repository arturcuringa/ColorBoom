#include "Gameinterface.h"

GameInterface::GameInterface() : myWindow(sf::VideoMode(800,600), "COLOR BOOOM")
{	
	sf::Clock clock;
	//sf::Time shoot= clock.restart();
	Player.Body.setRadius(10.f);
	Player.Body.setPosition(380.f, 280.f);
	Player.Body.setFillColor(sf::Color(100,100,100));

	Player.snipe.setSize(sf::Vector2f(10.f,10.f));
	Player.snipe.setPosition(Player.Body.getPosition() + sf::Vector2f(20.f,10.f));
	Player.snipe.setOrigin(0.f , 5.f);
	Player.snipe.setFillColor(sf::Color(100,100,100));

}

void GameInterface::Start()
{
	sf::Clock clock;
	sf::Clock timer;
	while(myWindow.isOpen()){
		sf::Time deltaTime = clock.restart();
		EventInput();
		update(deltaTime,timer);
		render();

	}
	
}

void GameInterface::render()
{
	myWindow.clear();
	Player.gun.ShootDraw(myWindow);
	myWindow.draw(Player.Body);
	myWindow.draw(Player.snipe);
	myWindow.display();
}

void GameInterface::PlayerInput(sf::Keyboard::Key key, bool press)
{
	if (key == sf::Keyboard::W )
	{
		Player.ismovingUp = press;
		
	}else if (key == sf::Keyboard::A )
	{
		Player.ismovingLeft = press;
	}else if (key == sf::Keyboard::S )
	{
		Player.ismovingDown = press;
	}else if (key == sf::Keyboard::D )
	{
		Player.ismovingRight = press;
	}
	


}

void GameInterface::EventInput()
{

	sf::Event ev;

	while(myWindow.pollEvent(ev)){
		switch(ev.type){
		case sf::Event::KeyPressed:
			PlayerInput(ev.key.code, true);
			break;
		case sf::Event::KeyReleased:
			PlayerInput(ev.key.code, false);
			break;
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

}

void GameInterface::update(sf::Time deltaTime,sf::Clock &timer){

	sf::Time watch = timer.getElapsedTime();

	sf::Vector2f movement(0.f, 0.f);
	if (Player.ismovingUp)
		movement.y -= 200.f;

	if (Player.ismovingLeft)
		movement.x -= 200.f;
	
	if (Player.ismovingDown)
		movement.y += 200.f;
	
	if (Player.ismovingRight)
		movement.x += 200.f;

	sf::Joystick::update();
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	float z = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
	float r = sf::Joystick::getAxisPosition(0, sf::Joystick::R);
	bool r1 =sf::Joystick::isButtonPressed(0,5);
	bool l1 =sf::Joystick::isButtonPressed(0,4);
	bool r2 =sf::Joystick::isButtonPressed(0,7);
	bool l2 =sf::Joystick::isButtonPressed(0,6);

		sf::Vector2f center( Player.Body.getPosition() + sf::Vector2f(10.f, 10.f) );
		

		
		if (l1 && l2)
		{
			Player.cor = sf::Color(255,255,0);
		}else if (l1 && r2)
		{
			Player.cor = sf::Color(255,0,255);
		}else if (l2 && r2)
		{
			Player.cor = sf::Color(0,255,255);
		}else 	if (l1)
		{
			Player.cor = sf::Color(255,0,0);
		}else if (l2)
		{
			Player.cor = sf::Color(0,255,0);
		}else if (r2)
		{
			Player.cor = sf::Color(0,0,255);
		}
		if(Player.cor!=sf::Color(0,0,0))
		{
			Player.Body.setFillColor(Player.cor);
			Player.snipe.setFillColor(Player.cor);
		}
		//else
		//{
		//	Player.Body.setFillColor(sf::Color(100,100,100));
		//	Player.snipe.setFillColor(sf::Color(100,100,100));
		//}



	

	double tang =  atan2(r/100,  z/100);

	movement.x += 3*x;
	movement.y += 3*y;


	if (z <-50 || z>50 || r >50 || r<-50)
	{
		sf::Vector2f rot(10.f * cos(tang), 10.f * sin(tang) );

		Player.snipe.setPosition(center);
		
		Player.snipe.move ( rot );

		if(Player.cor!=sf::Color(0,0,0)&& watch.asSeconds()>0.1)
		{
			timer.restart();
			Player.gun.ShootAdd(  tang  ,  Player.Body.getPosition() + sf::Vector2f(5.f, 5.f) ,  Player.cor);
		}


		if(z<0){

			Player.snipe.setRotation( 180 * tang/(3.14159)  );
		}
		else
		{
				Player.snipe.setRotation( ( (90 * tang/(3.14159/2) )  )  );
		}
	}

	if (x <-50 || x>50 || y >50 || y<-50)
	{
		Player.Body.move(movement * deltaTime.asSeconds());

		Player.snipe.move(movement * deltaTime.asSeconds());
	}
	Player.gun.ShootUpdate(deltaTime);

	
}	
