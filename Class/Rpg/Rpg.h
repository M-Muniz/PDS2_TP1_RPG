#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <Skill.h>

/**
 * @brief Struct para representar os status de um jogador no jogo.
 */
struct Status {
        int Hp; /**< Vida do Player */
        int Atk; /**< Valor de ataque do Player */
        int Def; /**< Valor de defesa do Player */
        int Mp; /**< Valor de energia no Player */
        int Xp; /**< Valor de experiência do Player */
        int Agi; /**< Valor de possível esquiva do Player */
    };

/**
 * @brief Classe para representar um jogador no jogo.
 */
class Player {
public:
    /**
     * @brief Construtor da classe Player.
     */
    Player();

    /**
     * @brief Retorna o valor de ataque do Player.
     * @return Valor de ataque.
     */
    int Atk();

    /**
     * @brief Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e esquiva do Player.
     * @param Atk_enemy Valor de ataque do inimigo.
     */
    void Def(int Atk_enemy);

    /**
     * @brief Aumenta os status do Player com base na experiência recebida.
     * @param Xp Pontos de experiência a serem adicionados.
     */
    void Upar(int Xp);

    /**
     * @brief Retorna a struct de dados do Player.
     * @return Struct contendo os status do Player.
     */
    Status returnStatus();

    /**
     * @brief Retorna uma das skills do Player com base no índice.
     * @param Index Índice da habilidade desejada.
     * @return Objeto Skill representando a habilidade.
     */
    Skill userSkills(int Index);

private:
    std::string Name; /**< Nome do Player */
    Status Stats; /**< Status do Player*/
    std::vector<Skill> Skills[3]; /**< Vetor de habilidades do Player */
    sf::Sprite img_Player; /**< Imagem do Player para a interface gráfica */
};

#endif // PLAYER_H