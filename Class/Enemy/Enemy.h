#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <Skill.h>

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
    Status returnStatus();

private:
    /**
     * @brief Estrutura de dados que armazena os status do inimigo.
     */
    struct Status {
        int Hp;   /**< Vida do inimigo. */
        int Atk;  /**< Valor de ataque do inimigo. */
        int Def;  /**< Valor de defesa do inimigo. */
        int Agi;  /**< Valor de possível esquiva do inimigo. */
    };

    std::string Name; /**< Nome do inimigo. */
};

#endif // ENEMY_H
