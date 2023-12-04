#include "../../include/entity.h"

Entity::Entity(){};

Entity::~Entity(){};

int Entity::Atk(){  
  float variancia = rand() % 41; //gera um numero entre 0 e 40
  variancia += 80; //faz com que esse numero esteja entre 80 e 120
  variancia /= 100; //numero agr esta entre 0.8 e 1.2;
  return (stats_.atk*variancia);
  }

bool Entity::Def(int atk_opponent){
  int aux = rand() % 100;

  if(aux+stats_.agi < 75){  /* o golpe atingiu o inimigo */
   
    stats_.hp -= atk_opponent - stats_.def;

    if(stats_.hp < 0){stats_.hp = 0;}

    return true;
  }else{    
    return false;   /* o não golpe atingiu o inimigo */
  }
}

void Entity::BuffaInimigo(int inimigos_mortos){
  if(inimigos_mortos >= 3){
    int multiplicador = inimigos_mortos/3;
    stats_.hp_max *= (1.05*multiplicador);
    stats_.hp =stats_.hp_max;
    stats_.atk *= (1.05*multiplicador);
    stats_.def *= (1.05*multiplicador);
    stats_.xp -= multiplicador;
  }
}

Status Entity::ReturnStatus(){return stats_;};

string Entity::ReturnSpriteMorte(){return "";};

string Entity::ReturnSpriteAtk(){return "";};

string Entity::ReturnSpriteIdle(){return "";};

string Entity::ReturnSpriteDef(){return "";};

string Entity::ReturnSpriteTomou(){return "";};

DadosAnimacao Entity::ReturnDadosSprite(string png){return DadosAnimacao{0,0,0};};

void Entity::SettaSprite(string Png){};