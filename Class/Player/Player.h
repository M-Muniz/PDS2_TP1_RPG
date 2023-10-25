#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <Skill.h>

/**
 * @brief Classe que representa o jogador no jogo.
 */
class Player {
public:
    /**
     * @brief Construtor da classe Player.
     */
    Player();

    /**
     * @brief Retorna o valor de ataque do jogador.
     * @return O valor de ataque do jogador.
     */
    int Atk();

    /**
     * @brief Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e esquiva do jogador.
     * @param Atk_enemy O valor de ataque do atacante.
     */
    void Def(int Atk_enemy);

    /**
     * @brief Aumenta os status do jogador com base na experiência recebida.
     * @param Xp A quantidade de experiência recebida.
     */
    void Upar(int Xp);

    /**
     * @brief Retorna a struct de dados do jogador.
     * @return A struct de dados do jogador.
     */
    Status returnStatus();

    /**
     * @brief Retorna uma das habilidades do jogador com base no índice.
     * @param Index O índice da habilidade desejada.
     * @return A habilidade do jogador correspondente ao índice.
     */
    Skill userSkills(int Index);

private:
    /**
     * @brief Estrutura de dados que armazena os status do jogador.
     */
    struct Status {
        int Hp;   /**< Vida do jogador. */
        int Atk;  /**< Valor de ataque do jogador. */
        int Def;  /**< Valor de defesa do jogador. */
        int Mp;   /**< Valor de energia do jogador. */
        int Xp;   /**< Valor de experiência do jogador. */
        int Agi;  /**< Valor de possível esquiva do jogador. */
    };

    std::string Name; /**< Nome do jogador. */
    sf::Sprite img_Player; /**< Imagem do jogador para a interface gráfica. */
    std::vector<Skill> Skills[3]; /**< Vetor de habilidades do jogador. */
};

#endif // PLAYER_H
