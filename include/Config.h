#ifndef __Config__
#define __Config__

#include "Resource.h"

class Configuration
{
	public:
		Configuration() = delete;
		Configuration(const Configuration&) = delete;
		Configuration& operator=(const Configuration&) = delete;
	
		enum Textures : int {Ships};
		static ResourceManager<sf::Texture,int> textures;
		
		static void initialize();
	
	private:
		static void initTextures();

};

#endif