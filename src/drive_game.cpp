#include <SFML/Graphics.hpp>
#include "Gameinterface.h"
#include <iostream>
#include <math.h>
#include "Config.h"

int main (){
	Configuration::initialize();
	GameInterface Game;
	
	Game.GameLoop();
	/*float x =0;
	float y =0;
	float z = 0;
	while(true){
		sf::Joystick::update();
		x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		z = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
		std::cout<<"X: " << x << " " << "Y: " << y << " " << "Z: "<< z << "\n";

	}*/
	
	

	return 0;
}