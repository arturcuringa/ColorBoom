#ifndef __Config__
#define __Config__

#include "Resource.h"
class Configuration
{
	public:
		Configuration() = delete;
		Configuration(const Configuration&) = delete;
		Configuration& operator=(const Configuration&) = delete;
	
		enum Textures : int {Ships,Shoots, Player, Gun, Mapa, C, O, L, O2, R, BOOM };
		static ResourceManager<sf::Texture,int> textures;
		
		enum Fonts : int {Arcade};
		static ResourceManager<sf::Font,int>fonts;

		enum Sounds : int{Explo, shot, PExplo};
		static ResourceManager<sf::SoundBuffer,int> SoundEffects;
		
		static void initialize();
	
	private:
		static void initFonts();
		static void initTextures();
		static void initSounds();

};

#endif