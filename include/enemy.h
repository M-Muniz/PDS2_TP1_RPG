#ifndef ENEMY_H_
#define ENEMY_H_

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
 * @brief Classe que representa um inimigo no jogo.
 */
class Enemy {
friend class Rpg;
public:
    /**
     * @brief Construtor da classe Enemy.
     */
    Enemy(int inimigo );

    /**
     * @brief Retorna o valor de ataque do inimigo.
     * @return O valor de ataque do inimigo.
     */
    int Atk();

    /**
     * @brief Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e esquiva do inimigo.
     * @param atk_enemy O valor de ataque do atacante.
     */
    bool Def(int atk_enemy);

    /**
     * @brief Retorna a struct de dados do inimigo.
     * @return A struct de dados do inimigo.
     */
    Status ReturnStatus();

private:
    Status stats_; /**< Estrutura de dados que armazena os status do inimigo. */
    string name_; /**< Nome do inimigo. */
    Texture img_enemy_texture_; /**< Textura para importar para o Sprite. */
    Sprite img_enemy_; /**< Imagem do inimigo para a interface gráfica. */
};

#endif