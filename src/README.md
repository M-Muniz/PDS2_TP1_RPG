Tema trabalho PDS2

Integrantes: 

José Lucas Lacerda Campos - 2023039295

Isabella de Paula Amaral - 2023039023

Luiz Fernando Verteiro Evaristo - 2023038760

Matheus Muniz Soares - 2023038892

Jogo de RPG em turnos:

Objetivo: criar um jogo de turnos em uma dungeon pré definida, na qual o usuário poderá escolher suas ações e moldar seu personagem enquanto enfrenta inimigos cada vez mais fortes. O Personagem jogável e os inimigos estarão representados através de Class na qual suas ações seriam definidas atraves de funções.

Escolhemos utilizar o manual de estillo da Google.

User Story: 

    RPG em turnos C++

    Como usuario desejo jogar um jogo simples de combate em turnos.
    --- criterios de aceitaçao ---
    . Desejo ser capaz de ter uma pequena variedade de açoes durante meus turnos, como atacar e usar skills.
    . Ser capaz de alterar entre classes ou habilidades entre partidas, para que cada jogo seja unico.
    . Quero que o jogo possua uma interface grafica para q eu seja capaz de enxergar os combates.
    . Quero interagir atraves da interface grafica com uso de botoes ou comandos.

CRC's:

    Class: 
        Player;
    Responsabilitys:
        Player(); // Construtor
        Atk(); // Retorna o valor de ataque do Player
        Def(int Atk_enemy); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e esquiva do Player 
        Upar(int Xp); // Aumenta os status do Palyer com base na experiência recebida
        returnStatus(); // Retorna a struct de dados do Player
        userSkills(int Index); // Retorna uma das skills do Player com base no indexador
    Colaborators:
        vector<Skill> Skills[3]; // Vetor de habilidades do Player
        Struct{
            int Hp; // Vida do Player 
            int Atk; // Valor de ataque do Player
            int Dfs; // Valor de defesa do Player
            int Mp; // Valor de energia no Player
            int Xp; // Valor de experiência do Player
            int Agi; // Valor de possível esquiva do Player
        } 
        String Nome; // Nome do Player
        Sprite Jogador; // Imagem doo Player para a interface gráfica

    Class: 
        Enemy;
    Responsabilitys:
        Enemy(); // Construtor
        Atk(); // Retorna o valor de ataque do Enemy
        Def(int Atk_enemy); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e esquiva do Enemy
        returnStatus(); // Retorna a struct de dados do Enemy
    Colaborators:

    Class: 
        Rpg;
    Responsabilitys:
    Colaborators:

    Class: 
        Skill;
    Responsabilitys:
    Colaborators:

    Class: 
        Boss;
    Responsabilitys:
        Boss(); // Construtor
        Atk(); // Retorna o valor de ataque do Player
        Def(int Atk_enemy); // Recebe o valor de ataque do atacante e subtrai da vida com base na defesa e esquiva do Boss 
        returnStatus(); // Retorna a struct de dados do Boss
        bossSkills(); // Retorna uma das skills do Boss com base no indexador
    Colaborators:
        Skill Skills; //habilidade do Boss
        Struct{
            int Hp; // Vida do Bo 
            int Atk; // Valor de ataque do Boss
            int Dfs; // Valor de defesa do Boss
            int Mp; // Valor de energia no Player
            int Xp; // Valor de experiência do Player
            int Agi; // Valor de possível esquiva do Player

    Class: 
        Item;
    Responsabilitys:
    Colaborators:

