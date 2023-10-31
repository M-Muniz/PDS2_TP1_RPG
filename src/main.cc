#include<time.h> //necessário p/ função time()
#include "../include/boss.h"
#include "../include/enemy.h"
#include "../include/item.h"
#include "../include/menu.h"
#include "../include/player.h"
#include "../include/rpg.h"
#include "../include/skill.h"

int main(){
  srand(time(NULL));

  Menu* menu = new Menu();
  menu->RunMenu();
  Player* jogador = new Player(menu->ReturnName(),menu->ReturnClass());
  delete menu;
  Rpg* jogo = new Rpg(jogador);
  jogo->Run();
  delete jogador;
  delete jogo;

  menu = nullptr;

  return 0;
}