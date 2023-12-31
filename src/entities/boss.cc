/**
 * @file boss.cc
 * @brief Implementação da classe Boss.
 */

#include "../../include/boss.h"
#include "../../include/entity.h"

/**
 * @brief Construtor da classe Boss.
 * Inicializa os atributos de status, nome e textura do Boss, bem como adiciona uma habilidade ao vetor de habilidades.
 */
Boss::Boss() : Entity(){
  stats_.hp_max = 400;
  stats_.hp = stats_.hp_max;
  stats_.atk = 55;
  stats_.def = 15;
  stats_.agi = 15;
  stats_.mp = 30;
  stats_.xp = 80;
    
  name_ = "Is'Abelu";
  img_entity_texture_.loadFromFile("resources/boss/sprite_boss_default.png");
  img_entity_.setTexture(img_entity_texture_);
  img_entity_.setScale(-5.8,5.8);
    
  // Adiciona uma habilidade ao vetor de habilidades
  Skill aux(4, 0);
  skills_.push_back(aux);
}

/**
 * @brief Retorna a habilidade do Boss com base no índice.
 * @param index O índice da habilidade desejada.
 * @return Objeto Skill representando a habilidade.
 */
Skill Boss::EntitySkills(int index){ return skills_[index]; }

/**
 * @brief Retorna o caminho relativo da animação de morte do Boss.
 * @return O caminho relativo da animação de morte.
 */
string Boss::ReturnSpriteMorte(){
  return "resources/boss/sprite_boss_dead.png";
}

/**
 * @brief Retorna o caminho relativo da animação de ataque do Boss.
 * @return O caminho relativo da animação de ataque.
 */
string Boss::ReturnSpriteAtk(){
  return "resources/boss/sprite_boss_atk.png";
} 

/**
 * @brief Retorna o caminho relativo da animação de dano recebido pelo Boss.
 * @return O caminho relativo da animação de dano.
 */
string Boss::ReturnSpriteTomou(){
  return "resources/boss/sprite_boss_hurt.png";
}

/**
 * @brief Retorna o caminho relativo da animação de defesa do Boss.
 * @return O caminho relativo da animação de defesa.
 */
string Boss::ReturnSpriteDef(){
return "resources/boss/sprite_boss_protect.png";
}

/**
 * @brief Retorna o caminho relativo da animação de repouso (idle) do Boss.
 * @return O caminho relativo da animação de repouso.
 */
string Boss::ReturnSpriteIdle(){
  return "resources/boss/sprite_boss_default.png";
}

/**
 * @brief Retorna o caminho relativo da animação da habilidade do Boss.
 * @return O caminho relativo da animação da habilidade.
 */
string Boss::ReturnSpriteSkill(){
  return "resources/boss/sprite_boss_skill.png";
}

/**
 * @brief Define a textura do Boss com base no caminho relativo fornecido.
 * @param png O caminho relativo da imagem do sprite.
 */
void Boss::SettaSprite(string png){
  if(!img_entity_texture_.loadFromFile(png)){
    throw ErroLoadFromFile{};
  }
  img_entity_.setTexture(img_entity_texture_);
  img_entity_.setScale(-5.8,5.8);
}

/**
 * @brief Retorna dados específicos para facilitar a animação com base no caminho relativo da imagem do sprite.
 * @param png O caminho relativo da imagem do sprite.
 * @return Os dados daquele sprite específico.
 */
//Boss c o Y aumenta 
DadosAnimacao Boss::ReturnDadosSprite(string png){
  DadosAnimacao aux{0,0,0};
  if(png == "resources/boss/sprite_boss_default.png"){
    aux = {879,111,8};
    img_entity_.setPosition(1300,0);
  }else if(png == "resources/boss/sprite_boss_dead.png" ){
    aux = {1272,149,12};
    img_entity_.setPosition(1300,-240);
  }else if(png == "resources/boss/sprite_boss_atk.png" ){
    aux = {1488,120,6};
    img_entity_.setPosition(1420,-90);
  }else if(png == "resources/boss/sprite_boss_hurt.png"){
    aux = {462,110,3};
    img_entity_.setPosition(1480,0);
  }else if(png == "resources/boss/sprite_boss_protect.png"){
    aux = {134,89,1};
    img_entity_.setPosition(1300,100);
  }else if(png == "resources/boss/sprite_boss_skill.png"){
    aux = {1880,139,8};
    img_entity_.setPosition(1600,-200);
  }
  return aux;
}