#include "../../include/rpg.h"

Rpg::Rpg(Player jogador){
  player_ = jogador;
  mouse_coord_={0,0};
  pos_mouse_={0,0};
  window_ = std::make_shared<RenderWindow>(VideoMode(1200, 928), "Rpg", Style::Titlebar | Style::Close);
  window_->setPosition(Vector2i(0, 0));
  window_->setFramerateLimit(100);
  inimigo1_ = new Enemy();
  enemys_.push_back(*(inimigo1_));
  cout << "Nome do inimigo gerado aleatoriamente: " << enemys_[0].name_<<endl;
  frame_e_=0;
  frame_p_=0;

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

  enemy_status_.setSize(Vector2f(461,21));
  enemy_status_.setFillColor(Color::Red);
  enemy_status_.setPosition(Vector2f(369, 18));
}

void Rpg::Game(){
  frame_p_ += 0.07;
  frame_e_ += 0.07;
  SetAnimePlayer();
  SetAnimeEnemy();
  }
void Rpg::SetAnimeEnemy(){
    
     if(enemys_[0].name_ =="Sword Skeleton"){

         enemys_[0].img_enemy_.setPosition(500,500);

         if(frame_e_ > 7){ 
             frame_e_-=7;                     

         }
     enemys_[0].img_enemy_.setTextureRect(IntRect(67*(int)frame_e_,0,67,80));
     }else if(enemys_[0].name_ =="Small Werewolf"||enemys_[0].name_ =="Big Werewolf"){
         enemys_[0].img_enemy_.setPosition(500,500);
         if(frame_e_ > 8){
            frame_e_-=8;
         }
     enemys_[0].img_enemy_.setTextureRect(IntRect(80*(int)frame_e_,0,80,100));
    }else if(enemys_[0].name_ =="Spear Skeleton"){
       enemys_[0].img_enemy_.setPosition(500,500);
       if(frame_e_ > 7){
            frame_e_ -= 7;
         }
    enemys_[0].img_enemy_.setTextureRect(IntRect(67*(int)frame_e_,0,80,110));
   }

 }
void Rpg::SetAnimePlayer(){
  if(player_.classe_ == 0){
    player_.img_player_.setPosition(150,300);

    if (frame_p_ > 4){
        frame_p_ -= 4;
    }

    player_.img_player_.setTextureRect(IntRect(67*(int)frame_p_,0,67,64));
  }else if(player_.classe_ == 1){
    player_.img_player_.setPosition(125,285);    

    if(frame_p_ > 8){
        frame_p_ -= 8;
    }

    player_.img_player_.setTextureRect(IntRect(67*(int)frame_p_,0,67,67));
  }else if(player_.classe_ == 2){
    player_.img_player_.setPosition(110,265);

    if(frame_p_ > 6){
        frame_p_ -= 6;
    }

    player_.img_player_.setTextureRect(IntRect(67*(int)frame_p_,0,67,70));
  }
  
}

int Rpg::Events() {
  Event event;
  pos_mouse_ = Mouse::getPosition(*window_);
  mouse_coord_ = window_->mapPixelToCoords(pos_mouse_);

  while (window_->pollEvent(event) && window_->isOpen()){
    if (event.type == Event::Closed) {
      window_->close();
    }
    if(Mouse::isButtonPressed(Mouse::Left)){  
      if(buttons_[0].getGlobalBounds().contains(mouse_coord_)){
        if(enemys_.front().Def(player_.Atk())){
          cout << "O jogador acertou o ataque."<< endl;
          cout << "Inimigo esta com " << enemys_.front().stats_.hp << " de vida restante." << endl;

          float tam_x = 461*enemys_.front().stats_.hp/enemys_.front().stats_.hp_max;
          enemy_status_.setSize(Vector2f(tam_x,21));
          enemy_status_.setFillColor(Color::Red);
          enemy_status_.setPosition(Vector2f(369, 18));
        }else{
          cout << "O jogador errou o ataque." <<endl;
        }
        return 1;
      }
    }
  }
  return 0;
}

void Rpg::DrawTexts(){
  Font font;
  font.loadFromFile("fonts/super_legend_boy.ttf"); 

  player_name_.setString(player_.name_);
  player_name_.setCharacterSize(25);
  player_name_.setFont(font);
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
    texts_[i].setFont(font);
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
  texts_[3].setFont(font);
  texts_[3].setFillColor(Color::Black);
  texts_[3].setOutlineThickness(3);
  texts_[3].setOutlineColor(Color::Red);
  texts_[3].setString(enemys_.front().name_);

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
  }
  for(size_t i{}; i < cd_skills_.size(); i++){
    for(size_t j{}; j < cd_skills_[i].size(); j++){
      window_->draw(cd_skills_[i][j]);
    } 
  }
  for(size_t i{}; i < player_status_.size(); i++){
    window_->draw(player_status_[i]);
  }
  window_->draw(enemy_status_);
  DrawTexts();
  window_->draw(player_.img_player_);
  window_->draw(enemys_[0].img_enemy_);
  window_->display();
}

void Rpg::Run() {
  while(window_->isOpen()){
    for(int turno = 1; player_.stats_.hp > 0 && window_->isOpen(); turno++){
      Game();
      Draw();

      if(turno % 2 == 1){

        while(!Events() && window_->isOpen()){
          if(!window_->isOpen()){
            return;
          }

          Game();
          Draw();
        }
      }else{
        if(enemys_.front().stats_.hp <= 0 ){
          Enemy inimigo_novo;
          enemys_.front().drop_item_.Sum(player_);
          cout << player_.Atk() << endl;
          cout << player_.stats_.def << endl;
          cout << player_.stats_.agi << endl;
          cout << player_.stats_.hp << endl;
          cout << player_.stats_.hp_max << endl;
          player_.Upar(enemys_.front().stats_.xp);
          enemys_.pop_back();
          enemys_.push_back(inimigo_novo);
          cout << "Você derrotou o inimigo!" << endl;
          cout << "O novo inimigo gerado aleatoriamente é um " << inimigo_novo.name_ << "." << endl;
        }else if(player_.Def(enemys_.front().Atk())){
          cout << "Inimigo acertou o golpe. O player esta com " << player_.stats_.hp;
          cout << " de vida restante." << endl;
          cout << "Inimigo esta com " << enemys_.front().stats_.hp << " de vida restante." << endl;
          if(player_.stats_.hp <= 0){
            player_status_[0].setSize(Vector2f(0,21));
            player_status_[0].setFillColor(Color::Green);
            player_status_[0].setPosition(Vector2f(369, 738));

            cout << "Seu jogador morreu." << '\n' << "Game Over =(" << endl;

            window_->close();
          }
          
          float tam_x = 461*player_.stats_.hp/player_.stats_.hp_max;
          player_status_[0].setSize(Vector2f(tam_x,21));
          player_status_[0].setFillColor(Color::Green);
          player_status_[0].setPosition(Vector2f(369, 738));
        }else{
          cout << "Inimigo errou o golpe." << endl;
        }
      }
    }
  }
}