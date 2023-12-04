/**
 * @file enemy.cpp
 * @brief Implementação da classe Enemy.
 */

#include "../../include/enemy.h"
#include "../../include/entity.h"

Enemy::Enemy() : Entity()
{
  int inimigo = rand() % 4;
  if (inimigo == 0)
  { /*o inimigo 0 corresponde a um inimigo mais balanceado*/
    // Definição dos stats do inimigo balanceado
    // stats_.hp_max = 80;
    stats_.hp_max = 10;
    stats_.hp = stats_.hp_max;
    stats_.atk = 45;
    stats_.def = 10;
    stats_.agi = 10;
    stats_.mp = 0;
    stats_.xp = 20;
    img_entity_texture_.loadFromFile("resources/spear_skeleton/sprite_spearskeleton_default.png");
    img_entity_.setTexture(img_entity_texture_);
    name_ = "Spear Skeleton";
    img_entity_.setScale(-5, 5);
  }
  else if (inimigo == 1)
  { /*o inimigo 1 corresponde a um inimigo mais agressivo*/
    // Definição dos stats do inimigo agressivo
    // stats_.hp_max = 40;
    stats_.hp_max = 10;
    stats_.hp = stats_.hp_max;
    stats_.atk = 60;
    stats_.def = 0;
    stats_.agi = 15;
    stats_.mp = 0;
    stats_.xp = 20;
    img_entity_texture_.loadFromFile("resources/warewolf/sprite_warewolf_default.png");
    img_entity_.setTexture(img_entity_texture_);
    name_ = "Small Werewolf";
    img_entity_.setScale(-3, 3);
  }
  else if (inimigo == 2)
  { /*o inimigo 2 corresponde a um inimigo mais defensivo*/
    // Definição dos stats do inimigo defensivo
    // stats_.hp_max = 135;
    stats_.hp_max = 10;
    stats_.hp = stats_.hp_max;
    stats_.atk = 40;
    stats_.def = 0;
    stats_.agi = 5;
    stats_.mp = 0;
    stats_.xp = 30;
    img_entity_texture_.loadFromFile("resources/warewolf/sprite_warewolf_default.png");
    img_entity_.setTexture(img_entity_texture_);
    name_ = "Big Werewolf";
    img_entity_.setScale(-6, 6);
  }
  else if (inimigo == 3)
  { /*o inimigo 3 corresponde a um inimigo mais balanceado*/
    // Definição dos stats do outro inimigo balanceado
    // stats_.hp_max = 70;
    stats_.hp_max = 10;
    stats_.hp = stats_.hp_max;
    stats_.atk = 50;
    stats_.def = 15;
    stats_.agi = 15;
    stats_.mp = 0;
    stats_.xp = 25;
    img_entity_texture_.loadFromFile("resources/sword_skeleton/sprite_swordskeleton_default.png");
    img_entity_.setTexture(img_entity_texture_);
    name_ = "Sword Skeleton";
    img_entity_.setScale(-5, 5);
  }
}

string Enemy::ReturnSpriteMorte()
{
  // Implementação do retorno do sprite de morte para diferentes tipos de inimigos
  if (name_ == "Spear Skeleton")
  {
    return "resources/spear_skeleton/sprite_spearskeleton_dead.png";
  }
  else if (name_ == "Sword Skeleton")
  {
    return "resources/sword_skeleton/sprite_swordskeleton_dead.png";
  }
  else if (name_ == "Big Werewolf" || name_ == "Small Werewolf")
  {
    return "resources/warewolf/sprite_warewolf_dead.png";
  }
  return " ";
}
string Enemy::ReturnSpriteAtk()
{
  // Implementação do retorno do sprite de ataque para diferentes tipos de inimigos
  if (name_ == "Spear Skeleton")
  {
    return "resources/spear_skeleton/sprite_spearskeleton_atk1.png";
  }
  else if (name_ == "Sword Skeleton")
  {
    return "resources/sword_skeleton/sprite_swordskeleton_atk1.png";
  }
  else if (name_ == "Big Werewolf" || name_ == "Small Werewolf")
  {
    return "resources/warewolf/sprite_warewolf_atk1.png";
  }
  return " ";
}
string Enemy::ReturnSpriteTomou()
{
  // Implementação do retorno do sprite de dano recebido para diferentes tipos de inimigos
  if (name_ == "Spear Skeleton")
  {
    return "resources/spear_skeleton/sprite_spearskeleton_hurt.png";
  }
  else if (name_ == "Sword Skeleton")
  {
    return "resources/sword_skeleton/sprite_swordskeleton_hurt.png";
  }
  else if (name_ == "Big Werewolf" || name_ == "Small Werewolf")
  {
    return "resources/warewolf/sprite_warewolf_hurt.png";
  }
  return " ";
}
string Enemy::ReturnSpriteDef()
{
  // Implementação do retorno do sprite de defesa para diferentes tipos de inimigos
  if (name_ == "Spear Skeleton")
  {
    return "resources/spear_skeleton/sprite_spearskeleton_protect.png";
  }
  else if (name_ == "Sword Skeleton")
  {
    return "resources/sword_skeleton/sprite_swordskeleton_protect.png";
  }
  else if (name_ == "Big Werewolf" || name_ == "Small Werewolf")
  {
    return "resources/warewolf/sprite_warewolf_protect.png";
  }
  return " ";
}
string Enemy::ReturnSpriteIdle()
{
  // Implementação do retorno do sprite de idle para diferentes tipos de inimigos
  if (name_ == "Spear Skeleton")
  {
    img_entity_.setPosition(1100, 215);
    return "resources/spear_skeleton/sprite_spearskeleton_default.png";
  }
  else if (name_ == "Sword Skeleton")
  {
    img_entity_.setPosition(1050, 320);
    return "resources/sword_skeleton/sprite_swordskeleton_default.png";
  }
  else if (name_ == "Big Werewolf" || name_ == "Small Werewolf")
  {
    if (name_ == "Big Werewolf")
    {
      img_entity_.setPosition(1200, 270);
    }
    else
    {
      img_entity_.setPosition(1050, 450);
    }
    return "resources/warewolf/sprite_warewolf_default.png";
  }
  return " ";
}
void Enemy::SettaSprite(string png)
{
  // Implementação para carregar textura e configurar o sprite do inimigo
  img_entity_texture_.loadFromFile(png);
  img_entity_.setTexture(img_entity_texture_);
  if (name_ == "Spear Skeleton")
  {
    img_entity_.setScale(-5, 5);
  }
  else if (name_ == "Sword Skeleton")
  {
    img_entity_.setScale(-5, 5);
  }
  else if (name_ == "Big Werewolf")
  {
    img_entity_.setScale(-6, 6);
  }
  else if (name_ == "Small Werewolf")
  {
    img_entity_.setScale(-3, 3);
  }
  return;
}
DadosAnimacao Enemy::ReturnDadosSprite(string png)
{
  // Implementação para retornar dados específicos de animação com base no sprite solicitado
  DadosAnimacao aux;
  if (name_ == "Spear Skeleton")
  {
    if (png == "resources/spear_skeleton/sprite_spearskeleton_dead.png")
    {
      aux = {575, 83, 5};
      img_entity_.setPosition(1100, 215);
      return aux;
    }
    if (png == "resources/spear_skeleton/sprite_spearskeleton_atk1.png")
    {
      aux = {528, 54, 4};
      img_entity_.setPosition(1100, 350);
      return aux;
    }
    if (png == "resources/spear_skeleton/sprite_spearskeleton_hurt.png")
    {
      aux = {240, 83, 3};
      img_entity_.setPosition(1100, 210);
      return aux;
    }
    if (png == "resources/spear_skeleton/sprite_spearskeleton_protect.png")
    {
      aux = {136, 70, 2};
      img_entity_.setPosition(1100, 260);
      return aux;
    }
  }
  else if (name_ == "Sword Skeleton")
  {
    if (png == "resources/sword_skeleton/sprite_swordskeleton_dead.png")
    {
      aux = {296, 59, 4};
      img_entity_.setPosition(1050, 320);
      return aux;
    }
    if (png == "resources/sword_skeleton/sprite_swordskeleton_atk1.png")
    {
      aux = {620, 78, 5};
      img_entity_.setPosition(1050, 245);
      return aux;
    }
    if (png == "resources/sword_skeleton/sprite_swordskeleton_hurt.png")
    {
      aux = {120, 63, 2};
      img_entity_.setPosition(1050, 300);
      return aux;
    }
    if (png == "resources/sword_skeleton/sprite_swordskeleton_protect.png")
    {
      aux = {36, 62, 1};
      img_entity_.setPosition(1050, 300);
      return aux;
    }
  }
  else if (name_ == "Big Werewolf" || name_ == "Small Werewolf")
  {
    if (png == "resources/warewolf/sprite_warewolf_dead.png")
    {
      aux = {190, 52, 2};
      if (name_ == "Big Werewolf")
      {
        img_entity_.setPosition(1200, 270);
      }
      else
      {
        img_entity_.setPosition(1050, 450);
      }
      return aux;
    }
    if (png == "resources/warewolf/sprite_warewolf_atk1.png")
    {
      aux = {792, 90, 6};
      if (name_ == "Big Werewolf")
      {
        img_entity_.setPosition(1200, 100);
      }
      else
      {
        img_entity_.setPosition(1000, 350);
      }
      return aux;
    }
    if (png == "resources/warewolf/sprite_warewolf_hurt.png")
    {
      aux = {190, 56, 2};
      if (name_ == "Big Werewolf")
      {
        img_entity_.setPosition(1200, 260);
      }
      else
      {
        img_entity_.setPosition(1000, 440);
      }
      return aux;
    }
    if (png == "resources/warewolf/sprite_warewolf_protect.png")
    {
      aux = {75, 93, 1};
      if (name_ == "Big Werewolf")
      {
        img_entity_.setPosition(1200, 100);
      }
      else
      {
        img_entity_.setPosition(1000, 350);
      }
      return aux;
    }
  }
  return DadosAnimacao{0, 0, 0};
}