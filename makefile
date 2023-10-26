Release: main

Build/main.o: src/main.cpp Class/Rpg/Rpg.h
	c++ -c src/main.cpp -I Class/ -L/usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system -o Build/main.o


Build/Rpg.o: Class/Rpg/Rpg.h Class/Rpg/Rpg.cpp
	c++ -c Class/Rpg/Rpg.cpp -I Class/ -o Build/Rpg.o

main: Build/Rpg.o Build/main.o  
	c++ Build/Rpg.o Build/main.o -o Jogo