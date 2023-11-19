#ifndef BOSS_H_
#define BOSS_H_

class Skill;

#include <iostream>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "skill.h"

using namespace std;
using namespace sf;

/**
 * @brief Estrutura de dados para armezenas os status do objeto.
 */
struct Status {
  int hp_max; /**< Vida máxima do objeto. */
  int hp;   /**< Vida do objeto. */
  int atk;  /**< Valor de ataque do objeto. */
  int def;  /**< Valor de defesa do objeto. */
  int mp; /**< Valore de mana do usuário. */
  int xp;   /**< Valor de experiência do objeto. */
  int agi;  /**< Valor de possível esquiva do objeto. */
};
/**
 * @brief Classe que representa um chefe (boss) no jogo.
 */
class Boss {
friend class Rpg;
public:
  /**
   * @brief Construtor da classe Boss.
   */
  Boss();

  /**
   * @brief Retorna o valor de ataque do chefe (boss).
   * @return O valor de ataque do chefe (boss).
   */
  int Atk();

  /**
   * @brief Recebe o valor de ataque do jogador e subtrai da vida com base na defesa e esquiva do chefe (boss).
   * @param atk_player O valor de ataque do jogador.
   */
  bool Def(int atk_player);

  /**
   * @brief Retorna a struct de dados do chefe (boss).
   * @return A struct de dados do chefe (boss).
   */
  Status ReturnStatus();

  /**
   * @brief Retorna uma das habilidades do chefe (boss) com base no índice.
   * @param Index O índice da habilidade desejada.
   * @return A habilidade do chefe (boss) correspondente ao índice.
   */
  Skill BossSkills(int index);

private:
  /**
   * @brief Estrutura de dados que armazena os status do chefe (boss).
   */
  Status stats_;
  string name_; /**< Nome do chefe (boss). */
  Texture img_boss_texture_; /**< Textura para importar para o Sprite*/
  Sprite img_boss_; /**< Imagem do chefe (boss) para a interface gráfica. */
  vector<Skill> skills_; /**< Vetor de habilidades do chefe (boss). */
};

#endif
