/**
 * @file item.cc
 * @brief Implementação da classe Item.
 */

#include "../../include/item.h"

Item::Item(){}

Item::Item(int tipo_item){
  // Inicialização do item com base no tipo
  if(tipo_item == 0){ // Item de + Vida (vermelho)
    attributes_.hp = 10;
    attributes_.agi=0;
    attributes_.atk=0;
    attributes_.def=0;
    attributes_.mp=0;
    attributes_.xp=0;
    img_item_texture_.loadFromFile("resources/Itens/hp_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 1){ // Item de + Ataque (espada)
    attributes_.hp = 0;
    attributes_.agi = 0;
    attributes_.atk = 5;
    attributes_.def = 0;
    attributes_.mp = 0;
    attributes_.xp = 0;
    img_item_texture_.loadFromFile("resources/Itens/atk_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 2){ // Item de + Defesa (escudo)
    attributes_.hp = 0;
    attributes_.agi = 0;
    attributes_.atk = 0;
    attributes_.def = 5;
    attributes_.mp = 0;
    attributes_.xp = 0;
    img_item_texture_.loadFromFile("resources/Itens/def_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 3){ // Item de + Energia (azul)
    attributes_.hp = 0;
    attributes_.agi = 0;
    attributes_.atk = 0;
    attributes_.def = 0;
    attributes_.mp = 10;
    attributes_.xp = 0;
    img_item_texture_.loadFromFile("resources/Itens/mp_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 4){ // Item de + Experiencia (verde)
    attributes_.hp = 0;
    attributes_.agi = 0;
    attributes_.atk = 0;
    attributes_.def = 0;
    attributes_.mp = 0;
    attributes_.xp = 20;
    img_item_texture_.loadFromFile("resources/Itens/xp_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 5){ // Item de + Esquiva (bota)
    attributes_.hp = 0;
    attributes_.agi = 5;
    attributes_.atk = 0;
    attributes_.def = 0;
    attributes_.mp = 0;
    attributes_.xp = 0;
    img_item_texture_.loadFromFile("resources/Itens/agi_item.png");
    img_item_.setTexture(img_item_texture_);
  }
  img_item_.setScale(3,3);
}

void Item::Sum(Player& usr){
  // Adiciona os atributos do item ao jogador
  usr.stats_.hp += attributes_.hp;
  if(usr.stats_.hp > usr.stats_.hp_max){
    usr.stats_.hp = usr.stats_.hp_max;
  }
  usr.stats_.atk += attributes_.atk;
  usr.stats_.def += attributes_.def;
  usr.stats_.mp += attributes_.mp;
  usr.stats_.xp += attributes_.xp;
  usr.stats_.agi += attributes_.agi;
}