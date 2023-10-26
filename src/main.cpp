#include "../Class/Rpg/Rpg.h"

int main(){
    auto jogo = std::make_shared<Rpg>();
    
    jogo->Run();
    
    return 0;
}