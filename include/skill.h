#ifndef SKILL_H_
#define SKILL_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
/**
* @brief Estrutura de dados que armazena os atributos dessa Skill.
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
 * @brief Classe Skill responsável por representar as habilidades do jogador ou do chefe (Boss) no jogo de RPG.
 */
class Skill {
public:
    /**
     * @brief Construtor da classe Skill baseado na Classe (RPG) selecionada.
     * 
     * @param classe O valor da classe do jogador ou do chefe (Boss).
     */
    Skill(int classe);
    
private:
    int class_; ///< Armazena o valor da classe do jogador ou do chefe (Boss).
    Attributes attributes_; ///< Estrutura de dados com os atributos da Skill.
    sf::Sprite img_skill_; ///< Imagem da Skill para a interface gráfica.
};

#endif
