CXX = g++
CXXFLAGS = -g -Wall -O3 -std=c++11
INC_DIRS = -I include/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

OBJS = build/main.o build/boss.o build/enemy.o build/item.o build/menu.o build/player.o build/rpg.o build/skill.o

main: $(OBJS)
	
	$(CXX) $(OBJS) -o game.app $(LIBS)

build/rpg.o: src/entities/rpg.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/main.o: src/main.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/boss.o: src/entities/boss.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/enemy.o: src/entities/enemy.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/item.o: src/entities/item.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/menu.o: src/entities/menu.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/player.o: src/entities/player.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

build/skill.o: src/entities/skill.cc
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS) game.app
