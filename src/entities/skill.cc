/**
 * @file skill.cc
 * @brief Implementação da classe Skill.
 */

#include "../../include/skill.h"

/**
 * @brief Construtor da classe Skill.
 * @param classe Índice da classe do personagem.
 * @param index Índice da habilidade da classe.
 */
Skill::Skill(int classe, int index)
{
    if (classe == 0)
    { // Knight
        if (index == 0)
        {
            /**
             * Configurações da primeira skill do Guerreiro (Knight).
             * Aumenta o HP do jogador.
             * @param mp Custo de mana da skill (positivo para comparação).
             * @param hp Aumento de HP do jogador.
             */
            attributes_.mp = 15;
            attributes_.hp = 20;
            // img_skill_texture_.loadFromFile("resources/knight/knight_hp.png");
        }
        else if (index == 1)
        {
            /**
             * Configurações da segunda skill do Guerreiro (Knight).
             * Aumenta a agilidade do jogador e diminui a vida do inimigo.
             * @param mp Custo de mana da skill (positivo para comparação).
             * @param agi Aumento de agilidade do jogador.
             * @param hp Diminuição de HP do inimigo.
             */
            attributes_.mp = 15;
            attributes_.agi = 10;
            attributes_.hp = -15;
            // img_skill_texture_.loadFromFile("resources/knight/Run+Attack.png");
        }
        else if (index == 2)
        {
            /**
             * Configurações da terceira skill do Guerreiro (Knight).
             * Diminui consideravelmente a vida do inimigo.
             * @param mp Custo de mana da skill (positivo para comparação).
             * @param hp Diminuição de HP do inimigo mais que na segunda skill.
             */
            attributes_.mp = 15;
            attributes_.hp = -30;
            // img_skill_texture_.loadFromFile("resources/knight/Attack_2.png"); //a ideia é que seja uma sprite do attack1 + attack2
        }
    }
    else if (classe == 1)
    { // Mage
        if (index == 0)
        {
            /**
             * Configurações da primeira skill do Mago (Mage).
             * Aumenta a defesa do jogador.
             * @param mp Custo de mana da skill (positivo para comparação).
             * @param def Aumento de defesa do jogador.
             */
            attributes_.mp = 15;
            attributes_.def = 10;
            // img_skill_texture_.loadFromFile("resources/mage/Attack_1.png");
        }
        else if (index == 1)
        {
            /**
             * Configurações da segunda skill do Mago (Mage).
             * Diminui a vida do inimigo.
             * @param mp Custo de mana da skill (positivo para comparação).
             * @param hp Diminuição de HP do inimigo.
             */
            attributes_.mp = 15; 
            attributes_.hp = -15;
            // img_skill_texture_.loadFromFile("resources/mage/Attack_2.png"); //é pra ser com a Charge 1
        }
        else if (index == 2)
        {
            /**
             * Configurações da terceira skill do Mago (Mage).
             * Diminui a vida do inimigo mais que na segunda skill.
             * @param mp Custo de mana da skill (positivo para comparação).
             * @param hp Diminuição de HP do inimigo.
             */
            attributes_.mp = 15;
            attributes_.hp = -20;
            // img_skill_texture_.loadFromFile("resources/mage/Attack_2.png"); // é pra ser com a Charge 2
        }
    }
    else if (classe == 2)
    { // Samurai
        if (index == 0)
        {
            /**
             * Configurações da primeira skill do Samurai.
             * Aumenta o MP do jogador.
             * @param mp Aumento de MP do jogador.
             */
            attributes_.mp = 15;
            // img_skill_texture_.loadFromFile("resources/samurai/samurai_mana.png");
        }
        else if (index == 1)
        {
            /**
             * Configurações da segunda skill do Samurai.
             * Diminui a vida do inimigo.
             * @param mp Custo de mana da skill (positivo para comparação).
             * @param hp Diminuição de HP do inimigo.
             */
            attributes_.mp = 15; 
            attributes_.hp = -20;
            // img_skill_texture_.loadFromFile("resources/samurai/Attack_1.png");
        }
        else if (index == 2)
        {
            /**
             * Configurações da terceira skill do Samurai.
             * Diminui a vida e a defesa do inimigo.
             * @param mp Custo de mana da skill (positivo para comparação).
             * @param hp Diminuição de HP do inimigo.
             * @param def Diminuição de defesa do inimigo.
             */
            attributes_.mp = 15;
            attributes_.hp = -5;
            attributes_.def = -10;
            // img_skill_texture_.loadFromFile("resources/samurai/Attack_2.png"); //a ideia é que seja attack 2 + attack 3
        }
    }
    else if (classe == 4)
    { // Boss
        if (index == 0)
        {
            /**
             * Configurações da skill do Boss.
             * Diminui a vida do jogador consideravelmente.
             * @param hp Diminuição de HP do jogador.
             */
            attributes_.hp = -50;
            // img_skill_texture_.loadFromFile("resources/boss/skill_boss.png"); //nao temos ainda
        }
    }

    // img_skill_.setTexture(img_skill_texture_);
}

Skill::Skill() {}