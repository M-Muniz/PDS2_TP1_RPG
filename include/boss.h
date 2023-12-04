/**
 * @file boss.h
 * @brief Contém a definição da classe Boss.
 */
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

  /**
   * @brief Retorna path relativo da animaçao de morte.
   * @return O path relativo da animaçao de morte.
   */
  string ReturnSpriteMorte();

    /**
   * @brief Retorna path relativo da animaçao de ataque.
   * @return O path relativo da animaçao de ataque.
   */
  string ReturnSpriteAtk();

   /**
   * @brief Retorna path relativo da animaçao de idle.
   * @return O path relativo da animaçao de idle.
   */
  string ReturnSpriteIdle();

    /**
   * @brief Retorna path relativo da animaçao de defesa.
   * @return O path relativo da animaçao de defesa.
   */
  string ReturnSpriteDef();

    /**
   * @brief Retorna path relativo da animaçao de hurt.
   * @return O path relativo da animaçao de hurt.
   */
  string ReturnSpriteTomou();

  /**
   * @brief Retorna dados do sprite pra facilitar as animaçoes.
   * @return Os dados daquele sprite especifico.
   */
  DadosAnimacao ReturnDadosSprite(string png);

  /**
   * @brief Retorna dados do sprite pra facilitar as animaçoes.
   * @return Os dados daquele sprite especifico.
   */
  void SettaSprite(string Png);

private:
  vector<Skill> skills_; /**< Vetor de habilidades do chefe (boss). */
};

#endif /* BOSS_H_ */