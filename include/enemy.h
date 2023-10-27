#ifndef ENEMY_H_
#define ENEMY_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "skill.h"

struct Status {
    int hp;   /**< Vida do inimigo. */
    int atk;  /**< Valor de ataque do inimigo. */
    int def;  /**< Valor de defesa do inimigo. */
    int agi;  /**< Valor de possível esquiva do inimigo. */
};

/**
 * @brief Classe que representa um inimigo no jogo.
 */
class Enemy {
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
     * @param Atk_enemy O valor de ataque do atacante.
     */
    void Def(int Atk_enemy);

    /**
     * @brief Retorna a struct de dados do inimigo.
     * @return A struct de dados do inimigo.
     */
    Status ReturnStatus();

private:
    Status stats_; /**< Estrutura de dados que armazena os status do inimigo. */

    std::string name_; /**< Nome do inimigo. */
};

#endif