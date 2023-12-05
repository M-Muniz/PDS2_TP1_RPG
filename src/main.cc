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
  try{
  Menu* menu = new Menu();

  menu->RunMenu();
  
  Player jogador(menu->ReturnName(), menu->ReturnClass());

  Rpg* jogo = new Rpg(jogador);
  
  delete menu;

  jogo->Run();
  
  delete jogo;

  menu = nullptr;
  jogo = nullptr;
  }catch(ErroLoadFromFile){
    cout << "Erro ao carregar alguma imagem ou fonte" << endl;
    cout << "Confira os arquivos da pasta resources" << endl;
  }
  return 0;
}