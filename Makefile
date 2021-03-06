#######################################################Compilação##################################################################
CXX = g++
DELETAR = bin/rm
CVERSION = -std=c++11 #-std=c++0x
AVISA =-Wall -g

OP = $(AVISA) $(CVERSION) -O3
SFMLOP = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
#######################################################DIR############################################################

DIRIN = include/

DIRSRC = src/

DRIVE =  drive_game.cpp

#######################################################TEST########################################################


all: msg test

msg:
	@echo Gremlin_Alfa-estamos a compilar vosso codigo mestre
test:
	$(CXX) $(OP) -I $(DIRIN) $(DIRSRC)$(DRIVE) $(DIRSRC)Gameinterface.cpp $(DIRSRC)Shoot.cpp $(DIRSRC)map.cpp $(DIRSRC)Ships.cpp $(DIRSRC)Config.cpp $(DIRSRC)Player.cpp $(DIRSRC)Menu.cpp $(DIRSRC)Score.cpp -o bin/test $(SFMLOP)

########################################################Execução###################################################################
roll:
	./bin/test

