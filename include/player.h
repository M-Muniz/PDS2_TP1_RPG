#ifndef PLAYER_H_
#define PLAYER_H_

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
 * @brief Classe para representar um jogador no jogo.
 */
class Player : public Entity {
friend class Item;
friend class Rpg;
public:
  /**
   * @brief Construtor da classe Player.
   * @param nome Nome do Player.
   * @param classe Classe do Player.
   */
  Player(string nome, int classe);

  /**
   * @brief Construtor vazio da classe Player.
   */
  Player();

  /**
   * @brief Aumenta os status do Player com base na experiência recebida.
   * @param xp Pontos de experiência a serem adicionados.
   */
  void Upar(int xp);

  /**
   * @brief Retorna uma das skills do Player com base no índice.
   * @param index Índice da habilidade desejada.
   * @return Objeto Skill representando a habilidade.
   */
  Skill EntitySkills(int index);

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
   * @brief Retorna path relativo da animaçao de ataque.
   * @return O path relativo da animaçao de ataque.
   */
  string ReturnSpriteSkill(int index);
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
  int classe_; /**< Classe do Player. */
  vector<Skill> skills_; /**< Vetor de habilidades do Player. */
  vector<vector<bool>> skills_cd_; /**< Computa o cooldown das skills do player. */
};

#endif 