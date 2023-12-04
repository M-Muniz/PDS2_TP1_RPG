#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "skill.h"

/**
 * @brief Estrutura de dados para a animação.
 */
struct DadosAnimacao {
  int largura; /**< Largura da animação. */
  int altura; /**< Altura da animação. */
  int frames; /**< Número de frames da animação. */
};

/**
 * @brief Estrutura de dados para armazenar os status da entidade.
 */
struct Status {
  int hp_max; /**< Vida máxima da entidade. */
  int hp; /**< Vida atual da entidade. */
  int atk; /**< Valor de ataque da entidade. */
  int def; /**< Valor de defesa da entidade. */
  int mp; /**< Valor de mana da entidade. */
  int xp; /**< Valor de experiência da entidade. */
  int agi; /**< Valor de agilidade da entidade. */
};

/**
 * @brief Classe base que representa uma entidade no jogo.
 */
class Entity {
friend class Rpg;
public:
  /**
   * @brief Construtor da classe Entity.
   */
  Entity();

  /**
   * @brief Destrutor da classe Entity.
   */
  virtual ~Entity();

  /**
   * @brief Retorna o valor de ataque da entidade.
   * @return O valor de ataque da entidade.
   */
  int Atk();

  /**
   * @brief Recebe o valor de ataque do oponente e subtrai da vida com base na defesa e esquiva da entidade.
   * @param atk_opponent O valor de ataque do oponente.
   * @return Verdadeiro se a entidade não esquivou, falso se esquivou.
   */
  bool Def(int atk_opponent);

   /**
   * @brief Buffa os inimigos com base na quantidade de inimigos mortos.
   * @param inimigos_mortos A quantidade de inimigos mortos.
   */
  void BuffaInimigo(int inimigos_mortos);

  /**
   * @brief Retorna a struct de dados de status da entidade.
   * @return A struct de dados de status da entidade.
   */
  Status ReturnStatus();

  /**
   * @brief Retorna uma das habilidades da entidade com base no índice.
   * @param index O índice da habilidade desejada.
   * @return A habilidade correspondente ao índice.
   */
  virtual Skill EntitySkills(int index){ return Skill{};};

  /**
   * @brief Retorna o nome da entidade.
   * @return O nome da entidade.
   */
  string Name();

  // Métodos comuns para animações

  /**
   * @brief Retorna o caminho relativo da animação de morte.
   * @return O caminho relativo da animação de morte.
   */
  virtual string ReturnSpriteMorte();

  /**
   * @brief Retorna o caminho relativo da animação de ataque.
   * @return O caminho relativo da animação de ataque.
   */
  virtual string ReturnSpriteAtk();

  /**
   * @brief Retorna o caminho relativo da animação de idle.
   * @return O caminho relativo da animação de idle.
   */
  virtual string ReturnSpriteIdle();

  /**
   * @brief Retorna o caminho relativo da animação de defesa.
   * @return O caminho relativo da animação de defesa.
   */
  virtual string ReturnSpriteDef();

  /**
   * @brief Retorna o caminho relativo da animação de dano.
   * @return O caminho relativo da animação de dano.
   */
  virtual string ReturnSpriteTomou();

  /**
   * @brief Retorna dados do sprite para facilitar as animações.
   * @param png O caminho relativo da imagem do sprite.
   * @return Os dados da animação especificada.
   */
  virtual DadosAnimacao ReturnDadosSprite(string png);

  /**
   * @brief Define a textura do sprite da entidade.
   * @param Png O caminho relativo da nova textura.
   */
  virtual void SettaSprite(string Png);

protected:
  Status stats_; /**< Estrutura de dados que armazena os status da entidade. */
  string name_; /**< Nome da entidade. */
  Texture img_entity_texture_; /**< Textura para importar para o Sprite. */
  Sprite img_entity_; /**< Imagem da entidade para a interface gráfica. */
  vector<Skill> skills_; /**< Vetor de habilidades da entidade. */
};

#endif