
#include "Config.h"

ResourceManager<sf::Texture,int> Configuration::textures;
void Configuration::initialize()
{
	initTextures();
}
void Configuration::initTextures()
{
	textures.load(Textures::Ships,"ENEMY SHIPS2.png");
}