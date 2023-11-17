#include "../../include/player.h"

Player::Player(){}

Player::Player(string nome, int classe){
  if(classe == 0){ // Classe Guerreiro
    stats_.hp_max = 110;
    stats_.hp = stats_.hp_max;
    stats_.atk = 20;
    stats_.def = 30;
    stats_.agi = 15;
    stats_.mp = 20;
    img_player_texture_.loadFromFile("resources/knight/sprite_knight_default.png"); 
    img_player_.setTexture(img_player_texture_);
  }else if(classe == 1){ // Classe Mago
    stats_.hp_max = 95;
    stats_.hp = stats_.hp_max;
    stats_.atk = 30;
    stats_.def = 20;
    stats_.agi = 20;
    stats_.mp = 30;
    img_player_texture_.loadFromFile("resources/mage/sprite_mage_default.png"); 
    img_player_.setTexture(img_player_texture_);
  }else if(classe == 2){ // Classe Samurai
    stats_.hp_max = 80;
    stats_.hp = stats_.hp_max;
    stats_.atk = 25;
    stats_.def = 20;
    stats_.agi = 30;
    stats_.mp = 20;
    img_player_texture_.loadFromFile("resources/samurai/sprite_samurai_default.png"); 
    img_player_.setTexture(img_player_texture_);
  }
    
  img_player_.setScale(5,5);

  stats_.xp = 0;

  name_ = nome;

  classe_ = classe;

  for(int i = 0; i < 3; i++){
    Skill aux(classe, i);
    skills_.push_back(aux);
  }
}

string Player::Name(){return name_;}

int Player::Atk(){return stats_.atk;}

bool Player::Def(int atk_enemy){

  int x = rand() % 100;

  if (x + stats_.agi < 65){ // Player não desviou
    stats_.hp -= (atk_enemy - stats_.def);
        
    return 1;
  }else{ // Player desviou
    return 0;
  }
}
    
void Player::Upar(int xp){
  stats_.xp += xp;

  if(stats_.xp > 100){
    stats_.hp_max += 15;
    stats_.hp = stats_.hp_max;
    stats_.atk += 5;
    stats_.def += 5;
    stats_.agi += 5;
    stats_.mp += 15; 
    stats_.xp=0;
  }
    
  return;
}

Status Player::ReturnStatus(){return stats_;}