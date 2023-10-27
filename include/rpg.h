#ifndef RPG_H_
#define RPG_H_

#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


/**
 * @brief Classe principal para o jogo de RPG.
 */
class Rpg {
public:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Texture bg;
    std::shared_ptr<sf::Sprite> background;

public:
    /**
     * @brief Inicia o jogo de RPG.
     */
    void Run();
        /**
     * @brief Construtor da classe Rpg.
     */
    Rpg();
    
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