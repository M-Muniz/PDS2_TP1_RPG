CXX = g++
CXXFLAGS = -g -Wall -O3 -std=c++11
INC_DIRS = -I include/
LIB_DIRS = -L/usr/lib/x86_64-linux-gnu/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

OBJS = build/main.o build/rpg.o

main: $(OBJS)
	$(CXX) $(OBJS) -o game.app $(LIB_DIRS) $(LIBS)

build/rpg.o: src/entities/rpg.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/main.o: src/main.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS) game.app
