#include "Gameinterface.h"

GameInterface::GameInterface() : myWindow(sf::VideoMode(800,600), "COLOR BOOOM")
{
	Player.setRadius(80.f);
	Player.setPosition(100.f, 100.f);
	Player.setFillColor(sf::Color::Red);
}

void GameInterface::Start()
{
	while(myWindow.isOpen()){
	
		EventInput();
		update();
		render();

	}
	
}

void GameInterface::render()
{
	myWindow.clear();
	myWindow.draw(Player);
	myWindow.display();
}

void GameInterface::PlayerInput(sf::Keyboard::Key key, bool press)
{
	if (key == sf::Keyboard::W )
	{
		sf::Vector2f movement (0.f, 0.f);
		movement.y -= 1.f;
		Player.move(movement);
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
		case sf::Event::Closed:
			myWindow.close();
			break;
		}
	}

}
