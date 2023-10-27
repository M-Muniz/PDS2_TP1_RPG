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
    void Sum(Player& usr);

private:
    Attributes attributes_; /**< Estrutura de dados que armazena os atributos do item. */
    Texture img_item_texture_; /**< Textura para importar para o Sprite. */
    Sprite img_item_; /**< Imagem do item para a interface gráfica. */
};

#endif
