#include "../../include/rpg.h"

Rpg::Rpg(Player jogador){
  player_ = jogador;
  mouse_coord_={0,0};
  pos_mouse_={0,0};
  window = std::make_shared<RenderWindow>(VideoMode(1200, 928), "Rpg", Style::Titlebar | Style::Close);
  window->setPosition(Vector2i(0, 0));
  window->setFramerateLimit(100);
  Enemy inimigo1;
  enemys_.push_back(inimigo1);
  cout << "Nome do inimigo gerado aleatoriamente: " << enemys_[0].name_<<endl;


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

  // stringstream aux;
  // string aux_s_1 = "teste1", aux_s_2 = "teste2", aux_s_3 = "teste3";

  // aux << player_.stats_.atk;
  // aux >> aux_s_1;

  // aux << player_.stats_.def;
  // aux >> aux_s_2;

  // aux << player_.stats_.xp;
  // aux >> aux_s_3;

  // texts_strings_ = {aux_s_1, aux_s_2, aux_s_3};
  // texts_coords_ = {{0,0},{0,0},{0,0}};

  // Font fonte;
  // fonte.loadFromFile("fonts/super_legend_boy.ttf");

  // texts_.resize(3);

  // for(size_t i{}; i < texts_.size(); i++){
  //     texts_[i].setString(texts_strings_[i]);
  //     texts_[i].setFont(fonte);
  //     texts_[i].setPosition(texts_coords_[i]);
  //     texts_[i].setCharacterSize(15);
  //     texts_[i].setFillColor(Color::White);
  //     texts_[i].setOutlineColor(Color::Black);
  //     texts_[i].setOutlineThickness(2);
  // }

  // texts_[0].setString(texts_strings_[0]);
  // texts_[0].setFillColor(Color::White);
  // texts_[0].setOutlineColor(Color::Black);
  // texts_[0].setOutlineThickness(2);
  // texts_[0].setCharacterSize(15);
  // texts_[0].setFont(fonte);

  // FloatRect text_bound = texts_[0].getLocalBounds();
  // float x = (1200 - text_bound.width)/2;

  // texts_[0].setPosition(Vector2f(0,830));
  // texts_[1].setPosition(Vector2f());
  // texts_[2].setPosition(Vector2f());
}

void Rpg::Game(){
    frame_p_ += 0.07;
    frame_e_ += 0.07;
    //SetAnimeEnemy();
    SetAnimePlayer();

}

/*void Rpg::SetAnimeEnemy(){
    
    if(enemys_[0].name_ =="Sword Skeleton"){

        enemys_[0].img_enemy_.setPosition(500,500);

        if(frame_e_ > 7){                               TODO
            frame_e_-=7;                      funçao que vai animar os inimigos 

        }
    enemys_[0].img_enemy_.setTextureRect(IntRect(67*(int)frame_e_,0,67,59));
    }else if(enemys_[0].name_ =="Small Werewolf"||enemys_[0].name_ =="Big Werewolf"){
        enemys_[0].img_enemy_.setPosition(500,500);
        if(frame_e_ > 8){
            frame_e_-=8;
        }
    enemys_[0].img_enemy_.setTextureRect(IntRect(80*(int)frame_e_,0,80,59));
    }else if(enemys_[0].name_ =="Spear Skeleton"){
        enemys_[0].img_enemy_.setPosition(500,500);
        if(frame_e_ > 7){
            frame_e_ -= 7;
        }
    enemys_[0].img_enemy_.setTextureRect(IntRect(67*(int)frame_e_,0,67,84));
    }

}*/

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
  pos_mouse_ = Mouse::getPosition(*window);
  mouse_coord_ = window->mapPixelToCoords(pos_mouse_);

  while (window->pollEvent(event)) {
    if (event.type == Event::Closed) {
      window->close();
      return -1;
    }
    // if(){}
    // if(){}
    // if(){}
    return 0;
  }
  if(Mouse::isButtonPressed(Mouse::Left)){  
    if(buttons_[0].getGlobalBounds().contains(mouse_coord_)){
      if(enemys_.front().Def(player_.Atk())){
        cout << "O jogador acertou o ataque."<< endl;
        cout << "Inimigo esta com " << enemys_.front().stats_.hp << " de vida restante." << endl;
      }else{
        cout << "O jogador errou o ataque." <<endl;
      }
      return 1;
    }
  }
  return 0;
}

void Rpg::Draw() {
  window->clear(Color::Black);
  window->draw(*background);
  for(size_t i{}; i < buttons_.size(); i++){
      window->draw(buttons_[i]);
  }
  for(size_t i{}; i < cd_skills_.size(); i++){
      for(size_t j{}; j < cd_skills_[i].size(); j++){
          window->draw(cd_skills_[i][j]);
      } 
  }
  for(size_t i{}; i < player_status_.size(); i++){
      window->draw(player_status_[i]);
  }
  // for(auto t : texts_){
  //     window->draw(t);
  // }
  // window->draw(texts_.front());
  window->draw(enemys_.front().img_enemy_);
  window->draw(player_.img_player_);
  window->display();
}

void Rpg::Run() {
  while(window->isOpen()){
    for(int turno = 1; player_.stats_.hp > 0 && window->isOpen(); turno++){
      Game();
      Draw();

      if(turno % 2 == 1){

        while(!Events() && window->isOpen()){
          if(!window->isOpen()){
            return;
          }

          Game();
          Draw();
        }

        if(enemys_.front().stats_.hp <= 0 ){
          Enemy inimigo_novo;
          enemys_.pop_back();
          enemys_.push_back(inimigo_novo);
          cout << "Você derrotou o inimigo!" << endl;
          cout << "O novo inimigo gerado aleatoriamente é um " << inimigo_novo.name_ << "." << endl;
        }

      }else{
        if(player_.Def(enemys_.front().Atk())){
          cout << "Inimigo acertou o golpe. O player esta com " << player_.stats_.hp;
          cout << " de vida restante." << endl;
          cout << "Inimigo esta com " << enemys_.front().stats_.hp << " de vida restante." << endl;
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