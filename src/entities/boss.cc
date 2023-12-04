/**
 * @file boss.cc
 * @brief Implementação da classe Boss.
 */

#include "../../include/boss.h"
#include "../../include/entity.h"

Boss::Boss() : Entity(){
  stats_.hp_max = 1000;
  stats_.hp = stats_.hp_max;
  stats_.atk = 20;
  stats_.def = 20;
  stats_.agi = 20;
  stats_.mp = 30;
  stats_.xp = 80;
    
  name_ = "Is'Abelu";
  img_entity_texture_.loadFromFile("resources/bg_temp.jpg");
  img_entity_.setTexture(img_entity_texture_);
    
  for(int i = 0; i < 3; i++){
    Skill aux(4, i);
    skills_.push_back(aux);
  }
}

string Boss::ReturnSpriteMorte(){
  // if (classe_ == 0){
  //   return "resources/knight/sprite_knight_dead.png";
  // }else if(classe_ == 1 ){
  //   return "resources/mage/sprite_mage_dead.png";
  // }
  // return "resources/samurai/sprite_samurai_dead.png";
  return "";
}

string Boss::ReturnSpriteAtk(){
  // if (classe_ == 0){
  //   return "resources/knight/sprite_knight_atk1.png";
  // }else if(classe_ == 1 ){
  //   return "resources/mage/sprite_mage_atk2.png";
  // }
  // return "resources/samurai/sprite_samurai_atk1.png";
  return "";
} 

string Boss::ReturnSpriteTomou(){
  // if (classe_ == 0){
  //   return "resources/knight/sprite_knight_hurt.png";
  // }else if(classe_ == 1 ){
  //   return "resources/mage/sprite_mage_hurt.png";
  // }
  // return "resources/samurai/sprite_samurai_hurt.png";
  return "";
}

string Boss::ReturnSpriteDef(){
  // if (classe_ == 0){
  //   return "resources/knight/sprite_knight_protect.png";
  // }else if(classe_ == 1 ){
  //   return "resources/mage/sprite_mage_protect.png";
  // }
  // return "resources/samurai/sprite_samurai_protection.png";
  return "";
}

string Boss::ReturnSpriteIdle(){
  // if (classe_ == 0){
  //   return "resources/knight/sprite_knight_default.png";
  // }else if(classe_ == 1 ){
  //   return "resources/mage/sprite_mage_default.png";
  // }
  // return "resources/samurai/sprite_samurai_default.png";
  return "";
}

void Boss::SettaSprite(string png){
  // img_entity_texture_.loadFromFile(png);
  // img_entity_.setTexture(img_entity_texture_);
  // img_entity_.setScale(5,5);
}

//Boss c o Y aumenta 
DadosAnimacao Boss::ReturnDadosSprite(string png){
  // DadosAnimacao aux;
  // if (classe_ == 0){
  //   if(png == "resources/knight/sprite_knight_atk1.png"){
  //     aux={555,75,5};
  //     img_entity_.setPosition(260,260);
  //     return aux;
  //   }else if(png == "resources/knight/sprite_knight_protect.png"){
  //     aux={45,61,1};
  //     img_entity_.setPosition(150,300);
  //     return aux;
  //   }else if(png == "resources/knight/sprite_knight_hurt.png"){
  //     aux={106,61,2};
  //     img_entity_.setPosition(150,300);
  //     return aux;
  //   }else if(png == "resources/knight/sprite_knight_dead.png"){
  //     aux={480,60,6};
  //     img_entity_.setPosition(150,300);
  //     return aux;
  //   }
  // }else if(classe_ == 1 ){
  //   if(png == "resources/mage/sprite_mage_atk2.png"){
  //     aux={990,74,9};
  //     img_entity_.setPosition(125,285);
  //     return aux;
  //   }else if(png == "resources/mage/sprite_mage_protect.png"){
  //     aux={348,87,4};
  //     img_entity_.setPosition(125,165);
  //     return aux;
  //   }else if(png == "resources/mage/sprite_mage_hurt.png"){
  //     aux={132,59,2};
  //     img_entity_.setPosition(125,265);
  //     return aux;
  //   }else if(png == "resources/mage/sprite_mage_dead.png"){
  //     aux={340,59,4};
  //     img_entity_.setPosition(125,285);
  //     return aux;
  //   }
  // }else if(classe_ == 2){
  //   if(png == "resources/samurai/sprite_samurai_atk1.png"){
  //     aux={575,67,5};
  //     img_entity_.setPosition(110,265);
  //     return aux;
  //   }else if(png == "resources/samurai/sprite_samurai_protection.png"){
  //     aux={345,70,5};
  //     img_entity_.setPosition(110,265);
  //     return aux;
  //   }else if(png == "resources/samurai/sprite_samurai_hurt.png"){
  //     aux={210,70,3};
  //     img_entity_.setPosition(110,265);
  //     return aux;
  //   }else if(png == "resources/samurai/sprite_samurai_dead.png"){
  //     aux={480,67,6};
  //     img_entity_.setPosition(110,265);
  //     return aux;
  //   }
  // }
  return DadosAnimacao{0,0,0};
}