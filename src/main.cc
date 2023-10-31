#include "../include/boss.h"
#include "../include/enemy.h"
#include "../include/item.h"
#include "../include/menu.h"
#include "../include/player.h"
#include "../include/rpg.h"
#include "../include/skill.h"

int main(){
  srand(time(NULL));

  Menu * menu = new Menu();
  menu->RunMenu();
  Player jogador(menu->ReturnName(),menu->ReturnClass());
  delete menu;
  Rpg* jogo = new Rpg(jogador);
  jogo->Run();
  delete jogo;

  menu = nullptr;

  return 0;
}