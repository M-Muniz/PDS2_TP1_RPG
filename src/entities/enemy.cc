#include "../../include/enemy.h"

Enemy::Enemy(){
  int inimigo = rand() % 4;
  int item = rand() % 6;
  drop_item_=Item(item);
  if(inimigo == 0){/*o inimigo 0 corresponde a um inimigo mais balanceado*/         
    stats_.hp_max = 1;
    stats_.hp = stats_.hp_max;
    stats_.atk = 45;
    stats_.def = 10;
    stats_.agi = 10;
    stats_.mp = 0;
    stats_.xp = 20;
    img_enemy_texture_.loadFromFile("resources/spear_skeleton/sprite_spearskeleton_default.png");
    img_enemy_.setTexture(img_enemy_texture_);
    name_ = "Spear Skeleton";
    img_enemy_.setScale(-5,5);
  }else if(inimigo == 1){/*o inimigo 1 corresponde a um inimigo mais agressivo*/ 
    stats_.hp_max = 1;
    stats_.hp = stats_.hp_max;
    stats_.atk = 60;
    stats_.def = 0;
    stats_.agi = 15;
    stats_.mp = 0;
    stats_.xp = 20;
    img_enemy_texture_.loadFromFile("resources/black_wolf/sprite_blackwolf_default.png");
    img_enemy_.setTexture(img_enemy_texture_);
    name_ = "Small Werewolf";
    img_enemy_.setScale(-3,3);
  }else if(inimigo == 2){/*o inimigo 2 corresponde a um inimigo mais defensivo*/ 
    stats_.hp_max = 1;
    stats_.hp = stats_.hp_max;
    stats_.atk = 40;
    stats_.def = 0;
    stats_.agi = 5;
    stats_.mp = 0;
    stats_.xp = 30;
    img_enemy_texture_.loadFromFile("resources/black_wolf/sprite_blackwolf_default.png");
    img_enemy_.setTexture(img_enemy_texture_);
    name_ = "Big Werewolf";
    img_enemy_.setScale(-7,7);
  }else if(inimigo == 3){/*o inimigo 3 corresponde a um inimigo mais balanceado*/ 
    stats_.hp_max = 1;
    stats_.hp = stats_.hp_max;
    stats_.atk = 50;
    stats_.def = 15;
    stats_.agi = 15;
    stats_.mp = 0;
    stats_.xp = 25;
    img_enemy_texture_.loadFromFile("resources/sword_skeleton/sprite_swordskeleton_default.png");
    img_enemy_.setTexture(img_enemy_texture_);
    name_ = "Sword Skeleton";
    img_enemy_.setScale(-5,5);
  }

}

int Enemy::Atk(){return stats_.atk;}

bool Enemy::Def(int atk_player){
  int aux = rand() % 100;

  if(aux+stats_.agi < 70){/* o golpe atingiu o inimigo */
   
    stats_.hp -= atk_player - stats_.def;

    return true;
  }else{    
    return false;   /* o não golpe atingiu o inimigo */
  }

}

Status Enemy::ReturnStatus(){return stats_;}
