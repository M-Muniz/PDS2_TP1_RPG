#include <time.h> //necessário p/ função time()
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
  
  Player jogador(menu->ReturnName(), menu->ReturnClass());

  Rpg* jogo = new Rpg(jogador);
  
  jogo->Run();
  
  menu->~Menu();
  delete menu;

  delete jogo;

  menu = nullptr;
  jogo = nullptr;

  return 0;
}