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

Upar(int xp); // Aumenta os status do Player com base na experiência recebida.

EntitySkills(int index); // Retorna uma das skills do Player com base no índice.

ReturnSpriteMorte(); // Retorna o caminho relativo da animação de morte.

ReturnSpriteAtk(); // Retorna o caminho relativo da animação de ataque.

ReturnSpriteIdle(); // Retorna o caminho relativo da animação de idle.

ReturnSpriteDef(); // Retorna o caminho relativo da animação de defesa.

ReturnSpriteTomou(); // Retorna o caminho relativo da animação de hurt.

ReturnSpriteSkill(int index); // Retorna o caminho relativo da animação da habilidade com base no índice.

ReturnDadosSprite(string png); // Retorna dados do sprite para facilitar as animações com base no caminho relativo.

SettaSprite(string Png); // Define a imagem do sprite do Player.
Atk(); // Retorna o valor de ataque do Player.

##    Colaborators:

int classe_; // Classe do Player.

vector<Skill> skills_; // Vetor de habilidades do Player.

vector<vector<bool>> skills_cd_; // Computa o cooldown das skills do player.
# ----------------------------------------------------------------

##    Class:

Enemy;

##    Responsabilidades:

Enemy(); // Construtor.

BuffaInimigo(int inimigos_mortos); // Aumenta os status do inimigo com base no número de inimigos mortos.

ReturnSpriteMorte(); // Retorna o caminho relativo da animação de morte.

ReturnSpriteAtk(); // Retorna o caminho relativo da animação de ataque.

ReturnSpriteDef(); // Retorna o caminho relativo da animação de defesa.

ReturnSpriteTomou(); // Retorna o caminho relativo da animação de hurt.

ReturnSpriteIdle(); // Retorna o caminho relativo da animação de idle.

ReturnDadosSprite(string png); // Retorna dados do sprite para facilitar as animações com base no caminho relativo.

SettaSprite(string Png); // Define a imagem do sprite do Enemy.

##    Colaboradores:

Status stats_; // Estrutura de dados que armazena os status do inimigo.

string name_; // Nome do inimigo.

Texture img_enemy_texture_; // Textura para importar para o Sprite

Sprite img_enemy_; // Imagem do Enemy para a interface gráfica.

# ----------------------------------------------------------------

##    Class: 

Rpg;

##    Responsabilidades:

Rpg(Player jogador); // Construtor da classe.

~Rpg(); // Destrutor da classe.

Run(); // Inicia o jogo.

MoveEnemys(); // Move os inimigos.

SetAnimePlayer(int largura, int altura, int frame, bool idle); // Anima os objetos Player do jogo.

SetAnimeEnemy(int largura, int altura, int frame, bool idle); // Anima os objetos Enemy do jogo.

Events(); // Eventos do jogo que acontecem na interface gráfica.

Draw(); // Anima a janela.

DrawMessages(string message); // Desenha as mensagens na janela do jogo.

DrawTexts(); // Desenha os textos na janela do jogo.

Game(int x_e, int y_e, int z_e, bool idle_e, int x_p, int y_p, int z_p, bool idle_p); // Seta os frames do jogo.

ItemDraw(); // Desenha os itens na tela.

##    Colaboradores:

shared_ptr<RenderWindow> window_; // Janela.

Texture bg; // Textura para importar para o backgroud da tela.

shared_ptr<Sprite> background; // Background da tela.

RectangleShape opponent_status_; // Barra de vida do inimigo.

vector<RectangleShape> buttons_; // Vetor para os botões clicáveis.

vector<RectangleShape> player_status_; // Barras de mana e vida do Player.

vector<vector<RectangleShape>> cd_skills_; // Mostradores para o cooldown das skills do player.

vector<Text> texts_; // Vetor para posicionar os textos na tela.

Text player_name_; // Texto para plotar o nome do Player na tela.

Font font_; // Variável para armazenar a fonte para os textos.

Player player_; // Jogador.

Entity* opponent_; // Enemy/Boss a ser enfrentado.

Item* item_drop_; // Item dropado por cada enemy/boss vencido.

Vector2i pos_mouse_; // Posição do mouse.

Vector2f mouse_coord_; // Coordenadas do mouse.

int animacao_completa_enemy_; // Armazena dados da animação do enemy.

int animacao_completa_player_; // Armazena dados da animação do player.

int inimigos_mortos; // Armazena a quantidade de inimigos mortos pelo Player.

float frame_e_, frame_p_; // Variáveis para armazenar a contagem de frames das animações.

# ----------------------------------------------------------------

##    Class: 

Skill;

##    Responsabilidades:

Skill(int classe, int index); // Construtor da classe Skill baseado na Classe (RPG) selecionada.

##    Colaboradores:

int class_; // Armazena o valor da classe do Player ou do Boss.

Attributes attributes_; // Estrutura de dados com os atributos da Skill.

Texture img_skill_texture_; // Textura para importar para o Sprite.

Sprite img_skill_; // Imagem da Skill para a interface gráfica.

# ----------------------------------------------------------------

##    Class: 

Boss;

##    Responsabilidades:

Boss(); // Construtor.

EntitySkills(int index); // Retorna a habilidade do Boss.

ReturnSpriteMorte(); // Retorna o caminho relativo da animação de morte.

ReturnSpriteAtk(); // Retorna o caminho relativo da animação de ataque.

ReturnSpriteIdle(); // Retorna o caminho relativo da animação de idle.

ReturnSpriteDef(); // Retorna o caminho relativo da animação de defesa.

ReturnSpriteTomou(); // Retorna o caminho relativo da animação de hurt.

ReturnSpriteSkill(); // Retorna o caminho relativo da animação de skill.

##    Colaboradores:

vector<Skill> skills_; // Vetor de habilidades do chefe (boss).

## Herança:

Entity; // Classe base para Boss.

## Atributos Herdados:

Status stats_; // Estrutura de dados com os status do Boss.

String name_; // Nome do Boss.

Texture img_entity_texture_; // Textura para importar para o Sprite.

Sprite img_entity_; // Imagem do Boss para a interface gráfica.

# ----------------------------------------------------------------

##    Class: 

Item;

##    Responsabilidades:

Item(int tipo_item); // Construtor da classe Item.

Sum(Player& usr); // Soma os atributos deste item ao jogador.

##    Colaboradores:

Attributes attributes_; // Estrutura de dados que armazena os atributos do item.

Texture img_item_texture_; // Textura para importar para o Sprite.

Sprite img_item_; // Imagem do item para a interface gráfica.

# ----------------------------------------------------------------

##    Class: 

Menu;

##    Responsabilidades:

Menu(); // Construtor.

~Menu(); // Destrutor. 

SetValues(); // Função para definir os valores para cada um dos objetos da Classe.

LoopEvents(); // Função para armazenar os eventos que ocorrem no Menu (interações como mouse e teclado).

ReceiveName(); // Função para receber uma string (nome do player) através da interface gráfica.

DrawAll(); // Função para desenhar as coisas na janela da interface gráfica.

RunMenu(); // Coloca o Menu para funcionar.

ReturnName(); // Retorna o nome do player.

ReturnClass(); // Retorna a classe do player.

##    Colaboradores:

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
execute o arquivo game.app (digite "./game.app" no terminal).

## game.app

Após executar o game.app, um menu de seleção de classe irá abrir. 

![image](https://github.com/M-Muniz/PDS2_TP1_RPG/assets/133266092/49a62e45-08c6-41b3-be38-ce11b3ddf874)

Para navegar pelo menu basta utilizar as setas (cima e baixo), e para selecionar utilize o botão "enter". 
Após selecionar a sua classe, o menu irá se fechar e uma input irá aparecer para que você insira o nome 
do seu personagem. 

![image](https://github.com/M-Muniz/PDS2_TP1_RPG/assets/133266092/1f8ac36f-a085-427a-8969-97936fc8954f)

Inicialmente, essas informações ficam salvas nas variáveis Menu::pos_ e Menu::player_name_. Por 
enquanto, é possível verificar se as informações foram salvas corretamente por um cout no terminal 
apenas para este fim.
![image](https://github.com/M-Muniz/PDS2_TP1_RPG/assets/139146076/b8fb2323-2580-4703-8d20-4dc66bab6ac9)

Depois de escolher o personagem e o nome o jogo começará. Até esse instante o jogo consiste no player 
visivel (a imagem e a animação variam de acordo com a classe selecionada) e em um inimigo invisivel 
(pois ainda não conseguimos realiazar a animação dele). O inimigo é gerado aleatoriamente no começo de 
todo jogo e é sempre substituido por outro apos sua morte, também gerado aleatoriamente (como ainda não 
é possível realizar uma distinção visual, o tipo de inimigo é exposto no terminal, assim como as demais 
informações).
![image](https://github.com/M-Muniz/PDS2_TP1_RPG/assets/139146076/5d2fa438-adaf-40db-ac51-6df4147d66f5)

O botao no canto inferior esquerdo da tela representa a funçao de ataque do player, que sera impressa no
terminal cada vez que o player realizar o golpe (por enquanto, todas as interações fornecem uma resposta
no terminal, mas iremos implementar tudo na interface gráfica). Depois disso é a vez do inimigo que 
atacara o jogador e imprimira no terminal seu erro ou seu acerto. Caso ele acerte, a vida do player tambem 
é impressa em tempo real no terminal e a barra de vida na interface gráfica se altera proporcionalmente 
(ainda iremos implementar uma barra de vida para o inimigo, assim como o player). Futuramente, o mesmo 
ocorrerá com a mana do player ao gastar uma skill, essas que por sua vez, além de um custo de mana, terão 
um cooldown baseado em turnos, sendo representado pelas marcações verdes abaixo do botão de cada skill. 

### Final do jogo

Caso a vida do player seja menor ou igual a 0, o loop de turnos se encerra, mas ainda não implementamos uma 
tela de game over ou de pontuação, por isso, ao final do jogo, para encerra-lo, basta fechar a janela.



