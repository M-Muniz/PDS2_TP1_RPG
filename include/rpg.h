#ifndef RPG_H_
#define RPG_H_

#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "player.h"
#include "enemy.h"
#include "skill.h"
#include "item.h"
#include "boss.h"

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
    shared_ptr<Sprite> player_sprite; /**< sprite do player. */
    float frame; /**< Realiza a renderização das animações. */
    Player player_; /** Jogador. */
    int enemy_type_; /**< Armazena a informação de tipo do Enemy atual. */
public:
    /**
     * @brief Construtor da classe Rpg.
     */
    Rpg();
    
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
     * @brief Anima os Players do jogo.
     */
    void SetAnimePlayer();

    /**
     * @brief Anima os Enemys do jogo.
     */
    void SetAnimeEnemy();

    /**
     * @brief Gerencia eventos do jogo que acontecem na interface gráfica.
     */
    void Events();

    /**
     * @brief Anima a janela do jogo.
     */
    void Draw();

    void Game();
};
#endif