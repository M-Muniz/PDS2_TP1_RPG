CXX = g++
CXXFLAGS = -g -Wall -O3 -std=c++11
INC_DIRS = -I Class/
LIB_DIRS = -L/usr/lib/x86_64-linux-gnu/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

OBJS = build/main.o build/Rpg.o

main: $(OBJS)
	$(CXX) $(OBJS) -o Game.app $(LIB_DIRS) $(LIBS)

build/Rpg.o: Class/Rpg/Rpg.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS) Game.app
