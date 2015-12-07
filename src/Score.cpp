#include "Score.h"

bool Score::checkScore(long unsigned int score ){
	
	std::ifstream myfile("data/Scores");
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
				beat = true;
				i++;
			}
			
		}

	}else
		std::cout<<"Bug!"<<std::endl;
	myfile.close();
	
	return beat;
}

bool Score::InputScore(long unsigned int score, std::string Name ){
	
	std::ifstream myfile("data/Scores");
	std::ofstream tempfile("data/Temp");

	std::ifstream myfile2("data/Names");
	std::ofstream tempNfile("data/TempN");


	bool beat= false;
	int i = 0;
	if (myfile.is_open())
	{
		if (myfile2.is_open())
		{
		
		
			std::string lineS;
			std::string lineN;
			while(std::getline(myfile,lineS)){
				std::getline(myfile2,lineN);
				std::string::size_type sz;
				long unsigned int tempscore = std::stoi(lineS, &sz);
				if (score >tempscore && !beat)
				{
					tempfile << score <<"\n";
					tempNfile << Name << "\n";
					beat = true;
					i++;
				}
				if ( !(i>9) )
				{
					tempfile << lineS << "\n";
					tempNfile << lineN << "\n";
					i++;
				}
			}
		}
		else
			std::cout<<"Bug!"<<std::endl;

	}else
		std::cout<<"Bug!"<<std::endl;
	tempfile.close();
	myfile.close();
	remove("data/Scores");
	rename("data/Temp", "data/Scores" );
	remove("data/Names");
	rename("data/TempN", "data/Names");

	return beat;
}