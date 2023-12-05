/**
 * @file player.cc
 * @brief Implementação da classe Player.
 */

#include "../../include/player.h"
#include "../../include/entity.h"

Player::Player() : Entity() {}

/**
 * @brief Construtor da classe Player que recebe o nome e a classe do jogador.
 * @param nome Nome do jogador.
 * @param classe Classe do jogador (0: Guerreiro, 1: Mago, 2: Samurai).
 */
Player::Player(string nome, int classe) : Entity()
{
  // Configurações iniciais do jogador com base na classe escolhida.
  if (classe == 0)
  { // Classe Guerreiro
    // Atributos base para a classe Guerreiro
    stats_.hp_max = 1;
    stats_.hp = stats_.hp_max;
    stats_.atk = 35;
    stats_.def = 30;
    stats_.agi = 100;
    stats_.mp = 100;
    img_entity_texture_.loadFromFile("resources/knight/sprite_knight_default.png");
    img_entity_.setTexture(img_entity_texture_);
  }
  else if (classe == 1)
  { // Classe Mago
    // Atributos base para a classe Mago
    stats_.hp_max = 1;
    stats_.hp = stats_.hp_max;
    stats_.atk = 55;
    stats_.def = 20;
    stats_.agi = 100;
    stats_.mp = 100;
    img_entity_texture_.loadFromFile("resources/mage/sprite_mage_default.png");
    img_entity_.setTexture(img_entity_texture_);
  }
  else if (classe == 2)
  { // Classe Samurai
    // Atributos base para a classe Samurai
    stats_.hp_max = 1;
    stats_.hp = stats_.hp_max;
    stats_.atk = 45;
    stats_.def = 25;
    stats_.agi = 100;
    stats_.mp = 100;
    img_entity_texture_.loadFromFile("resources/samurai/sprite_samurai_default.png");
    img_entity_.setTexture(img_entity_texture_);
  }
  img_entity_.setScale(5, 5);

  stats_.xp = 0;

  name_ = nome;

  classe_ = classe;

  skills_cd_.resize(3);

  for (int i = 0; i < 3; i++)
  {
    Skill aux(classe, i);
    skills_.push_back(aux);
    for (int j = 0; j < 3; j++)
    {
      skills_cd_[i].push_back(true);
    }
  }
}

/**
 * @brief Método para aumentar o nível do jogador com base na experiência acumulada.
 * @param xp Quantidade de experiência que vai ser adicionada.
 */
void Player::Upar(int xp)
{
  // Lógica para o jogador subir de nível baseado na experiência acumulada
  stats_.xp += xp;

  if (stats_.xp >= 100)
  {
    // Atributos incrementados ao subir de nível
    stats_.hp_max += 15;
    stats_.hp = stats_.hp_max;
    stats_.atk += 5;
    stats_.def += 5;
    stats_.agi += 5;
    stats_.mp += 15;
    stats_.xp -= 100;

    cout << "Você subiu de nível!" << endl;
  }

  return;
}

/**
 * @brief Método para obter uma habilidade do jogador com base no índice.
 * @param index Índice da habilidade desejada.
 * @return A habilidade correspondente ao índice.
 */
Skill Player::UserSkills(int index) { return skills_[index]; }

/**
 * @brief Método para retornar o sprite de morte com base na classe do jogador.
 * @return O caminho do sprite de morte.
 */
string Player::ReturnSpriteMorte()
{
  if (classe_ == 0)
  {
    return "resources/knight/sprite_knight_dead.png";
  }
  else if (classe_ == 1)
  {
    return "resources/mage/sprite_mage_dead.png";
  }
  return "resources/samurai/sprite_samurai_dead.png";
}

/**
 * @brief Método para retornar o sprite de ataque com base na classe do jogador.
 * @return O caminho do sprite de ataque.
 */
string Player::ReturnSpriteAtk()
{
  if (classe_ == 0)
  {
    return "resources/knight/sprite_knight_atk1.png";
  }
  else if (classe_ == 1)
  {
    return "resources/mage/sprite_mage_atk2.png";
  }
  return "resources/samurai/sprite_samurai_atk1.png";
}

/**
 * @brief Método para retornar o sprite de dano recebido com base na classe do jogador.
 * @return O caminho do sprite de dano recebido.
 */
string Player::ReturnSpriteTomou()
{
  if (classe_ == 0)
  {
    return "resources/knight/sprite_knight_hurt.png";
  }
  else if (classe_ == 1)
  {
    return "resources/mage/sprite_mage_hurt.png";
  }
  return "resources/samurai/sprite_samurai_hurt.png";
}

/**
 * @brief Método para retornar o sprite de defesa com base na classe do jogador.
 * @return O caminho do sprite de defesa.
 */
string Player::ReturnSpriteDef()
{
  if (classe_ == 0)
  {
    return "resources/knight/sprite_knight_protect.png";
  }
  else if (classe_ == 1)
  {
    return "resources/mage/sprite_mage_protect.png";
  }
  return "resources/samurai/sprite_samurai_protection.png";
}

/**
 * @brief Método para retornar o sprite de repouso com base na classe do jogador.
 * @return O caminho do sprite de repouso.
 */
string Player::ReturnSpriteIdle()
{
  if (classe_ == 0)
  {
    return "resources/knight/sprite_knight_default.png";
  }
  else if (classe_ == 1)
  {
    return "resources/mage/sprite_mage_default.png";
  }
  return "resources/samurai/sprite_samurai_default.png";
}

/**
 * @brief Método para carregar e configurar o sprite do jogador.
 * @param png Caminho do arquivo de imagem do sprite.
 */
void Player::SettaSprite(string png)
{
  img_entity_texture_.loadFromFile(png);
  img_entity_.setTexture(img_entity_texture_);
  img_entity_.setScale(5, 5);
}

/**
 * @brief Método para retornar dados específicos de animação com base no sprite fornecido.
 * @param png Caminho do arquivo de imagem do sprite.
 * @return Dados específicos de animação.
 */
DadosAnimacao Player::ReturnDadosSprite(string png)
{
  DadosAnimacao aux;
  if (classe_ == 0)
  {
    // Configuração de dados de animação para o Guerreiro
    if (png == "resources/knight/sprite_knight_atk1.png")
    {
      aux = {555, 75, 5};
      img_entity_.setPosition(260, 260);
      return aux;
    }
    else if (png == "resources/knight/sprite_knight_protect.png")
    {
      aux = {45, 61, 1};
      img_entity_.setPosition(150, 300);
      return aux;
    }
    else if (png == "resources/knight/sprite_knight_hurt.png")
    {
      aux = {106, 61, 2};
      img_entity_.setPosition(150, 300);
      return aux;
    }
    else if (png == "resources/knight/sprite_knight_dead.png")
    {
      aux = {480, 60, 6};
      img_entity_.setPosition(150, 300);
      return aux;
    }
  }
  else if (classe_ == 1)
  {
    // Configuração de dados de animação para o Mago
    if (png == "resources/mage/sprite_mage_atk2.png")
    {
      aux = {990, 74, 9};
      img_entity_.setPosition(125, 285);
      return aux;
    }
    else if (png == "resources/mage/sprite_mage_protect.png")
    {
      aux = {348, 87, 4};
      img_entity_.setPosition(125, 165);
      return aux;
    }
    else if (png == "resources/mage/sprite_mage_hurt.png")
    {
      aux = {132, 59, 2};
      img_entity_.setPosition(125, 265);
      return aux;
    }
    else if (png == "resources/mage/sprite_mage_dead.png")
    {
      aux = {340, 59, 4};
      img_entity_.setPosition(125, 285);
      return aux;
    }
  }
  else if (classe_ == 2)
  {
    // Configuração de dados de animação para o Samurai
    if (png == "resources/samurai/sprite_samurai_atk1.png")
    {
      aux = {575, 67, 5};
      img_entity_.setPosition(110, 265);
      return aux;
    }
    else if (png == "resources/samurai/sprite_samurai_protection.png")
    {
      aux = {345, 70, 5};
      img_entity_.setPosition(110, 265);
      return aux;
    }
    else if (png == "resources/samurai/sprite_samurai_hurt.png")
    {
      aux = {210, 70, 3};
      img_entity_.setPosition(110, 265);
      return aux;
    }
    else if (png == "resources/samurai/sprite_samurai_dead.png")
    {
      aux = {480, 67, 6};
      img_entity_.setPosition(110, 265);
      return aux;
    }
  }
  return DadosAnimacao{0, 0, 0};
}