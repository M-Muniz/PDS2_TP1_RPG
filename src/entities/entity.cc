#include "../../include/entity.h"

Entity::Entity(){};

Entity::~Entity(){};

int Entity::Atk(){return stats_.atk;}

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

Status Entity::ReturnStatus(){return stats_;};

Skill Entity::EntitySkills(int index){return skills_[index];};

string Entity::ReturnSpriteMorte(){return "";};

string Entity::ReturnSpriteAtk(){return "";};

string Entity::ReturnSpriteIdle(){return "";};

string Entity::ReturnSpriteDef(){return "";};

string Entity::ReturnSpriteTomou(){return "";};

DadosAnimacao Entity::ReturnDadosSprite(string png){return DadosAnimacao{0,0,0};};

void Entity::SettaSprite(string Png){};

