#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "skill.h"

/**
 * @brief Struct para representar os status de um jogador no jogo.
 */
struct Status {
    int hp; /**< Vida do Player */
    int atk; /**< Valor de ataque do Player */
    int def; /**< Valor de defesa do Player */
    int mp; /**< Valor de energia no Player */
    int xp; /**< Valor de experiência do Player */
    int agi; /**< Valor de possível esquiva do Player */
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
    Status ReturnStatus();

    /**
     * @brief Retorna uma das skills do Player com base no índice.
     * @param Index Índice da habilidade desejada.
     * @return Objeto Skill representando a habilidade.
     */
    Skill UserSkills(int Index);

private:
    std::string name; /**< Nome do Player */
    Status ntats_; /**< Status do Player*/
    std::vector<Skill> skills[3]; /**< Vetor de habilidades do Player */
    sf::Sprite img_player; /**< Imagem do Player para a interface gráfica */
};

#endif 
