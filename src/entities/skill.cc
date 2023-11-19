#include "../../include/skill.h"
#include "../../include/player.h"
#include "../../include/enemy.h"

Skill::Skill(int classe, int index, Player* player, Enemy* enemy) 
    : player_ref(player), enemy_ref(enemy) {
    // Referência utilizada para mudar os atributos de jogador e inimigo
    if(classe == 0){ // Knight
        if(index == 0){ // Guerreiro de Aço
            player_ref->AumentaHp(10);
        }else if(index == 1){ // Quebra-Escudo
            player_ref->AumentaAgi(10, 3);
            enemy_ref->ReduzHp(10);
        }else if(index == 2){ // Golpe Devastador
            enemy_ref->ReduzHp(20);
        }
    } else if(classe == 1){ // Mage
        if(index == 0){ // Barreira da Luz
            player_ref->AumentaDef(10, 3);
        }else if(index == 1){ // Raio Singular
            enemy_ref->ReduzHp(20);
        }else if(index == 2){ // Arco Místico
            enemy_ref->ReduzHp(30);
        }
    } else if(classe == 2){ // Samurai
        if(index == 0){ // Coração da Batalha
            player_ref->AumentaMp(15);
        }else if(index == 1){ // Espada Fantasma
            enemy_ref->ReduzHp(20);
        }else if(index == 2){ // Falhas da Armadura
            enemy_ref->ReduzDef(15, 3);
        }
    } else if(classe == 4){ // Boss

    }
}

Skill::Skill(){}