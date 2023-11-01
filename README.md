# Tema trabalho PDS2

# ----------------------------------------------------------------

## Integrantes: 


José Lucas Lacerda Campos - 2023039295

Isabella de Paula Amaral - 2023039023

Luiz Fernando Verteiro Evaristo - 2023038760

Matheus Muniz Soares - 2023038892


# ----------------------------------------------------------------

# Jogo de RPG em turnos:

Objetivo: criar um jogo de turnos em uma dungeon pré definida, na qual o usuário poderá escolher suas ações 
e moldar seu personagem enquanto enfrenta inimigos cada vez mais fortes. O Personagem jogável e os inimigos 
estarão representados através de Class na qual suas ações seriam definidas atraves de funções.

# ----------------------------------------------------------------

# Especificações

## Manual de estilo

Escolhemos utilizar o manual de estillo da Google.

## Bibliotecas e especificações técnicas

Optamos por utilizar a biblioteca SFML, que é uma biblioteca multimídia orientada a objetos de uso um pouco 
mais simples que algumas outras opções. A biblioteca é dividida em 5 modulos principais, a "system" usada 
para manipulaçao de vetores e temporizadores, "window" usada para abrir janelas com suportes de inputs (como 
mouse e controles), a "graphics", usada para renderizaçao de graficos, "audio" usada para gravar ou 
reproduzir audios, e a "network" que é usada para transmissao de dados. Esse projeto é baseado nos primeiros 
quatro módulos, tendo em vista que não utilizaremos o módulo "network".

#### ATENÇÃO: É importante frisar que esta implementação é baseada em linux, então possivelmente aplicaçoes em outros sistemas operacionais nao terao o resultado esperado. 

Para baixar a biblioteca, basta usar o comando "sudo apt-get install libsfml-dev", mas caso prefira instalar 
de outra forma ou acompanhar um tutorial mais completo, basta acessar o site oficial da biblioteca, disponível 
em "https://www.sfml-dev.org/index.php".

# ----------------------------------------------------------------

# User Story: 
Objetivo: criar um jogo de turnos em uma dungeon pré definida, na qual o usuário poderá escolher suas ações e moldar seu personagem enquanto enfrenta inimigos cada vez mais fortes. O Personagem jogável e os inimigos estarão representados através de Class na qual suas ações seriam definidas atraves de funções.
##    RPG em turnos C++

Como usuario desejo jogar um jogo simples de RPG com o combate em turnos.

### Critérios de aceitação   

. Desejo ser capaz de ter uma pequena variedade de açoes durante meus turnos, como atacar e usar skills.

. Ser capaz de alterar entre classes ou habilidades entre partidas, e que haja uma certa variedade de 
inimigos, como inimigos normais e um boss, para que cada jogo seja unico.

. Quero que o jogo possua uma interface grafica para que eu seja capaz de enxergar os combates.

. Quero interagir atraves da interface grafica com uso de botoes, mouse e/ou comandos.


# ----------------------------------------------------------------

# CRC's:

##    Class: 

Player;

##    Responsabilitys:

Player(string nome, int classe); // Construtor, recebe o nome do personagem
e a sua classe.

Atk(); // Retorna o valor de ataque do Player.

Def(int atk_enemy); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e 
esquiva do Player, retorna 0 se o Player desviar do ataque e 1 c.c. 

Upar(int xp); // Aumenta os status do Palyer com base na experiência recebida.

ReturnStatus(); // Retorna a struct de dados do Player.

UserSkills(int index); // Retorna uma das skills do Player com base no indexador.

##    Colaborators:

int classe_; // Classe do Player

vector<Skill> skills_; // Vetor de habilidades do Player.

Status stats_; // Estrutura que armazena os status do Player.

String name_; // Nome do Player.

Texture img_player_texture_; // Textura para importar para o Sprite

Sprite img_player_; // Imagem do Player para a interface gráfica.

vector<vector<bool>> skills_cd_; // Computa o cooldown das skills do player. 
# ----------------------------------------------------------------

##    Class:

Enemy;

##    Responsabilitys:

Enemy(); // Construtor.

Atk(); // Retorna o valor de ataque do Enemy.

Def(int Atk_player); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e 
esquiva do Enemy.

ReturnStatus(); // Retorna a struct de dados do Enemy.

##    Colaborators:

Status stats_; // Estrutura de dados que armazena os status do inimigo.

string name_; // Nome do inimigo.

Texture img_enemy_texture_; // Textura para importar para o Sprite

Sprite img_enemy_; // Imagem do Enemy para a interface gráfica.

# ----------------------------------------------------------------

##    Class: 

Rpg;

##    Responsabilitys:

Rpg(Player jogador); // Construtor da classe.

Run(); // Inicia o jogo.

shared_ptr<RenderWindow> window; // Janela.

Texture bg; // Textura para importar para o backgroud da tela.

shared_ptr<Sprite> background; // Background da tela.

vector<RectangleShape> buttons_; // Vetor para os botões clicáveis.

vector<RectangleShape> player_status_; // Barras de mana e vida do Player.

vector<vector<RectangleShape>> cd_skills_; // Mostradores para o cooldown das skills do player.

vector<Text> texts_; // Vetor para posicionar os textos na tela.

Text player_name_; // Texto para plotar o nome do Player na tela. 

vector<Vector2f> texts_coords_; // Vetor para posicionar os textos na tela.

 vector<string> texts_strings_; // Vetor para posicionar os textos na tela. 

 Player player_; // Jogador.

 vector<Enemy> enemys_; // Lista de Enemys para o jogo.

 vector<Boss> boss_; // Lista de Boss's para o jogo.

 float frame_e_,frame_p_; // Frame


##    Colaborators:

MoveEnemys(); // Move os inimigos.

SetAnimePlayer(); // Anima os objetos Player do jogo.

SetAnimeEnemy(); // Anima os objetos Enemy do jogo. 

Events(); // Eventos do jogo que acontecem na interface grafica.

Draw(); // Anima a janela.

Game(); // Seta os frames do jogo.

# ----------------------------------------------------------------

##    Class: 

Skill;

##    Responsabilitys:

skill(int classe); // Construtor da class skill baseado na Classe(RPG) selecionada. 

##    Colaborators:

int class_; // Armazena o valor da classe do Player ou do Boss.

Attributes attributes_; // Estrutura de dados com os atributos da Skill.

Texture img_skill_texture_; // Textura para importar para o Sprite.

Sprite img_skill_; // Imagem da Skill para a interface grafica. 

# ----------------------------------------------------------------

##    Class: 

Boss;

##    Responsabilitys:

Boss(); // Construtor.
Atk(); // Retorna o valor de ataque do Boss.

Def(int atk_player); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e 
esquiva do Boss. 

ReturnStatus(); // Retorna a estrutura de dados de status do Boss.

BossSkills(int index); // Retorna uma das skills do Boss com base no indexador.

##    Colaborators:

vector<Skill> skills_; // Vetor das habilidade do Boss;

Status stats_ // Estrutura de dados com os status do Boss.

String name_; // Nome do Boss.

Texture img_boss_texture_; // Textura para importar para o Sprite.

Sprite img_boss_; // Imagem do Boss para a interface gráfica.

# ----------------------------------------------------------------

##    Class: 

Item;

##    Responsabilitys:

Item(); // Construtor.

Sum(Player& usr); // Soma os atributos dessa class ao player.

##    Colaborators:

Attributes attributes_; // Estrutura de dados com os atributos do item.

Texture img_item_texture_; // Textura para importar para o Sprite.

Sprite img_Item; // Imagem do item para a interface gráfica.

# ----------------------------------------------------------------

##    Class: 

Menu;

##    Responsabilitys:

Menu(); // Construtor.

~Menu(); // Destrutor. 

void SetValues(); // Função para definir os valores para cada um dos objetos da Classe.

void LoopEvents(); // Função para armazenar os eventos que ocorrem no Menu (interações como mouse e teclado).

void ReceiveName(); // Função para receber uma string (nome do player) através da interface gráfica.

void DrawAll(); // Função para desenhar as coisas na janela da interface gráfica.

void RunMenu(); // Coloca o Menu para funcionar.

##    Colaborators:

int pos_; //  Armazena a posição de seleção do Menu.

bool pressed_; //  Armazena se uma tecla está pressionada.

bool theselect_; //  Armazena se houve uma seleção de uma opção do Menu.

RenderWindow *window_; // Janela do Menu.

Font *font_; // Armazena a fonte a ser usada no Menu.

Texture *image_; // Armazena a imagem para importar para o background.

Sprite *bg_; // Background do Menu para a interface gráfica.

string player_name_; // Armazena o nome que o usuário inserir.

vector<string> options_; // Vetor de opções do Menu.

vector<Vector2f> coords_; // Vetor de posições das opções do Menu.

vector<Text> texts_; // Vetor de textos para as opções do Menu.

vector<size_t> sizes_; // Tamanho das fontes para as opções do Menu.

# ----------------------------------------------------------------

# Como utilizar o nosso jogo

## Compilação e execução

Para compilar o nosso programa, basta rodar o comando make no terminal e, após isso,
execute o arquivo game.app.

## game.app

Após executar o game.app, um menu de seleção de classe irá abrir. 

![image](https://github.com/M-Muniz/PDS2_TP1_RPG/assets/133266092/49a62e45-08c6-41b3-be38-ce11b3ddf874)

Para navegar pelo menu basta utilizar as setas (cima e baixo), e para selecionar utilize o botão "enter". 
Após selecionar a sua classe, o menu irá se fechar e uma input irá aparecer para que você insira o nome 
do seu personagem. 

![image](https://github.com/M-Muniz/PDS2_TP1_RPG/assets/133266092/1f8ac36f-a085-427a-8969-97936fc8954f)

Inicialmente, essas informações ficam salvas nas variáveis Menu::pos_ e 
Menu::player_name_. Por enquanto, é possível verificar se as informações foram salvas corretamente
por um cout no terminal apenas para este fim.
![image](https://github.com/M-Muniz/PDS2_TP1_RPG/assets/139146076/b8fb2323-2580-4703-8d20-4dc66bab6ac9)

Depois de escolher o personagem e o nome o jogo começará, ate esse instante o jogo consiste no player 
visivel e em um inimigo invisivel. O inimigo é gerado aleatoriamente no começo de td jogo e é sempre 
substituido por outro apos sua morte.
![image](https://github.com/M-Muniz/PDS2_TP1_RPG/assets/139146076/5d2fa438-adaf-40db-ac51-6df4147d66f5)

O botao no canto inferior esquerdo da tela representa a funçao de ataque do player ,que sera impressa no
terminal cada vez que o player realizar o golpe. Depois disso é a vez do inimigo que atacara o jogador e
imprimira no terminal seu erro ou seu acerto .
Caso ele acerte a vida do player tambem é imprimida em tempo real

Ate o instante todas as verificaçoes foram feitas no terminal por que nao conseguimos linkar td com a interface grafica
