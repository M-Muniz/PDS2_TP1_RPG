#ifndef BOSS_H_
#define BOSS_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "skill.h"

using namespace std;
using namespace sf;

struct Status {
    int hp;   /**< Vida do chefe (boss). */
    int atk;  /**< Valor de ataque do chefe (boss). */
    int def;  /**< Valor de defesa do chefe (boss). */
    int xp;   /**< Valor de experiência passado ao jogador. */
    int agi;  /**< Valor de possível esquiva do chefe (boss). */
};
/**
 * @brief Classe que representa um chefe (boss) no jogo.
 */
class Boss {
public:
    /**
     * @brief Construtor da classe Boss.
     */
    Boss();

    /**
     * @brief Retorna o valor de ataque do chefe (boss).
     * @return O valor de ataque do chefe (boss).
     */
    int Atk();

    /**
     * @brief Recebe o valor de ataque do jogador e subtrai da vida com base na defesa e esquiva do chefe (boss).
     * @param Atk_player O valor de ataque do jogador.
     */
    void Def(int Atk_player);

    /**
     * @brief Retorna a struct de dados do chefe (boss).
     * @return A struct de dados do chefe (boss).
     */
    Status ReturnStatus();

    /**
     * @brief Retorna uma das habilidades do chefe (boss) com base no índice.
     * @param Index O índice da habilidade desejada.
     * @return A habilidade do chefe (boss) correspondente ao índice.
     */
    Skill BossSkills(int Index);

private:
    /**
     * @brief Estrutura de dados que armazena os status do chefe (boss).
     */
    Status stats_;
    string name_; /**< Nome do chefe (boss). */
    Texture img_boss_texture_; /**< Textura para importar para o Sprite*/
    Sprite img_boss_; /**< Imagem do chefe (boss) para a interface gráfica. */
    Skill skills_; /**< Habilidades do chefe (boss). */
};

#endif
