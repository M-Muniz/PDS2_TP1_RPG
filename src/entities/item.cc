#include "../../include/item.h"

Item::Item(){}

Item::Item(int tipo_item){
  if(tipo_item == 0){ // Item de + Vida
    attributes_.hp = 10;
    img_item_texture_.loadFromFile("resources/itens/hp_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 1){ // Item de + Ataque
    attributes_.atk = 5;
    img_item_texture_.loadFromFile("resources/itens/atk_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 2){ // Item de + Defesa
    attributes_.def = 5;
    img_item_texture_.loadFromFile("resources/itens/def_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 3){ // Item de + Energia
    attributes_.mp = 10;
    img_item_texture_.loadFromFile("resources/itens/mp_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 4){ // Item de + Experiencia
    attributes_.xp = 5;
    img_item_texture_.loadFromFile("resources/itens/xp_item.png");
    img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 5){ // Item de + Esquiva
    attributes_.agi = 5;
    img_item_texture_.loadFromFile("reosurces/itens/agi_item.png");
    img_item_.setTexture(img_item_texture_);
  }
}

void Item::Sum(Player& usr){
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

