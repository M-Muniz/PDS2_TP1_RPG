Build/main.o: main.cpp 
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.cpp: src/main.o  
	g++ -c src/main.cpp


Class/Rpg/Rpg.o:Class/Rpg/Rpg.h Class/Rpg/Rpg.cpp
	g++ -c Class/Rpg/Rpg.cpp