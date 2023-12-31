/**
 * @file skill.h
 * @brief Contém a definição da estrutura de atributos e da classe Skill.
 */
#ifndef SKILL_H_
#define SKILL_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

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
 * @brief Classe Skill responsável por representar as habilidades do jogador ou do chefe (Boss) no jogo de RPG.
 */
class Skill {
friend class Rpg;
public:
  /**
   * @brief Construtor da classe Skill baseado na Classe (RPG) selecionada.
   * @param classe O valor da classe do jogador ou do chefe (Boss).
   * @param index O valor do indexador da skill (Para gerar skills diferentes).
   */
  Skill(int classe, int index);

  /**
   * @brief Construtor vazio da classe Skill.
   */
  Skill();
    
private:
  int class_; /**< Armazena o valor da classe do jogador ou do chefe (Boss). */
  Attributes attributes_; /**< Estrutura de dados com os atributos da Skill. */
  Texture img_skill_texture_; /**< Textura para importar para o Sprite. */
  Sprite img_skill_; /**< Imagem da Skill para a interface gráfica. */
};

#endif /* SKILL_H_ */