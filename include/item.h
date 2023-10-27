#ifndef ITEM_H_
#define ITEM_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "skill.h"
#include "player.h"

using namespace std;
using namespace sf;

/**
* @brief Estrutura de dados que armazena os atributos deste item.
*/
struct Attributes {
        int hp;   /**< Valor de vida a ser somado. */
        int atk;  /**< Valor de ataque a ser somado. */
        int def;  /**< Valor de defesa a ser somado. */
        int mp;   /**< Valor de energia a ser somado. */
        int xp;   /**< Valor de experiência a ser somado. */
        int agi;  /**< Valor de possível esquiva a ser somado. */
    };

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
    Attributes attributes_; /**< Estrutura de dados que armazena os atributos do item*/

    Sprite img_item_; /**< Imagem do item para a interface gráfica. */
};

#endif
