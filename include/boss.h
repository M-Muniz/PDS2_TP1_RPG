#ifndef BOSS_H_
#define BOSS_H_

#include <iostream>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "skill.h"
#include "entity.h"

using namespace std;
using namespace sf;

/**
 * @brief Classe que representa um chefe (boss) no jogo.
 */
class Boss : public Entity {
friend class Rpg;
public:
  /**
   * @brief Construtor da classe Boss.
   */
  Boss();

  /**
   * @brief Retorna uma das habilidades do chefe (boss) com base no índice.
   * @param Index O índice da habilidade desejada.
   * @return A habilidade do chefe (boss) correspondente ao índice.
   */
  Skill BossSkills(int index);

private:
  vector<Skill> skills_; /**< Vetor de habilidades do chefe (boss). */
};

#endif