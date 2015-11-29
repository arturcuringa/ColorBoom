
#include "Config.h"

ResourceManager<sf::Texture,int> Configuration::textures;
ResourceManager<sf::Font,int> Configuration::fonts;

void Configuration::initialize()
{
	initFonts();
	initTextures();
}
void Configuration::initFonts()
{
	fonts.load(Fonts::Arcade,"ARCADE_N.TTF");
}
void Configuration::initTextures()
{
	textures.load(Textures::Ships,"ENEMY SHIPS2.png");
	textures.load(Textures::Shoots,"Shoot2.png");

}