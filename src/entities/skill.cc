#include "../../include/skill.h"

Skill::Skill(int classe, int index) {
    if (classe == 0) {  // Knight
        if (index == 0) {
            attributes_.mp = 15; // Custo de mana da skill (tem que ser positivo pra comparação)
            attributes_.hp = 20;  // Aumenta HP do jogador
            // img_skill_texture_.loadFromFile("resources/knight/knight_hp.png");
        } else if (index == 1) {
            attributes_.mp = 15; // Custo de mana da skill (tem que ser positivo pra comparação)
            attributes_.agi = 10;  // Aumenta a agilidade do jogador
            attributes_.hp = -15;  // Diminui a vida do inimigo 
            // img_skill_texture_.loadFromFile("resources/knight/Run+Attack.png");
        } else if (index == 2) {
            attributes_.mp = 15; // Custo de mana da skill (tem que ser positivo pra comparação)
            attributes_.hp = -30;  // Diminui mais que na segunda skill
            // img_skill_texture_.loadFromFile("resources/knight/Attack_2.png"); //a ideia é que seja uma sprite do attack1 + attack2
        }
    } else if (classe == 1) {  // Mage
        if (index == 0) {
            attributes_.mp = 15; // Custo de mana da skill (tem que ser positivo pra comparação)
            attributes_.def = 10;  // Aumenta a defesa do jogador
            // img_skill_texture_.loadFromFile("resources/mage/Attack_1.png");
        } else if (index == 1) {
            attributes_.mp = 15; // Custo de mana da skill (tem que ser positivo pra comparação)
            attributes_.hp = -15;  // Diminui a vida do inimigo
            // img_skill_texture_.loadFromFile("resources/mage/Attack_2.png"); //é pra ser com a Charge 1
        } else if (index == 2) {
            attributes_.mp = 15; // Custo de mana da skill (tem que ser positivo pra comparação)
            attributes_.hp = -20;  // Diminui a vida do inimigo mais que na segunda skill
            // img_skill_texture_.loadFromFile("resources/mage/Attack_2.png"); // é pra ser com a Charge 2
        }
    } else if (classe == 2) {  // Samurai
        if (index == 0) {
            attributes_.mp = 15;  // Aumenta o MP do jogador
            // img_skill_texture_.loadFromFile("resources/samurai/samurai_mana.png");
        } else if (index == 1) {
            attributes_.mp = 15; // Custo de mana da skill (tem que ser positivo pra comparação)
            attributes_.hp = -20;  // Diminui a vida do inimigo
            // img_skill_texture_.loadFromFile("resources/samurai/Attack_1.png");
        } else if (index == 2) {
            attributes_.mp = 15; // Custo de mana da skill (tem que ser positivo pra comparação)
            attributes_.hp = -5;
            attributes_.def = -10;  // Diminui a defesa do inimigo
            // img_skill_texture_.loadFromFile("resources/samurai/Attack_2.png"); //a ideia é que seja attack 2 + attack 3
        }
    } else if (classe == 4) { // Boss
        if (index == 0){
            attributes_.hp = -50;  // Diminui a vida do jogador consideravelmente (um tanto bao)
            // img_skill_texture_.loadFromFile("resources/boss/skill_boss.png"); //nao temos ainda
        }
    }

    // img_skill_.setTexture(img_skill_texture_);
}

Skill::Skill() {}