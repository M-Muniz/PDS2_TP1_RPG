#include <time.h> //necessário p/ função time()
#include "../include/boss.h"
#include "../include/enemy.h"
#include "../include/item.h"
#include "../include/menu.h"
#include "../include/player.h"
#include "../include/rpg.h"
#include "../include/skill.h"

/**
 * @brief Função principal que inicia o jogo.
 *
 * A função main() é responsável por inicializar o jogo. Ela inicializa o gerador de números aleatórios,
 * cria um menu, executa o menu para que o jogador escolha suas opções, cria um objeto jogador com base nas
 * seleções do menu, cria o jogo e executa o jogo principal. Por fim, limpa a memória alocada e encerra o jogo.
 *
 * @return 0 ao término do jogo
 */
int main()
{
  srand(time(NULL)); // Inicialização do gerador de números aleatórios com base no tempo
  try{
  // Criação e execução do menu para interações do jogador
  Menu *menu = new Menu();

  menu->RunMenu();

  // Criação do jogador com base nas escolhas feitas no menu
  Player jogador(menu->ReturnName(), menu->ReturnClass());

  // Criação e execução do jogo com base no jogador criado
  Rpg *jogo = new Rpg(jogador);

  delete menu; // Liberação de memória do menu após sua utilização

  jogo->Run(); // Execução do jogo principal

  delete jogo; // Liberação de memória do jogo após sua execução

  // Prevenção de vazamento de memória, atribuição de nullptr às variáveis
  menu = nullptr;
  jogo = nullptr;
  }catch(ErroLoadFromFile){
    cout << "Erro ao carregar alguma imagem ou fonte" << endl;
    cout << "Confira os arquivos da pasta resources" << endl;
  }
  return 0;
}