#include "../../include/boss.h"

Boss::Boss(){
  stats_.hp_max = 1000;
  stats_.hp = stats_.hp_max;
  stats_.atk = 20;
  stats_.def = 20;
  stats_.agi = 20;
  stats_.mp = 30;
  stats_.xp = 80;
    
  name_ = "Is'Abelu";
  img_boss_texture_.loadFromFile("resources/bg_temp.jpg");
  img_boss_.setTexture(img_boss_texture_);
    
  for(int i = 0; i < 3; i++){
    Skill aux(4, i, nullptr, nullptr);
    skills_.push_back(aux);
  }
}

int Boss::Atk(){return stats_.atk;}

bool Boss::Def(int atk_player){
  int x = rand() % 100;

  if (x + stats_.agi < 65){ // Boss não desviou
    stats_.hp -= (atk_player - stats_.def);
        
    return 1;
  }else{ // Boss desviou
    return 0;
  }
}

Status Boss::ReturnStatus(){return stats_;}

