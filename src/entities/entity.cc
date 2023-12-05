/**
 * @file entity.cc
 * @brief Implementação da classe Entity.
 */

#include "../../include/entity.h"

Entity::Entity(){};

Entity::~Entity(){};

/**
 * @brief Retorna o valor de ataque da entidade.
 * @return Valor de ataque da entidade.
 */
int Entity::Atk() { return stats_.atk; }

/**
 * @brief Simula um ataque e a possível defesa da entidade.
 * @param atk_opponent Valor de ataque do oponente.
 * @return true se o golpe atingir a entidade, false se a entidade se esquivar.
 */
bool Entity::Def(int atk_opponent)
{
  int aux = rand() % 100;

  if (aux + stats_.agi < 75)
  { ///< o golpe atingiu o inimigo

    stats_.hp -= atk_opponent - stats_.def;

    if (stats_.hp < 0)
    {
      stats_.hp = 0;
    }

    return true;
  }
  else
  {
    return false; ///< o não golpe atingiu o inimigo
  }
}

/**
 * @brief Incrementa os atributos da entidade com base no número de inimigos mortos.
 * @param inimigos_mortos Número de inimigos mortos.
 */
void Entity::BuffaInimigo(int inimigos_mortos)
{
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

/**
 * @brief Retorna uma habilidade da entidade com base no índice.
 * @param index Índice da habilidade desejada.
 * @return Habilidade da entidade.
 */
Skill Entity::EntitySkills(int index) { return skills_[index]; };

/**
 * @brief Retorna o caminho do sprite de morte da entidade.
 * @return Caminho do sprite de morte.
 * As outras funções a seguir seguem a mesma lógica, apenas trocando morte por ataque, idle, defesa ou dano.
 */
string Entity::ReturnSpriteMorte() { return ""; };

string Entity::ReturnSpriteAtk() { return ""; };

string Entity::ReturnSpriteIdle() { return ""; };

string Entity::ReturnSpriteDef() { return ""; };

string Entity::ReturnSpriteTomou() { return ""; };

/**
 * @brief Retorna dados específicos de animação com base no caminho do sprite fornecido.
 * @param png Caminho do sprite para o qual os dados de animação são solicitados.
 * @return Dados de animação específicos do sprite.
 */
DadosAnimacao Entity::ReturnDadosSprite(string png) { return DadosAnimacao{0, 0, 0}; };

/**
 * @brief Carrega e configura o sprite para a entidade.
 * @param Png Caminho do sprite a ser configurado.
 */
void Entity::SettaSprite(string Png){
    // Carrega e configura o sprite para a entidade
};