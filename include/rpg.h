#ifndef RPG_H_
#define RPG_H_

#include <vector>
#include <string>
#include <memory>
#include <list>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "player.h"
#include "boss.h"
#include "enemy.h"

using namespace std;
using namespace sf;

/**
 * @brief Classe principal para o jogo de RPG.
 */
class Rpg {

public:
    
  shared_ptr<RenderWindow> window; /**< Janela. */
    
  Texture bg; /**< Textura para importar para o backgroud da tela. */
  shared_ptr<Sprite> background; /**< Background da tela. */
    
  vector<RectangleShape> buttons_; /**< Vetor para os botões clicáveis. */
  vector<RectangleShape> player_status_; /**< Barras de mana e vida do Player. */
  vector<vector<RectangleShape>> cd_skills_; /**< Mostradores para o cooldown das skills do player. */

  vector<Text> texts_; /**< Vetor para posicionar os textos na tela. */
  Text player_name_; /**< Texto para plotar o nome do Player na tela. */
  vector<Vector2f> texts_coords_; /**< Vetor para posicionar os textos na tela. */
  vector<string> texts_strings_; /**< Vetor para posicionar os textos na tela. */
    

  Player player_; /**< Jogador. */
  vector<Enemy> enemys_; /**< Lista de Enemys para o jogo. */
  vector<Boss> boss_; /**< Lista de Boss's para o jogo. */

  Vector2i pos_mouse_;
  Vector2f mouse_coord_;


  float frame_e_,frame_p_;

public:
  /**
   * @brief Construtor da classe Rpg.
   */
  Rpg(Player jogador);
    
  /**
   * @brief Inicia o jogo de RPG.
   */
  void Run();

  private:
  /**
   * @brief Move os inimigos no jogo.
   */
  void MoveEnemys();

  /**
   * @brief Anima os objetos Player do jogo.
   */
  void SetAnimePlayer();

  /**
   * @brief Anima os objetos Enemy do jogo.
   */
  void SetAnimeEnemy();

  /**
   * @brief Gerencia eventos do jogo que acontecem na interface gráfica.
   */
  int Events();

  /**
   * @brief Anima a janela do jogo.
   */
  void Draw();

  void Game();
};
#endif