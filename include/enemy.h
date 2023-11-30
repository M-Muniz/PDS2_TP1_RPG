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

using namespace std;
using namespace sf;

/**
 * @brief Classe que representa um inimigo no jogo.
 */
class Enemy {
friend class Rpg;
public:
  /**
   * @brief Construtor da classe Enemy.
   */
  Enemy();

  /**
   * @brief Retorna o valor de ataque do inimigo.
   * @return O valor de ataque do inimigo.
   */
  int Atk();

  /**
   * @brief Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e esquiva do inimigo.
   * @param atk_player O valor de ataque do atacante.
   */
  bool Def(int atk_player);

  /**
   * @brief Aumenta os status desse inimigo baseado no numero de inimigos mortos.
   * @param atk_player Numero de inimigos mortos.
   */
  void BuffaInimigo(int inimigos_mortos);

  /**
   * @brief Retorna a struct de dados do inimigo.
   * @return A struct de dados do inimigo.
   */
  Status ReturnStatus();
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
   * @return Os dados daquele sprite especifico.
   */
  DadosAnimacao ReturnDadosSprite(string png);
  /**
   * @brief Retorna dados do sprite pra facilitar as animaçoes.
   * @return Os dados daquele sprite especifico.
   */
  void SettaSprite(string Png);

private:
  Status stats_; /**< Estrutura de dados que armazena os status do inimigo. */
  string name_; /**< Nome do inimigo. */
  Texture img_enemy_texture_; /**< Textura para importar para o Sprite. */
  Sprite img_enemy_; /**< Imagem do inimigo para a interface gráfica. */
};

#endif