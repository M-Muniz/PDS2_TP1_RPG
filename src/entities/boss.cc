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
