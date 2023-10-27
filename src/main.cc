#include "../include/boss.h"
#include "../include/enemy.h"
#include "../include/item.h"
#include "../include/menu.h"
#include "../include/player.h"
#include "../include/rpg.h"
#include "../include/skill.h"

int main(){
    auto jogo = std::make_shared<Rpg>();
    
    jogo->Run();
    
    return 0;
}