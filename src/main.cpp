#include "../Class/Rpg/Rpg.h"
#include <SFML/Graphics.hpp>

int main(){
    auto jogo = std::make_shared<Rpg>();
    
    jogo->Run();
    
    return 0;
}