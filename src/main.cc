#include "../include/boss.h"
#include "../include/enemy.h"
#include "../include/item.h"
#include "../include/menu.h"
#include "../include/player.h"
#include "../include/rpg.h"
#include "../include/skill.h"

int main(){
    Menu * menu = new Menu();
    
    menu->RunMenu();

    delete menu;
    
    menu = nullptr;

    return 0;
}