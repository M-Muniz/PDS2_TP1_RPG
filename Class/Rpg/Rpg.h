#ifndef RPG_H
#define RPG_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <memory>

/**
 * @brief Classe principal para o jogo de RPG.
 */
class Rpg {
public:
    std::shared_ptr<sf::RenderWindow> Window;
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
    void moveEnemys();

    /**
     * @brief Anima os objetos do jogo.
     */
    void Setanime();

    /**
     * @brief Gerencia eventos do jogo que acontecem na interface gráfica.
     */
    void events();

    /**
     * @brief Anima a janela do jogo.
     */
    void draw();


};
#endif // RPG_H