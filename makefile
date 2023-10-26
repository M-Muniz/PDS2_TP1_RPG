Release: main

Build/main.o: main.cpp Class/Rpg/Rpg.cpp
	c++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system


Build/Rpg.o: Class/Rpg/Rpg.h Class/Rpg/Rpg.cpp
	c++ -c Class/Rpg/Rpg.cpp -I Class/ -o Build/Rpg.o

main: Build/Rpg.o Build/main.o  
	c++ Build/Rpg.o Build/main.o -o Jogo 
