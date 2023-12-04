/**
 * @file entity.cpp
 * @brief Implementação da classe Entity.
 */

#include "../../include/entity.h"

Entity::Entity(){};

Entity::~Entity(){};

int Entity::Atk() { return stats_.atk; }

bool Entity::Def(int atk_opponent)
{
  // A função simula um ataque e uma possível defesa do oponente.
  int aux = rand() % 100;

  if (aux + stats_.agi < 75)
  { // o golpe atingiu o inimigo

    stats_.hp -= atk_opponent - stats_.def;

    if (stats_.hp < 0)
    {
      stats_.hp = 0;
    }

    return true;
  }
  else
  {
    return false; // o não golpe atingiu o inimigo
  }
}

void Entity::BuffaInimigo(int inimigos_mortos)
{
  // Incrementa os atributos do inimigo com base no número de inimigos mortos
  if (inimigos_mortos >= 3)
  {
    int multiplicador = inimigos_mortos / 3;
    stats_.hp_max *= (1.05 * multiplicador);
    stats_.hp = stats_.hp_max;
    stats_.atk *= (1.05 * multiplicador);
    stats_.def *= (1.05 * multiplicador);
    stats_.xp -= multiplicador;
  }
}

Status Entity::ReturnStatus() { return stats_; };

Skill Entity::EntitySkills(int index) { return skills_[index]; };

string Entity::ReturnSpriteMorte() { return ""; };

string Entity::ReturnSpriteAtk() { return ""; };

string Entity::ReturnSpriteIdle() { return ""; };

string Entity::ReturnSpriteDef() { return ""; };

string Entity::ReturnSpriteTomou() { return ""; };

DadosAnimacao Entity::ReturnDadosSprite(string png) { return DadosAnimacao{0, 0, 0}; };

void Entity::SettaSprite(string Png){
    // Carrega e configura o sprite para a entidade
};