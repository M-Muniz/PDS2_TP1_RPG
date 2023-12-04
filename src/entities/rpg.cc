#include "../../include/rpg.h"

Rpg::Rpg(Player jogador){
  player_ = jogador;
  mouse_coord_={0,0};
  pos_mouse_={0,0};
  window_ = std::make_shared<RenderWindow>(VideoMode(1200, 928), "Rpg", Style::Titlebar | Style::Close);
  window_->setPosition(Vector2i(0, 0));
  window_->setFramerateLimit(100);
  
  opponent_ = new Enemy();

  cout << "Nome do inimigo gerado aleatoriamente: " << opponent_->name_<<endl;
  frame_e_ = 0;
  frame_p_ = 0;

  bg.loadFromFile("resources/bgs/bg_temp.png");
  background = make_shared<Sprite>();
  background->setTexture(bg);
  background->setScale(2.35,2.35);

  buttons_.resize(4);
  buttons_[0].setSize(Vector2f(141, 141));
  buttons_[0].setPosition(Vector2f(122, 692));
  buttons_[0].setFillColor(Color::Transparent);
  buttons_[0].setOutlineColor(Color::Red);
  buttons_[0].setOutlineThickness(0);

  buttons_[1].setSize(Vector2f(65, 65));
  buttons_[1].setPosition(Vector2f(915, 680));
  buttons_[1].setFillColor(Color::Transparent);
  buttons_[1].setOutlineColor(Color::Red);
  buttons_[1].setOutlineThickness(0);

  buttons_[2].setSize(Vector2f(65, 65));
  buttons_[2].setPosition(Vector2f(1037, 680));
  buttons_[2].setFillColor(Color::Transparent);
  buttons_[2].setOutlineColor(Color::Red);
  buttons_[2].setOutlineThickness(0);

  buttons_[3].setSize(Vector2f(65, 65));
  buttons_[3].setPosition(Vector2f(976, 767));
  buttons_[3].setFillColor(Color::Transparent);
  buttons_[3].setOutlineColor(Color::Red);
  buttons_[3].setOutlineThickness(0);

  cd_skills_.resize(3);

  for(size_t i{}; i < cd_skills_.size(); i++){
    cd_skills_[i].resize(3);
  }

  for(size_t i{}; i < cd_skills_.size(); i++){
    for(size_t j{}; j < cd_skills_[i].size(); j++){
      cd_skills_[i][j].setSize(Vector2f(7,7));
      cd_skills_[i][j].setFillColor(Color::Green);
      cd_skills_[i][j].setOutlineThickness(0);
    }
  }

  cd_skills_[0][0].setPosition(Vector2f(931.5,750));
  cd_skills_[0][1].setPosition(Vector2f(945.5,750));
  cd_skills_[0][2].setPosition(Vector2f(959.5,750));

  cd_skills_[1][0].setPosition(Vector2f(1053.5,750));
  cd_skills_[1][1].setPosition(Vector2f(1067.5,750));
  cd_skills_[1][2].setPosition(Vector2f(1081.5,750));

  cd_skills_[2][0].setPosition(Vector2f(992.5,837));
  cd_skills_[2][1].setPosition(Vector2f(1006.5,837));
  cd_skills_[2][2].setPosition(Vector2f(1020.5,837));

  player_status_.resize(2);
  player_status_[0].setFillColor(Color::Green);
  player_status_[0].setOutlineThickness(0);
  player_status_[0].setSize(Vector2f(461, 21));
  player_status_[0].setPosition(Vector2f(369, 738));

  player_status_[1].setFillColor(Color::Blue);
  player_status_[1].setOutlineThickness(0);
  player_status_[1].setSize(Vector2f(409, 9.4));
  player_status_[1].setPosition(Vector2f(395, 766));

  opponent_status_.setSize(Vector2f(461,21));
  opponent_status_.setFillColor(Color::Red);
  opponent_status_.setPosition(Vector2f(369, 18));

  font_.loadFromFile("fonts/super_legend_boy.ttf");
}

void Rpg::Game(int x_e,int y_e, int z_e,bool idle_e,int x_p,int y_p,int z_p,bool idle_p){
  frame_p_ += 0.5;
  frame_e_ += 0.5;
  SetAnimePlayer(x_p,y_p,z_p,idle_p);
  SetAnimeEnemy(x_e,y_e,z_e,idle_e);
}

void Rpg::SetAnimeEnemy(int largura,int altura,int frame,bool idle){
  if(idle==false){
    largura/=frame;
  }
  if(opponent_->name_ =="Sword Skeleton"){
    if (idle == true){
      frame = 7;
      largura = 67;
      altura = 59;
      opponent_->img_entity_.setPosition(1050,320);
    }
    opponent_->img_entity_.setTextureRect(IntRect(largura*(int)frame_e_,0,largura,altura));
    if(frame_e_ > frame){ 
      frame_e_ -= frame;
      animaçao_completa_enemy_ = 1;                     
    }
  }else if(opponent_->name_ =="Small Werewolf"||opponent_->name_ =="Big Werewolf"){
    if (idle == true){
      frame = 8;
      largura = 80;
      altura = 59;
      if(opponent_->name_ =="Small Werewolf"){
        opponent_->img_entity_.setPosition(1050,450);
      }
      if(opponent_->name_ =="Big Werewolf"){
      opponent_->img_entity_.setPosition(1200,270);
      }
    }
    opponent_->img_entity_.setTextureRect(IntRect(largura*(int)frame_e_,0,largura,altura));
    if(frame_e_ > frame){
      frame_e_ -= frame;
      animaçao_completa_enemy_ = 1; 
    }
  }else if(opponent_->name_ =="Spear Skeleton"){
    if (idle == true){
      altura = 84;
      altura = 67;
      frame = 7;
    }
    opponent_->img_entity_.setTextureRect(IntRect(largura*(int)frame_e_,0,largura,altura));
    if(frame_e_ > frame){
      frame_e_ -= frame;
      animaçao_completa_enemy_ = 1; 
    }
  }else if(opponent_->name_ =="Is'Abelu"){
    if (idle == true){
      largura = 110;
      altura = 111;
      frame = 8;
      opponent_->img_entity_.setPosition(1300,0);
    }
    opponent_->img_entity_.setTextureRect(IntRect(largura*(int)frame_e_,0,largura,altura));
    if(frame_e_ > frame){
      frame_e_ -= frame;
      animaçao_completa_enemy_ = 1; 
    }
  }
 }

void Rpg::ItemDraw(){
  item_drop_ = new Item(rand() % 6);
  item_drop_->Sum(player_); //soma os status do item no player
  item_drop_->img_item_.setPosition(600,490);

  opponent_->SettaSprite(opponent_->ReturnSpriteMorte());
  DadosAnimacao aux = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteMorte());

  frame_e_=0;
  animaçao_completa_enemy_=0;

  while(!animaçao_completa_enemy_){
    Game(aux.largura,aux.altura,aux.frames,false,0,0,0,true);
    Draw();

    FloatRect rect = item_drop_->img_item_.getLocalBounds();
    item_drop_->img_item_.setPosition((window_->getSize().x - rect.width) / 2,490);

    window_->draw(item_drop_->img_item_);
    window_->display();
  }
  delete item_drop_; 
}
void Rpg::SetAnimePlayer(int largura,int altura,int frame,bool idle){
  if(idle == false){
    largura/=frame;
  }
  if(player_.classe_ == 0){
    if(idle == true){
      largura=67;
      altura=64;
      frame=4;
      player_.img_entity_.setPosition(150,300);
    }
    player_.img_entity_.setTextureRect(IntRect(largura*(int)frame_p_,0,largura,altura));
    if (frame_p_ > frame){
      frame_p_ -= frame;
      animaçao_completa_player_=1;
    }

  }else if(player_.classe_ == 1){    
    if(idle == true){
      largura=67;
      altura=67;
      frame=8;
      player_.img_entity_.setPosition(125,285);
    }
    player_.img_entity_.setTextureRect(IntRect(largura*(int)frame_p_,0,largura,altura));    
    if(frame_p_ > frame){
      frame_p_ -= frame;
      animaçao_completa_player_=1;
    }

    player_.img_entity_.setTextureRect(IntRect(largura*(int)frame_p_,0,largura,altura));
  }else if(player_.classe_ == 2){
    if(idle == true){
      largura=67;
      altura=70;
      frame=6;
      player_.img_entity_.setPosition(110,265);
    }
    player_.img_entity_.setTextureRect(IntRect(largura*(int)frame_p_,0,largura,altura));
    if(frame_p_ > frame){
      frame_p_ -= frame;
      animaçao_completa_player_=1;
    }
  }
  
}

int Rpg::Events(){
  Event event;
  pos_mouse_ = Mouse::getPosition(*window_);
  mouse_coord_ = window_->mapPixelToCoords(pos_mouse_);
  pos_mouse_ = Mouse::getPosition(*window_);
  mouse_coord_ = window_->mapPixelToCoords(pos_mouse_);

  while (window_->pollEvent(event) && window_->isOpen()){
    if (event.type == Event::Closed){
      window_->close();
      window_->close();
    }
    if(Mouse::isButtonPressed(Mouse::Left)){  
      if(buttons_[0].getGlobalBounds().contains(mouse_coord_)){ // Ataque básico
        return 1; 
      }else if(buttons_[1].getGlobalBounds().contains(mouse_coord_)){ // Skill I
        return 2;
      }else if(buttons_[2].getGlobalBounds().contains(mouse_coord_)){ // Skill 2
        return 3;
      }else if(buttons_[3].getGlobalBounds().contains(mouse_coord_)){ // Skill 3
        return 4;
      }
    }
  }
  return 0;
}

void Rpg::DrawMessages(string message){
  Text text_message;
  text_message.setFont(font_);
  text_message.setCharacterSize(15);
  text_message.setFillColor(Color::White);
  text_message.setOutlineColor(Color::Black);
  text_message.setOutlineThickness(3);
  text_message.setString(message);

  if(message == "Seu jogador morreu. Game Over."){
    text_message.setCharacterSize(30);
  }

  FloatRect name_rect = text_message.getLocalBounds();
  text_message.setPosition(Vector2f((window_->getSize().x - name_rect.width) / 2, 350));

  window_->draw(text_message);
  window_->display();

  sleep(milliseconds(250));
}

void Rpg::DrawTexts(){
  player_name_.setString(player_.name_);
  player_name_.setCharacterSize(25);
  player_name_.setFont(font_);
  player_name_.setFillColor(Color::White);
  player_name_.setOutlineThickness(3);

  if(player_.classe_ == 0){
    player_name_.setOutlineColor(Color::Blue);
  }else if(player_.classe_ == 1){
    player_name_.setOutlineColor(Color::Magenta);
  }else if(player_.classe_ == 2){
    player_name_.setOutlineColor(Color::Red);
  }  
  
  FloatRect name_rect = player_name_.getLocalBounds();
  player_name_.setPosition(Vector2f((window_->getSize().x - name_rect.width) / 2, 680));

  texts_.resize(4);

  for(int i = 0;i < 3; i++){
    texts_[i].setCharacterSize(15);
    texts_[i].setFont(font_);
    texts_[i].setFillColor(Color::White);
    texts_[i].setOutlineThickness(3);
    texts_[i].setOutlineColor(Color::Black);
  }

  stringstream aux1, aux2, aux3;
  string x;

  aux1 << player_.stats_.atk;
  aux1 >> x;

  texts_[0].setString("Atk: " + x);
  name_rect = texts_[0].getLocalBounds();
  texts_[0].setPosition(Vector2f(((window_->getSize().x - name_rect.width) / 2) - 150, 800));

  aux2 << player_.stats_.def;
  aux2 >> x;

  texts_[1].setString("Def: " + x);
  name_rect = texts_[1].getLocalBounds();
  texts_[1].setPosition(Vector2f((window_->getSize().x - name_rect.width) / 2, 800));

  aux3 << player_.stats_.xp;
  aux3 >> x;

  texts_[2].setString("Xp: " + x);
  name_rect = texts_[2].getLocalBounds();
  texts_[2].setPosition(Vector2f(((window_->getSize().x - name_rect.width) / 2) + 150, 800));

  texts_[3].setCharacterSize(18);
  texts_[3].setFont(font_);
  texts_[3].setFillColor(Color::Black);
  texts_[3].setOutlineThickness(3);
  texts_[3].setOutlineColor(Color::Red);

  texts_[3].setString(opponent_->name_);

  name_rect = texts_[3].getLocalBounds();
  texts_[3].setPosition(Vector2f(((window_->getSize().x - name_rect.width) / 2), 60));

  window_->draw(player_name_);
  for(auto t : texts_){
    window_->draw(t);
  }
}

void Rpg::Draw() {  
  window_->clear(Color::Black);
  window_->draw(*background);
  for(size_t i{}; i < buttons_.size(); i++){
    window_->draw(buttons_[i]);
    window_->draw(buttons_[i]);
  }
  for(size_t i{}; i < cd_skills_.size(); i++){
    for(size_t j{}; j < cd_skills_[i].size(); j++){
      window_->draw(cd_skills_[i][j]);
    } 
    for(size_t j{}; j < cd_skills_[i].size(); j++){
      window_->draw(cd_skills_[i][j]);
    } 
  }
  for(size_t i{}; i < player_status_.size(); i++){
    window_->draw(player_status_[i]);
    window_->draw(player_status_[i]);
  }
  window_->draw(opponent_status_);
  window_->draw(opponent_->img_entity_);
  window_->draw(player_.img_entity_);
  
  DrawTexts();
  window_->display();
}

void Rpg::Run(){
  float tam_x;
  int inimigos_mortos = 0, turnos_sem_usar_skill = 0;

  while(window_->isOpen()){
    for(int turno = 1; player_.stats_.hp > 0 && window_->isOpen(); turno++){
      Game(0,0,0,true,0,0,0,true);
      Draw();
      if(turno % 2){

        for(int i = 0; i < 3; i++){ // Reseta o CD das skills (1 ponto de cooldown por turno do Player)
          for(int j = 0; j < 3; j++){
            if(!player_.skills_cd_[i][j]){
              player_.skills_cd_[i][j] = true;
              cd_skills_[i][j].setFillColor(Color::Green);
              break;
            }
          }
        }

        vector<bool> test_cd_ = {true, true, true};
        for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
            if(!player_.skills_cd_[i][j]){
              test_cd_[i] = false;
            }
          }
        }

        player_.stats_.mp += 5; // Regeneração natural de mana do Player
        if(player_.stats_.mp <= 100){player_.stats_.mp = 100;}

        int evento = 0;

        while(!evento){
          if(!window_->isOpen()){
            return;
          }

          evento = Events();

          switch (evento){
            case 1: // Ataque básico
              cout << "Player usou o AA" << endl;

              if(opponent_->Def(player_.Atk())){
                player_.SettaSprite(player_.ReturnSpriteAtk());
                DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteAtk());
                DadosAnimacao aux_e = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteTomou());

                animaçao_completa_player_ = 0;
                frame_p_ = 0;
                
                while(frame_p_ < (aux_p.frames-aux_e.frames)){
                  Game(0,0,0,true,aux_p.largura,aux_p.altura,aux_p.frames,false);
                  Draw();
                }
                opponent_->SettaSprite(opponent_->ReturnSpriteTomou());
                
                aux_e = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteTomou());
                frame_e_ = 0;
                
                while(!animaçao_completa_player_){
                  Game(aux_e.largura,aux_e.altura,aux_e.frames,false,aux_p.largura,aux_p.altura,aux_p.frames,false);
                  Draw();
                }
                player_.SettaSprite(player_.ReturnSpriteIdle());

                if(opponent_->stats_.hp > 0){
                  opponent_->SettaSprite(opponent_->ReturnSpriteIdle());
                }
                cout << "O jogador acertou o ataque."<< endl;
                cout << "Inimigo esta com " << opponent_->stats_.hp << " de vida restante." << endl;
                
                float tam_x = 461*opponent_->stats_.hp/opponent_->stats_.hp_max;
                opponent_status_.setSize(Vector2f(tam_x, 21));

                stringstream aux;
                string x;

                aux << opponent_->stats_.hp;
                aux >> x;

                DrawMessages("The enemy has " + x + " of HP.");
              }else{
                opponent_->SettaSprite(opponent_->ReturnSpriteDef());
                player_.SettaSprite(player_.ReturnSpriteAtk());

                DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteAtk());
                DadosAnimacao aux_e = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteDef());

                animaçao_completa_player_ = 0;
                frame_e_ = 0;
                frame_p_ = 0;

                while(!animaçao_completa_player_){
                  Game(aux_e.largura,aux_e.altura,aux_e.frames,false,aux_p.largura,aux_p.altura,aux_p.frames,false);
                  Draw();
                }

                cout << "O jogador errou o ataque." <<endl;

                DrawMessages("You miss");

                player_.SettaSprite(player_.ReturnSpriteIdle());
                opponent_->SettaSprite(opponent_->ReturnSpriteIdle());
              }
              break;
            case 2: // Skill I
              cout << "Player usou a skill 1" << endl;
              if(player_.classe_ != 2){ // Mago ou Cavaleiro usaram a skill
                if(player_.stats_.mp >= player_.EntitySkills(0).attributes_.mp && test_cd_[0]){ // Testa se CD e Mana estão ok
                  if(player_.classe_ == 0){
                    player_.stats_.hp += player_.EntitySkills(0).attributes_.hp;
                    if(player_.stats_.hp > player_.stats_.hp_max){player_.stats_.hp = player_.stats_.hp_max;}
                    float tam_x = 461*opponent_->stats_.hp/opponent_->stats_.hp_max;
                    opponent_status_.setSize(Vector2f(tam_x, 21));
                    cout << "Knight curou a vida" << endl;
                    DrawMessages("You heals HP");
                  }else if(player_.classe_ == 1){
                    player_.stats_.def += player_.EntitySkills(0).attributes_.def;
                    cout << "Mage bufou a defesa" << endl;
                    DrawMessages("You gains defense");
                  }
                  player_.stats_.mp -= player_.EntitySkills(0).attributes_.mp;
                  player_status_[1].setSize(Vector2f(409 * player_.stats_.mp / 100,9.4));
                  player_.SettaSprite(player_.ReturnSpriteSkill(0));
                  DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteSkill(0));
                  animaçao_completa_player_ = 0;
                  frame_p_ = 0;
                  while(!animaçao_completa_player_){
                    Game(0,0,0,true,aux_p.largura,aux_p.altura,aux_p.frames,false);
                    Draw();
                  }
                  player_.SettaSprite(player_.ReturnSpriteIdle());

                  float tam_x = 461*opponent_->stats_.hp/opponent_->stats_.hp_max;
                  opponent_status_.setSize(Vector2f(tam_x, 21));
                }else{ // Caso CD ou Mana não forem suficientes
                  cout << "Não foi possível usar a skill" << endl;
                  DrawMessages("Skill isn't ready, you miss your turn");
                }
                for(int i = 0; i < 3; i++){
                  cd_skills_[0][i].setFillColor(Color::Red);
                  player_.skills_cd_[0][i] = false;
                }
              }else if(test_cd_[0]){ // Samurai usou a skill
                cout << "Samurai bufou a mana" << endl;
                DrawMessages("You gains MP");
                player_.stats_.mp += player_.EntitySkills(0).attributes_.mp;
                if(player_.stats_.mp > 100){player_.stats_.hp = 100;}
                player_status_[1].setSize(Vector2f(409 * player_.stats_.mp / 100,9.4));
                player_.SettaSprite(player_.ReturnSpriteSkill(0));
                DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteSkill(0));
                animaçao_completa_player_=0;
                frame_p_=0;
                while(!animaçao_completa_player_){
                  Game(0,0,0,true,aux_p.largura,aux_p.altura,aux_p.frames,false);
                  Draw();
                }
                player_.SettaSprite(player_.ReturnSpriteIdle());

                for(int i = 0; i < 3; i++){
                  cd_skills_[0][i].setFillColor(Color::Red);
                  player_.skills_cd_[0][i] = false;
                }
              }else{ // CD não era o suficiente para o Samurai
                cout << "Não foi possível usar a skill" << endl;
                DrawMessages("Skill isn't ready, you miss your turn");
              }
              break;
            case 3: // Skill II
              cout << "Player usou a skill 2" << endl;
              if(player_.stats_.mp >= player_.EntitySkills(1).attributes_.mp && test_cd_[1]){ // Testa se CD e Mana estão ok
                if(player_.classe_ == 0){
                  player_.stats_.agi += player_.EntitySkills(1).attributes_.agi;
                  opponent_->stats_.hp += player_.EntitySkills(1).attributes_.hp;
                  cout << "Knight bufou a agilidade e causou dano" << endl;
                  float tam_x = 461*opponent_->stats_.hp/opponent_->stats_.hp_max;

                  if(opponent_->stats_.hp <= 0){opponent_->stats_.hp = 0;}

                  stringstream aux;
                  string x;

                  aux << opponent_->stats_.hp;
                  aux >> x;

                  DrawMessages("You deals damage and gain agility \n The enemy has " + x + " of HP.");

                  opponent_status_.setSize(Vector2f(tam_x, 21));
                }else{
                  opponent_->stats_.hp += player_.EntitySkills(1).attributes_.hp;
                  float tam_x = 461*opponent_->stats_.hp/opponent_->stats_.hp_max;
                  opponent_status_.setSize(Vector2f(tam_x, 21));
                  cout << "Mage/Samurai causou dano" << endl;

                  if(opponent_->stats_.hp <= 0){opponent_->stats_.hp = 0;}

                  stringstream aux;
                  string x;

                  aux << opponent_->stats_.hp;
                  aux >> x;
                  DrawMessages("You deals damage \n The enemy has " + x + " of HP.");
                }
                player_.stats_.mp -= player_.EntitySkills(1).attributes_.mp;
                player_.SettaSprite(player_.ReturnSpriteSkill(1));

                DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteSkill(1));
                DadosAnimacao aux_e = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteTomou());

                animaçao_completa_player_ = 0;
                frame_p_ = 0;
               
                while(frame_p_<(aux_p.frames-aux_e.frames)){
                  Game(0,0,0,true,aux_p.largura,aux_p.altura,aux_p.frames,false);
                  Draw();
                }
                aux_e = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteTomou());
                opponent_->SettaSprite(opponent_->ReturnSpriteTomou());
                frame_e_ = 0;
                
                while (!animaçao_completa_player_){
                  Game(aux_e.largura,aux_e.altura,aux_e.frames,true,aux_p.largura,aux_p.altura,aux_p.frames,false);
                  Draw();
                }
                player_.SettaSprite(player_.ReturnSpriteIdle());
                
                if(opponent_->stats_.hp > 0){
                  opponent_->SettaSprite(opponent_->ReturnSpriteIdle());
                }
      
                for(int i = 0; i < 3; i++){
                  cd_skills_[1][i].setFillColor(Color::Red);
                  player_.skills_cd_[1][i] = false;
                }

                player_status_[1].setSize(Vector2f(409 * player_.stats_.mp / 100,9.4));
                
              }else{ // Caso CD ou Mana não forem suficientes
                cout << "Não foi possível usar a skill" << endl;
                DrawMessages("Skill isn't ready, you miss your turn");
              }
              break;
            case 4: // Skill III
              cout << "Player usou a skill 3" << endl;
              if(player_.stats_.mp >= player_.EntitySkills(2).attributes_.mp && test_cd_[2]){ // Testa se CD e Mana estão ok
                if(player_.classe_ == 2){
                  opponent_->stats_.hp += player_.EntitySkills(2).attributes_.hp;
                  opponent_->stats_.def += player_.EntitySkills(2).attributes_.def;
                  cout << "Samurai causou dano e reduziu a defesa do inimigo" << endl;

                  if(opponent_->stats_.hp <= 0){opponent_->stats_.hp = 0;}

                  stringstream aux;
                  string x;

                  aux << opponent_->stats_.hp;
                  aux >> x;

                  DrawMessages("You deals damage and low the opponent defense \n The enemy has " + x + " of HP.");

                  float tam_x = 461*opponent_->stats_.hp/opponent_->stats_.hp_max;
                  if(opponent_->stats_.hp <= 0){tam_x = 0;}
                  opponent_status_.setSize(Vector2f(tam_x, 21));
                }else{
                  opponent_->stats_.hp += player_.EntitySkills(2).attributes_.hp;
                  opponent_status_.setSize(Vector2f(tam_x, 21));
                  cout << "Mage/Knight causou dano" << endl;

                  if(opponent_->stats_.hp <= 0){opponent_->stats_.hp = 0;}

                  stringstream aux;
                  string x;

                  aux << opponent_->stats_.hp;
                  aux >> x;

                  DrawMessages("   You deals damage \n The enemy has " + x + " of HP.");
                  // DrawMessages("The enemy has " + x + " of HP.");

                  float tam_x = 461*opponent_->stats_.hp/opponent_->stats_.hp_max;
                  if(opponent_->stats_.hp <= 0){tam_x = 0;}
                  opponent_status_.setSize(Vector2f(tam_x, 21));
                }
                player_.stats_.mp -= player_.EntitySkills(0).attributes_.mp;
                player_.SettaSprite(player_.ReturnSpriteSkill(2));
                DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteSkill(2));
                DadosAnimacao aux_e = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteTomou());
                animaçao_completa_player_=0;
                frame_p_ = 0;
                while(frame_p_<(aux_p.frames-aux_e.frames)){
                  // if(player_.classe_ == 1){
                  //   img_skill.setPosition((window_->getSize().x - rect.width) / 2,490);
                  //   window_->draw(img_skill);
                  // }
                  Game(0,0,0,true,aux_p.largura,aux_p.altura,aux_p.frames,false);
                  Draw();
                }
                aux_e=opponent_->ReturnDadosSprite(opponent_->ReturnSpriteTomou());
                opponent_->SettaSprite(opponent_->ReturnSpriteTomou());
                frame_e_=0;
                while (!animaçao_completa_player_){
                  Game(aux_e.largura,aux_e.altura,aux_e.frames,true,aux_p.largura,aux_p.altura,aux_p.frames,false);
                  Draw();
                }
                player_.SettaSprite(player_.ReturnSpriteIdle());
                if(opponent_->stats_.hp > 0){
                  opponent_->SettaSprite(opponent_->ReturnSpriteIdle());
                }
                for(int i = 0; i < 3; i++){
                  cd_skills_[2][i].setFillColor(Color::Red);
                  player_.skills_cd_[2][i] = false;
                }
                player_status_[1].setSize(Vector2f(409 * player_.stats_.mp / 100,9.4));
              }else{ // Caso CD ou Mana não forem suficientes
                cout << "Não foi possível usar a skill" << endl;
                DrawMessages("Skill isn't ready, you miss your turn");
              }
              break;
            default:
              break;
          }
          Game(0,0,0,true,0,0,0,true);
          Draw();
        }

        if(opponent_->stats_.hp <= 0 ){
          player_.Upar(opponent_->stats_.xp);
          inimigos_mortos++;

          ItemDraw();

          opponent_->BuffaInimigo(inimigos_mortos);

          player_.Upar(20); 

          delete opponent_;

          if(!(inimigos_mortos%2)){ // A cada 7 inimigos mortos, o próximo a spawnar é um boss.
            opponent_ = new Boss();
            turnos_sem_usar_skill = 0;
          }else{
            opponent_ = new Enemy();
          }
        
          tam_x = 461*player_.stats_.hp/player_.stats_.hp_max;
          player_status_[0].setSize(Vector2f(tam_x, 21));

          opponent_status_.setSize(Vector2f(0, 21));

          DrawMessages("You kill the enemy");

          cout << "Você derrotou o inimigo!" << endl;
          cout << "O novo inimigo gerado aleatoriamente é um " << opponent_->name_ << "." << endl;

          opponent_status_.setSize(Vector2f(461, 21));
        }else if(opponent_->name_ == "Is'Abelu" && ((rand() % 100)*turnos_sem_usar_skill >= 130)){
          player_.stats_.hp += opponent_->EntitySkills(0).attributes_.hp;
          opponent_->SettaSprite("resources/boss/sprite_boss_skill.png");

          DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteTomou());
          DadosAnimacao aux_e = opponent_->ReturnDadosSprite("resources/boss/sprite_boss_skill.png");

          animaçao_completa_enemy_ = 0;
          frame_e_ = 0;
          frame_p_ = 0;

          while(frame_e_<(aux_e.frames-aux_p.frames)){
            Game(aux_e.largura,aux_e.altura,aux_e.frames,false,0,0,0,true);
            Draw();
          }
          player_.SettaSprite(player_.ReturnSpriteTomou());
          aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteTomou());
          
          while(!animaçao_completa_enemy_){
            Game(aux_e.largura,aux_e.altura,aux_e.frames,false,aux_p.largura,aux_p.altura,aux_p.frames,false);
            Draw();
          }
          player_.SettaSprite(player_.ReturnSpriteIdle());
          opponent_->SettaSprite(opponent_->ReturnSpriteIdle());
          turnos_sem_usar_skill = 0;
          cout << "Boss castou a skill" << endl;

          if(player_.stats_.hp <= 0){player_.stats_.hp = 0;}

          stringstream aux;
          string x;

          aux << player_.stats_.hp;
          aux >> x;

          DrawMessages("You has " + x + " of HP.");

          tam_x = 461*player_.stats_.hp/player_.stats_.hp_max;

          if(tam_x > 461){tam_x = 461; player_.stats_.hp = player_.stats_.hp_max;}

          player_status_[0].setSize(Vector2f(tam_x,21));

          if(player_.stats_.hp <= 0){
            player_status_[0].setSize(Vector2f(0,21));

            player_.SettaSprite(player_.ReturnSpriteMorte());
            DadosAnimacao aux = player_.ReturnDadosSprite(player_.ReturnSpriteMorte());

            animaçao_completa_player_=0;
            frame_p_=0;

            while(!animaçao_completa_player_){
              Game(0,0,0,true,aux.largura,aux.altura,aux.frames,false);
              Draw();  
            }

            cout << "Seu jogador morreu." << '\n' << "Game Over =(" << endl;

            window_->clear();

            DrawMessages("Seu jogador morreu. Game Over.");

            sleep(seconds(5));

            window_->close();
          }
        }
        else if(player_.Def(opponent_->Atk())){
          opponent_->SettaSprite(opponent_->ReturnSpriteAtk());

          DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteTomou());
          DadosAnimacao aux_e = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteAtk());

          animaçao_completa_enemy_ = 0;
          frame_e_ = 0;
          frame_p_ = 0;

          while(frame_e_<(aux_e.frames-aux_p.frames)){
            Game(aux_e.largura,aux_e.altura,aux_e.frames,false,0,0,0,true);
            Draw();
          }
          player_.SettaSprite(player_.ReturnSpriteTomou());

          while(!animaçao_completa_enemy_){
            Game(aux_e.largura,aux_e.altura,aux_e.frames,false,aux_p.largura,aux_p.altura,aux_p.frames,false);
            Draw();
          }
          player_.SettaSprite(player_.ReturnSpriteIdle());
          opponent_->SettaSprite(opponent_->ReturnSpriteIdle());
          turnos_sem_usar_skill++;

          stringstream aux;
          string x;

          aux << player_.stats_.hp;
          aux >> x;

          DrawMessages("You has " + x + " of HP.");

          tam_x = 461*player_.stats_.hp/player_.stats_.hp_max;

          if(tam_x > 461){tam_x = 461; player_.stats_.hp = player_.stats_.hp_max;}

          player_status_[0].setSize(Vector2f(tam_x,21));

          if(player_.stats_.hp <= 0){
            player_status_[0].setSize(Vector2f(0,21));

            player_.SettaSprite(player_.ReturnSpriteMorte());
            DadosAnimacao aux = player_.ReturnDadosSprite(player_.ReturnSpriteMorte());

            animaçao_completa_player_=0;
            frame_p_=0;

            while(!animaçao_completa_player_){
              Game(0,0,0,true,aux.largura,aux.altura,aux.frames,false);
              Draw();  
            }

            cout << "Seu jogador morreu." << '\n' << "Game Over =(" << endl;

            window_->clear();

            DrawMessages("Seu jogador morreu. Game Over.");

            sleep(seconds(5));

            window_->close();
          }
        }else{
          opponent_->SettaSprite(opponent_->ReturnSpriteAtk());
          DadosAnimacao aux_e = opponent_->ReturnDadosSprite(opponent_->ReturnSpriteAtk());

          animaçao_completa_enemy_ = 0;
          frame_e_ = 0;
          frame_p_ = 0;

          DadosAnimacao aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteDef());

          while(frame_e_<(aux_e.frames-aux_p.frames)){
            Game(aux_e.largura,aux_e.altura,aux_e.frames,false,0,0,0,true);
            Draw();
          }
          aux_p = player_.ReturnDadosSprite(player_.ReturnSpriteDef());
          player_.SettaSprite(player_.ReturnSpriteDef());

          while(!animaçao_completa_enemy_){
            Game(aux_e.largura,aux_e.altura,aux_e.frames,false,aux_p.largura,aux_p.altura,aux_p.frames,false);
            Draw();
          }
          Game(aux_e.largura,aux_e.altura,aux_e.frames,false,aux_p.largura,aux_p.altura,aux_p.frames,false);

          player_.SettaSprite(player_.ReturnSpriteIdle());
          opponent_->SettaSprite(opponent_->ReturnSpriteIdle());
          cout << "Inimigo errou o golpe." << endl;
          turnos_sem_usar_skill++;

          DrawMessages("Opponent miss");
        }
      }
      Draw();
    }
  }
}