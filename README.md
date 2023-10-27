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

OBS: É possível utilizar a biblioteca em Windows também, porém o uso é bem menos complexo ao se utilizar 
Linux/WSL, além de ser possível utilizar ferramentas como o Make, que é essencial nesse tipo de aplicação tendo 
em vista a quantidade de dependências neecssárias. Dessa forma, gostaria de salientar que o arquivo Makefile 
dessa aplicação ainda não foi concluído e, atualmente trabalha com a inclusão da biblioteca levando em 
consideração que esta se encontra instalada no diretório padrão de instalação do Linux (-L/usr/lib/x86_64-
linux-gnu/). É possível que haja alguma convergência em outras máquinas e pretendemos resolver essa questão o 
mais rápido possível, para tornar a aplicação mais abrangente.

# ----------------------------------------------------------------

# User Story: 

##    RPG em turnos C++

Como usuario desejo jogar um jogo simples de RPG com o combate em turnos.

### Critérios de aceitação   

. Desejo ser capaz de ter uma pequena variedade de açoes durante meus turnos, como atacar e usar skills.
. Ser capaz de alterar entre classes ou habilidades entre partidas, e que haja uma , para que cada jogo 
seja unico.
. Quero que o jogo possua uma interface grafica para q eu seja capaz de enxergar os combates.
. Quero interagir atraves da interface grafica com uso de botoes ou comandos.


# ----------------------------------------------------------------

# CRC's:

##    Class: 

Player;

##    Responsabilitys:

Player(); // Construtor.
Atk(); // Retorna o valor de ataque do Player.
Def(int Atk_enemy); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e 
esquiva do Player. 
Upar(int Xp); // Aumenta os status do Palyer com base na experiência recebida.
ReturnStatus(); // Retorna a struct de dados do Player.
UserSkills(int Index); // Retorna uma das skills do Player com base no indexador.

##    Colaborators:

vector<Skill> skills_[3]; // Vetor de habilidades do Player.
Status stats_; // Estrutura que armazena os status do Player.
String name_; // Nome do Player.
Sprite img_player_; // Imagem do Player para a interface gráfica.

# ----------------------------------------------------------------

##    Class:

Enemy;

##    Responsabilitys:

Enemy(); // Construtor.
Atk(); // Retorna o valor de ataque do Enemy.
Def(int Atk_enemy); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e 
esquiva do Enemy.
ReturnStatus(); // Retorna a struct de dados do Enemy.

##    Colaborators:

Status stats_; // Estrutura de dados que armazena os status do inimigo.
string name_; // Nome do inimigo.

# ----------------------------------------------------------------

##    Class: 

Rpg;

##    Responsabilitys:

MoveEnemys(); // Move os inimigos.
SetAnime(Vários)(); // Anima os objetos do jogo.     
Events(); // Eventos do jogo que acontecem na interface grafica.
Draw(); // Anima a janela. 

##    Colaborators:

Rpg(); // Construtor da classe.
Run(); // Inicia o jogo.

# ----------------------------------------------------------------

##    Class: 

Skill;

##    Responsabilitys:

skill(int classe); // Construtor da class skill baseado na Classe(RPG) selecionada. 

##    Colaborators:

int class_; // Armazena o valor da classe do Player ou do Boss.
Attributes attributes_; // Estrutura de dados com os atributos da Skill.
Sprite img_skill_; // Imagem da Skill para a interface grafica. 

# ----------------------------------------------------------------

##    Class: 

Boss;

##    Responsabilitys:

Boss(); // Construtor.
Atk(); // Retorna o valor de ataque do Boss.
Def(int Atk_player); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e 
esquiva do Boss. 
ReturnStatus(); // Retorna a estrutura de dados de status do Boss.
BossSkills(); // Retorna uma das skills do Boss com base no indexador.

##    Colaborators:

Skill skills_[]; // Vetor das habilidade do Boss;
Status stats_ // Estrutura de dados com os status do Boss.
String name_; // Nome do Boss.
Sprite img_boss_; // Imagem do Boss para a interface gráfica.

# ----------------------------------------------------------------

##    Class: 

Item;

##    Responsabilitys:

Item(); //Construtor.
Sum(Player Usr); // Soma os atributos dessa class ao player.

##    Colaborators:

Attributes attributes_; // Estrutura de dados com os atributos do item.
Sprite img_Item; // Imagem do item para a interface gráfica.
