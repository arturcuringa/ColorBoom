
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
	fonts.load(Fonts::Arcade,"data/ARCADE_N.TTF");
}
void Configuration::initTextures()
{
	textures.load(Textures::Ships,"data/ENEMY SHIPS2.png");
	textures.load(Textures::Shoots,"data/Shoot2.png");
	textures.load(Textures::Player, "data/LJ FINAL white.png");
	textures.load(Textures::Gun, "data/ARROWS.png");
	textures.load(Textures::Mapa, "data/Sky.png");
	textures.load(Textures::C, "data/c.png");
	textures.load(Textures::O, "data/O.png");
	textures.load(Textures::L, "data/L.png");
	textures.load(Textures::O2, "data/O2.png");
	textures.load(Textures::R, "data/R.png");
	textures.load(Textures::BOOM, "data/BOOM.png");
}