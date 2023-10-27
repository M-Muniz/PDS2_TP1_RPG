#include "../../include/player.h"

#include <iostream>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include<time.h> //necessário p/ função time()

Player::Player(string nome, int classe){
    if(classe == 0){ // Classe Guerreiro
        stats_.hp = 110;
        stats_.atk = 15;
        stats_.def = 30;
        stats_.agi = 20;
        stats_.mp = 20;
    }else if(classe == 1){ // Classe Mago
        stats_.hp = 95;
        stats_.atk = 20;
        stats_.def = 20;
        stats_.agi = 30;
        stats_.mp = 30;
    }else if(classe == 2){ // Classe Ladino
        stats_.hp = 80;
        stats_.atk = 30;
        stats_.def = 20;
        stats_.agi = 40;
        stats_.mp = 20;
    }
    stats_.xp = 0;

    name_ = nome;

    classe_ = classe;

    for(int i = 0; i < 3; i++){
        Skill aux(classe, i);
        skills_.push_back(aux);
    }
}

int Player::Atk(){return stats_.atk;}

bool Player::Def(int atk_enemy){
    srand(time(NULL));

    int x = rand() % 100;

    if (x + stats_.agi < 80){ /* Caso a agilidade do Player + valor aleatório for maior que 80, o Enemy terá errado o ataque*/
        stats_.hp -= atk_enemy;
        
        return 1;
    }else{
        return 0;
    }
}
    


void Player::Upar(int xp){
    //Experiencia+=experiencia;
    //if(Experiencia>valor){
        //skills nivel1;
        //upar status nivel1
    //}
    //if(Experiencia>valor1){
        //skills nivel2;
        //upar status nivel2
    //}
    //if(Experiencia>valor3){
        //skills nivel3;
        //upar status nivel3
    //}
    //return;
}

Status Player::ReturnStatus(){return stats_;}