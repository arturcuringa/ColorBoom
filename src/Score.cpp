#include "Score.h"

bool Score::checkScore(long unsigned int score ){
	
	std::ifstream myfile("data/Scores");
	std::ofstream tempfile("data/Temp");
	bool beat= false;
	int i = 0;
	if (myfile.is_open())
	{
		
		std::string line;
		while(std::getline(myfile,line)){
			//std::cout<<line;
			std::string::size_type sz;
			long unsigned int tempscore = std::stoi(line, &sz);
			if (score >tempscore && !beat)
			{
				tempfile << score <<"\n";
				beat = true;
				i++;
			}
			if ( !(i>9) )
			{
				tempfile << line << "\n";
				i++;
			}
			
		}

	}else
		std::cout<<"Bug!"<<std::endl;
	tempfile.close();
	myfile.close();
	remove("data/Scores");
	rename("data/Temp", "data/Scores" );
	
	return beat;
}