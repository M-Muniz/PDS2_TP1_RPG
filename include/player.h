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
#include "boss.h"

using namespace std;
using namespace sf;

/**
 * @brief Classe para representar um jogador no jogo.
 */
class Player{
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
   * @brief Retorna o valor de ataque do Player.
   * @return Valor de ataque.
   */
  int Atk();

  /**
   * @brief Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e esquiva do Player, retorna 0 se o Player esquivou e 1 não se esquivou.
   * @param atk_enemy Valor de ataque do inimigo.
   */
  bool Def(int atk_enemy);

  /**
   * @brief Aumenta os status do Player com base na experiência recebida.
   * @param xp Pontos de experiência a serem adicionados.
   */
  void Upar(int xp);

  /**
   * @brief Retorna a struct de dados do Player.
   * @return Struct contendo os status do Player.
   */
  Status ReturnStatus();

  /**
   * @brief Retorna uma das skills do Player com base no índice.
   * @param index Índice da habilidade desejada.
   * @return Objeto Skill representando a habilidade.
   */
  Skill UserSkills(int index);

  /**
   * @brief Retorna o nome do Player.
   */
  string Name();
  
private:
  int classe_; /**< Classe do Player. */
  string name_; /**< Nome do Player. */
  Status stats_; /**< Status do Player. */
  vector<Skill> skills_; /**< Vetor de habilidades do Player. */
  Texture img_player_texture_; /**< Textura para importar para o Sprite. */
  Sprite img_player_; /**< Imagem do Player para a interface gráfica. */
  vector<vector<bool>> skills_cd_; /**< Computa o cooldown das skills do player. */
  
};

#endif