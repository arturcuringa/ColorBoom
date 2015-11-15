#include "Gameinterface.h"

GameInterface::GameInterface() : myWindow(sf::VideoMode(800,600), "COLOR BOOOM")
{	
	sf::Clock clock;
	//sf::Time shoot= clock.restart();
	Player.Body.setRadius(10.f);
	Player.Body.setPosition(100.f, 100.f);
	Player.Body.setFillColor(sf::Color::Red);

	Player.snipe.setSize(sf::Vector2f(10.f,10.f));
	Player.snipe.setPosition(Player.Body.getPosition() + sf::Vector2f(20.f,5.f));
	Player.snipe.setOrigin(0.f , 5.f);
	Player.snipe.setFillColor(sf::Color::Blue);

}

void GameInterface::Start()
{
	sf::Clock clock;
	sf::Clock timer;
	while(myWindow.isOpen()){
		sf::Time deltaTime = clock.restart();
		sf::Time watch = timer.getElapsedTime();
		EventInput();
		update(deltaTime,watch);
		render();

	}
	
}

void GameInterface::render()
{
	myWindow.clear();
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

void GameInterface::update(sf::Time deltaTime,sf::Time watch){

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
	float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
	float z = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
	float r = sf::Joystick::getAxisPosition(1, sf::Joystick::V);

	sf::Vector2f center( Player.Body.getPosition() + sf::Vector2f(10.f, 10.f) );

	

	double tang =  atan2(r/100,  z/100);

	movement.x += 3*x;
	movement.y += 3*y;

	sf::Vector2f rot(10.f * cos(tang), 10.f * sin(tang) );

	if (z <-33 || z>33 || r >33 || r<-33)
	{
		
		Player.snipe.setPosition(center);
		
		Player.snipe.move ( rot );



		if(z<0){

			Player.snipe.setRotation( 180 * tang/(3.14159)  );
		}
		else
		{
				Player.snipe.setRotation( ( (90 * tang/(3.14159/2) )  )  );
		}
	}

	if (x <-33 || x>33 || y >33 || y<-33)
	{
		Player.Body.move(movement * deltaTime.asSeconds());

		Player.snipe.move(movement * deltaTime.asSeconds());
	}
	

	
}	
