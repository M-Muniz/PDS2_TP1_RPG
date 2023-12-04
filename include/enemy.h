/**
 * @file enemy.h
 * @brief Contém a definição da classe Enemy.
 */
#ifndef ENEMY_H_
#define ENEMY_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "boss.h"
#include "item.h"
#include "entity.h"

using namespace std;
using namespace sf;

/**
 * @brief Classe que representa um inimigo no jogo.
 */
class Enemy : public Entity {
friend class Rpg;
public:
  /**
   * @brief Construtor da classe Enemy.
   */
  Enemy();

  /**
   * @brief Aumenta os status desse inimigo baseado no numero de inimigos mortos.
   * @param atk_player Numero de inimigos mortos.
   */
  void BuffaInimigo(int inimigos_mortos);

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
   * @brief Retorna path relativo da animaçao de idle.
   * @return O path relativo da animaçao de idle.
   */
  string ReturnSpriteIdle();

  /**
   * @brief Retorna dados do sprite pra facilitar as animaçoes.
   * @param Png O caminho relativo do sprite.
   * @return Os dados daquele sprite especifico.
   */
  DadosAnimacao ReturnDadosSprite(string png);

  /**
   * @brief Retorna dados do sprite pra facilitar as animaçoes.
   * @param Png O caminho relativo do sprite.
   * @return Os dados daquele sprite especifico.
   */
  void SettaSprite(string Png);

private:
};

#endif /* ENEMY_H_ */