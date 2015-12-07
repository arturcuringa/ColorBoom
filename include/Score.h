#ifndef __Score__
#define __Score__


#include "Config.h"
#include <fstream>
#include <string>


class Score{
public:
	static bool checkScore(long unsigned int score );
	static bool InputScore(long unsigned int score, std::string Name );

};


#endif