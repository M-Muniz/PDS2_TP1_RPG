#include "../../include/player.h"
#include "../../include/entity.h"

Player::Player() : Entity(){}

Player::Player(string nome, int classe) : Entity(){
  if(classe == 0){ // Classe Guerreiro
    stats_.hp_max = 200;
    stats_.hp = stats_.hp_max;
    stats_.atk = 40;
    stats_.def = 30;
    stats_.agi = 5;
    stats_.mp = 100;
    img_entity_texture_.loadFromFile("resources/knight/sprite_knight_default.png"); 
    img_entity_.setTexture(img_entity_texture_);
  }else if(classe == 1){ // Classe Mago
    stats_.hp_max = 150;  
    stats_.hp = stats_.hp_max;
    stats_.atk = 60;
    stats_.def = 5;
    stats_.agi = 10;
    stats_.mp = 100;
    img_entity_texture_.loadFromFile("resources/mage/sprite_mage_default.png"); 
    img_entity_.setTexture(img_entity_texture_);
  }else if(classe == 2){ // Classe Samurai
    stats_.hp_max = 170;
    stats_.hp = stats_.hp_max;
    stats_.atk = 50;
    stats_.def = 15;
    stats_.agi = 20;
    stats_.mp = 100;
    img_entity_texture_.loadFromFile("resources/samurai/sprite_samurai_default.png"); 
    img_entity_.setTexture(img_entity_texture_);
  }
  img_entity_.setScale(5,5);

  stats_.xp = 0;

  name_ = nome;

  classe_ = classe;

  skills_cd_.resize(3);

  for(int i = 0; i < 3; i++){
    Skill aux(classe, i);
    skills_.push_back(aux);
    for(int j = 0; j < 3; j++){
      skills_cd_[i].push_back(true);
    }
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

Skill Player::EntitySkills(int index){return skills_[index];}

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
string Player::ReturnSpriteSkill(int index){
  if (classe_ == 0){
    switch (index){
    case 0:
      return "resources/knight/sprite_knight_pray.png";
      break;
    case 1:
      return "resources/knight/sprite_knight_atk2.png";
      break;
    case 2: 
      return "resources/knight/sprite_knight_atk3.png";
      break;
    }
  }else if (classe_ == 1){
    switch (index){
    case 0:
      return "resources/mage/sprite_mage_arrow.png";
      break;
    case 1:
      return "resources/mage/sprite_mage_atk1.png";
      break;
    case 2: 
      return "resources/mage/sprite_mage_sphere.png";
      //combinar com a resources/mage/sprite_mage_sphere_charge.png
      break;
    }
  }else{
    switch (index){
    case 0:
      return "resources/samurai/sprite_samurai_focus.png";
      break;
    case 1:
      return "resources/samurai/sprite_samurai_atk2.png";
      break;
    case 2: 
      return "resources/samurai/sprite_samurai_atk3.png";
      break;
    }
  }
  return " ";//pra nao gerar um warning
}

void Player::SettaSprite(string png){
  img_entity_texture_.loadFromFile(png);
  img_entity_.setTexture(img_entity_texture_);
  img_entity_.setScale(5,5);
}


DadosAnimacao Player::ReturnDadosSprite(string png){
  DadosAnimacao aux;
  if (classe_ == 0){
    if(png == "resources/knight/sprite_knight_atk1.png"){
      aux={555,75,5};
      img_entity_.setPosition(260,260);
      return aux;
    }else if(png == "resources/knight/sprite_knight_protect.png"){
      aux={45,61,1};
      img_entity_.setPosition(150,300);
      return aux;
    }else if(png == "resources/knight/sprite_knight_hurt.png"){
      aux={106,61,2};
      img_entity_.setPosition(150,300);
      return aux;
    }else if(png == "resources/knight/sprite_knight_dead.png"){
      aux={480,60,6};
      img_entity_.setPosition(150,300);
      return aux;
    }else if(png == "resources/knight/sprite_knight_pray.png"){
      aux={250,74,5};
      img_entity_.setPosition(150,240);
      return aux;
    }else if(png == "resources/knight/sprite_knight_atk2.png"){
      aux={424,76,4};
      img_entity_.setPosition(190,270);
      return aux;
    }else if(png == "resources/knight/sprite_knight_atk3.png"){
      aux={600,65,6};
      img_entity_.setPosition(150,300);
      return aux;
    }
  }else if(classe_ == 1 ){
    if(png == "resources/mage/sprite_mage_atk2.png"){
      aux={990,74,9};
      img_entity_.setPosition(125,250);
      return aux;
    }else if(png == "resources/mage/sprite_mage_protect.png"){
      aux={348,87,4};
      img_entity_.setPosition(125,175);
      return aux;
    }else if(png == "resources/mage/sprite_mage_hurt.png"){
      aux={132,59,2};
      img_entity_.setPosition(125,310);
      return aux;
    }else if(png == "resources/mage/sprite_mage_dead.png"){
      aux={340,59,4};
      img_entity_.setPosition(125,285);
      return aux;
    }else if(png == "resources/mage/sprite_mage_arrow.png"){
      aux={450,66,6};
      img_entity_.setPosition(125,285);
      return aux;
    }else if(png == "resources/mage/sprite_mage_atk1.png"){
      aux={770,100,7};
      img_entity_.setPosition(165,135);
      return aux;
    }else if(png == "resources/mage/sprite_mage_sphere.png"){
      aux={1440,66,16};
      img_entity_.setPosition(125,285);
      return aux;
    }
  }else if(classe_ == 2){
    if(png == "resources/samurai/sprite_samurai_atk1.png"){
      aux={575,67,5};
      img_entity_.setPosition(110,265);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_protection.png"){
      aux={345,70,5};
      img_entity_.setPosition(110,265);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_hurt.png"){
      aux={210,70,3};
      img_entity_.setPosition(110,265);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_dead.png"){
      aux={480,67,6};
      img_entity_.setPosition(110,265);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_focus.png"){
      aux={345,80,5};
      img_entity_.setPosition(110,250);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_atk2.png"){
      aux={864,105,8};
      img_entity_.setPosition(110,120);
      return aux;
    }else if(png == "resources/samurai/sprite_samurai_atk3.png"){
      aux={840,74,7};
      img_entity_.setPosition(110,265);
      return aux;
    }
  }
  return DadosAnimacao{0,0,0};
} 