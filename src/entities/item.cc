#include "../../include/item.h"

Item::Item(){}

Item::Item(int tipo_item){
  if(tipo_item == 0){ // Item de + Vida
    attributes_.hp = 10;
    attributes_.agi=0;
    attributes_.atk=0;
    attributes_.def=0;
    attributes_.mp=0;
    attributes_.xp=0;
    //img_item_texture_.loadFromFile("resources/hp_item.png");
    //img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 1){ // Item de + Ataque
    attributes_.hp = 0;
    attributes_.agi = 0;
    attributes_.atk = 5;
    attributes_.def = 0;
    attributes_.mp = 0;
    attributes_.xp = 0;
    ///img_item_texture_.loadFromFile("resources/atk_item.png");
    //img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 2){ // Item de + Defesa
    attributes_.hp = 0;
    attributes_.agi = 0;
    attributes_.atk = 0;
    attributes_.def = 5;
    attributes_.mp = 0;
    attributes_.xp = 0;
    //img_item_texture_.loadFromFile("resources/def_item.png");
    //img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 3){ // Item de + Energia
    attributes_.hp = 0;
    attributes_.agi = 0;
    attributes_.atk = 0;
    attributes_.def = 0;
    attributes_.mp = 10;
    attributes_.xp = 0;
    //img_item_texture_.loadFromFile("resources/mp_item.png");
    //img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 4){ // Item de + Experiencia
    attributes_.hp = 0;
    attributes_.agi = 0;
    attributes_.atk = 0;
    attributes_.def = 0;
    attributes_.mp = 0;
    attributes_.xp = 20;
    //img_item_texture_.loadFromFile("resources/xp_item.png");
    //img_item_.setTexture(img_item_texture_);
  }else if(tipo_item == 5){ // Item de + Esquiva
    attributes_.hp = 0;
    attributes_.agi = 5;
    attributes_.atk = 0;
    attributes_.def = 0;
    attributes_.mp = 0;
    attributes_.xp = 0;
    //img_item_texture_.loadFromFile("reosurces/agi_item.png");
    //img_item_.setTexture(img_item_texture_);
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

