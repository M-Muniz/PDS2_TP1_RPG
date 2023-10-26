#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <Skill.h>

/**
 * @brief Classe que representa um item no jogo.
 */
class Item {
public:
    /**
     * @brief Construtor da classe Item.
     */
    Item();

    /**
     * @brief Soma os atributos deste item ao jogador.
     * @param Usr O jogador ao qual os atributos deste item serão somados.
     */
    void Sum(Player& Usr);

private:
    /**
     * @brief Estrutura de dados que armazena os atributos deste item.
     */
    struct Attributes {
        int Hp;   /**< Valor de vida a ser somado. */
        int Atk;  /**< Valor de ataque a ser somado. */
        int Def;  /**< Valor de defesa a ser somado. */
        int Mp;   /**< Valor de energia a ser somado. */
        int Xp;   /**< Valor de experiência a ser somado. */
        int Agi;  /**< Valor de possível esquiva a ser somado. */
    };

    sf::Sprite img_Item; /**< Imagem do item para a interface gráfica. */
};

#endif // ITEM_H
