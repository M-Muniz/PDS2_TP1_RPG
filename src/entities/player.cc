#include "../../include/player.h"

Player::Player(){}

Player::Player(string nome, int classe){
  if(classe == 0){ // Classe Guerreiro
    stats_.hp_max = 110;
    stats_.hp = stats_.hp_max;
    stats_.atk = 20;
    stats_.def = 30;
    stats_.agi = 0;
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

  if (x + stats_.agi < 80){ // Player não desviou
    stats_.hp -= (atk_enemy - stats_.def);

    if(stats_.hp < 0){stats_.hp = 0;}
        
    return 1;
  }else{ // Player desviou
    return 0;
  }
}
    
void Player::Upar(int xp){
  stats_.xp += xp;

  if(stats_.xp >= 100){
    stats_.hp_max += 15;
    stats_.hp = stats_.hp_max;
    stats_.atk += 5;
    stats_.def += 5;
    stats_.agi += 5;
    stats_.mp += 15; 
    stats_.xp -= 100;

    cout << "Você subiu de nível!" << endl;
  }

  return;
}

Status Player::ReturnStatus(){return stats_;}

string Player::ReturnSpriteMorte(){
  if (classe_ == 0){
    return "resources/knight/sprite_knight_dead.png";
  }else if(classe_ == 1 ){
    return "resources/mage/sprite_mage_dead.png";
  }
  return "resources/samurai/sprite_samurai_dead.png";
}
string Player::ReturnSpriteAtk(){
  if (classe_ == 0){
    return "resources/knight/sprite_knight_atk1.png";
  }else if(classe_ == 1 ){
    return "resources/mage/sprite_mage_atk2.png";
  }
  return "resources/samurai/sprite_samurai_atk1.png";
} 
string Player::ReturnSpriteTomou(){
  if (classe_ == 0){
    return "resources/knight/sprite_knight_hurt.png";
  }else if(classe_ == 1 ){
    return "resources/mage/sprite_mage_hurt.png";
  }
  return "resources/samurai/sprite_samurai_hurt.png";
}
string Player::ReturnSpriteDef(){
  if (classe_ == 0){
    return "resources/knight/sprite_knight_protect.png";
  }else if(classe_ == 1 ){
    return "resources/mage/sprite_mage_protect.png";
  }
  return "resources/samurai/sprite_samurai_protection.png";
}
string Player::ReturnSpriteIdle(){
  if (classe_ == 0){
    return "resources/knight/sprite_knight_default.png";
  }else if(classe_ == 1 ){
    return "resources/mage/sprite_mage_default.png";
  }
  return "resources/samurai/sprite_samurai_default.png";
}
void Player::SettaSprite(string png){
  img_player_texture_.loadFromFile(png);
  img_player_.setTexture(img_player_texture_);
  img_player_.setScale(5,5);
}
DadosAnimacao Player::ReturnDadosSprite(string png){
  DadosAnimacao aux;
  if (classe_ == 0){
    if(png == "resources/knight/sprite_knight_atk1.png"){
      aux={555,75,5};
      img_player_.setPosition(150,300);
      return aux;
    }else if(png == "resources/knight/sprite_knight_protect.png"){
      aux={45,61,1};
      img_player_.setPosition(150,300);
      return aux;
    }else if(png == "resources/knight/sprite_knight_hurt.png"){
      aux={106,61,2};
      img_player_.setPosition(150,300);
      return aux;
    }else if(png == "resources/knight/sprite_knight_dead.png"){
      aux={480,60,6};
      img_player_.setPosition(150,300);
      return aux;
    }
  }else if(classe_ == 1 ){
    if(png == "resources/mage/sprite_mage_atk2.png"){
      aux={990,74,9};
      img_player_.setPosition(125,285);
      return aux;
    }else if(png == "resources/mage/sprite_mage_protect.png"){
      aux={348,87,4};
      img_player_.setPosition(125,285);
      return aux;
    }else if(png == "resources/mage/sprite_mage_hurt.png"){
      aux={132,59,2};
      img_player_.setPosition(125,285);
      return aux;
    }else if(png == "resources/mage/sprite_mage_dead.png"){
      aux={340,59,4};
      img_player_.setPosition(125,285);
      return aux;
    }
  }else if(classe_ == 2){
    if(png == "resources/samurai/sprite_samurai_atk1.png"){
      aux={575,67,5};
      img_player_.setPosition(110,265);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_protection.png"){
      aux={345,70,5};
      img_player_.setPosition(110,265);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_hurt.png"){
      aux={210,70,3};
      img_player_.setPosition(110,265);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_dead.png"){
      aux={480,67,6};
      img_player_.setPosition(110,265);
      return aux;
    }
  }
} 