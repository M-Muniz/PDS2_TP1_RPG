#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

/**
* @brief Classe que representa um Menu no jogo.
*/
class Menu {
  private:
    int pos_; /**<  Armazena a posição de seleção do Menu.*/
    bool pressed_; /**<  Armazena se uma tecla está pressionada.*/
    bool theselect_; /**<  Armazena se houve uma seleção de uma opção do Menu.*/

    RenderWindow *window_; /**<  Janela do Menu.*/
    Font *font_; /**<  Armazena a fonte a ser usada no Menu.*/
    Texture *image_; /**<  Armazena a imagem para importar para o background.*/
    Sprite *bg_; /**<   Background do Menu para a interface gráfica.*/
    
    string player_name_; /**< String para armazenar o nome do Player (limitada a 10 caracteres em Menu::ReceiveName()). */

    vector<string> options_; /**< Vetor de opções do Menu.*/
    vector<Vector2f> coords_; /**< Vetor de posições das opções do Menu.*/
    vector<Text> texts_; /**< Vetor de textos para as opções do Menu.*/
    vector<size_t> sizes_; /**< Tamanho das fontes para as opções do Menu.*/

  protected:
    /**
    * @brief Função para definir os valores para cada um dos objetos da Classe.
    */
    void SetValues();

    /**
    * @brief Função para armazenar os eventos que ocorrem no Menu (interações como mouse e teclado).
    */
    void LoopEvents();

    /**
    * @brief Função para desenhar as coisas na janela da interface gráfica.
    */
    void DrawAll();

    /**
    * @brief Função para receber o nome do Player através da interface gráfica.
    */
    void ReceiveName();

  public:
    /**
    * @brief Construtor.
    */
    Menu();

    /**
    * @brief Retorna o nome do player.
    */
    string ReturnName();

    /**
    * @brief Retorna a classe do player.
    */
    int ReturnClass();

    /**
    * @brief Destrutor.
    */
    ~Menu();

    /**
    * @brief Coloca o Menu para funcionar.
    */
    void RunMenu();
};

#endif