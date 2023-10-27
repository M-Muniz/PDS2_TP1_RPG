#ifndef RPG_H_
#define RPG_H_

#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

/**
 * @brief Classe principal para o jogo de RPG.
 */
class Rpg {
public:
    shared_ptr<sf::RenderWindow> window;
    Texture bg;
    shared_ptr<sf::Sprite> background;

public:
    /**
     * @brief Construtor da classe Rpg.
     */
    Rpg();
    
    /**
     * @brief Inicia o jogo de RPG.
     */
    void Run();

    private:
    /**
     * @brief Move os inimigos no jogo.
     */
    void MoveEnemys();

    /**
     * @brief Anima os objetos do jogo.
     */
    void SetAnime();

    /**
     * @brief Gerencia eventos do jogo que acontecem na interface gráfica.
     */
    void Events();

    /**
     * @brief Anima a janela do jogo.
     */
    void Draw();


};
#endif