#ifndef BOSS_H
#define BOSS_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <Skill.h>

/**
 * @brief Classe que representa um chefe (boss) no jogo.
 */
class Boss {
public:
    /**
     * @brief Construtor da classe Boss.
     */
    Boss();

    /**
     * @brief Retorna o valor de ataque do chefe (boss).
     * @return O valor de ataque do chefe (boss).
     */
    int Atk();

    /**
     * @brief Recebe o valor de ataque do jogador e subtrai da vida com base na defesa e esquiva do chefe (boss).
     * @param Atk_player O valor de ataque do jogador.
     */
    void Def(int Atk_player);

    /**
     * @brief Retorna a struct de dados do chefe (boss).
     * @return A struct de dados do chefe (boss).
     */
    Status returnStatus();

    /**
     * @brief Retorna uma das habilidades do chefe (boss) com base no índice.
     * @param Index O índice da habilidade desejada.
     * @return A habilidade do chefe (boss) correspondente ao índice.
     */
    Skill bossSkills(int Index);

private:
    /**
     * @brief Estrutura de dados que armazena os status do chefe (boss).
     */
    struct Status {
        int Hp;   /**< Vida do chefe (boss). */
        int Atk;  /**< Valor de ataque do chefe (boss). */
        int Def;  /**< Valor de defesa do chefe (boss). */
        int Xp;   /**< Valor de experiência passado ao jogador. */
        int Agi;  /**< Valor de possível esquiva do chefe (boss). */
    };

    std::string Name; /**< Nome do chefe (boss). */
    sf::Sprite img_Boss; /**< Imagem do chefe (boss) para a interface gráfica. */
    Skill Skills; /**< Habilidades do chefe (boss). */
};

#endif // BOSS_H
