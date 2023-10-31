#include "../../include/menu.h"
#include "../../include/menu.h"

Menu::Menu(){
  window_ = new RenderWindow();
  font_ = new Font();
  image_ = new Texture();
  bg_ = new Sprite();

  SetValues();
}

Menu::~Menu(){
  delete window_;
  delete font_;
  delete image_;
  delete bg_;
}

void Menu::SetValues(){
  window_->create(VideoMode(1240,720), "Menu Inicial", Style::Titlebar | Style::Close);
  window_->setPosition(Vector2i(0,0));

  pos_ = 1;
  pressed_ = theselect_ = false;
  font_->loadFromFile("fonts/super_legend_boy.ttf");
  image_->loadFromFile("resources/bg_menu.png");

  bg_->setTexture(*image_);

  options_ = {"RPG - TP1", "Choose your class", "Knight", "Mage", "Rogue"};
  texts_.resize(5);
  coords_ = {{575,55},{525,205},{600,310},{620,415},{610,515}};
  sizes_ = {20,20,24,24,24};

  for (size_t i{}; i < texts_.size(); ++i){
    texts_[i].setFont(*font_); 
    texts_[i].setString(options_[i]); 
    texts_[i].setCharacterSize(sizes_[i]);
    texts_[i].setPosition(coords_[i]);
  }
  texts_[0].setFillColor(Color::Red);
  texts_[1].setFillColor(Color::Black);
  texts_[2].setOutlineColor(Color::Blue);
  texts_[3].setOutlineColor(Color::Magenta);
  texts_[4].setOutlineColor(Color::Green);
}

void Menu::LoopEvents(){
  Event event;
  while(window_->pollEvent(event)){
    if( event.type == Event::Closed){
      window_->close();
    }

    if(Keyboard::isKeyPressed(Keyboard::Down) && !pressed_){
      if(pos_ < 4){
        ++pos_;
        pressed_ = true;
        texts_[pos_].setOutlineThickness(4);
        texts_[pos_ - 1].setOutlineThickness(0);
        pressed_ = false;
        theselect_ = false;
      }
    }

    if(Keyboard::isKeyPressed(Keyboard::Up) && !pressed_){
      if(pos_ > 2){
        --pos_;
        pressed_ = true;
        texts_[pos_].setOutlineThickness(4);
        texts_[pos_ + 1].setOutlineThickness(0);
        pressed_ = false;
        theselect_ = false;
      }
    }

    if(Keyboard::isKeyPressed(Keyboard::Enter) && !theselect_){
      theselect_ = true;
      cout << options_[pos_] << '\n';
      window_->close();
    }
  }
}

void Menu::ReceiveName(){
  RenderWindow window(VideoMode(500, 100), "Name select");
  
  Texture bg;
  bg.loadFromFile("resources/bg_insert_name.png");
  
  Sprite background;
  background.setTexture(bg);

  window.setPosition(Vector2i(0,0));

  Font font;
  font.loadFromFile("fonts/super_legend_boy.ttf"); 
  
  Text title;
  title.setString("What's your player name?");
  title.setFont(font);
  title.setPosition({100, 15});
  title.setCharacterSize(18);
  title.setFillColor(Color::White);
  
  Text input_text;
  input_text.setFont(font);
  input_text.setCharacterSize(15);
  input_text.setPosition(90, 55);
  input_text.setFillColor(Color::Black);

  while (window.isOpen()){
    Event event;
    while (window.pollEvent(event)){
      if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Enter)){
          window.close();
      }
      else if (event.type == Event::TextEntered){
        if (event.text.unicode == 8){ // Verifique se a tecla Backspace foi pressionada
          if(!player_name_.empty()){
            player_name_.pop_back(); // Remove o último caractere da string
          }
        }else if(event.text.unicode < 128 && player_name_.size() < 10){ // Limite de 10 caracteres para o nome
          player_name_ += static_cast<char>(event.text.unicode); // Adicione o caractere à string caso 
        }

        input_text.setString(player_name_);
      }
    }
    window.clear(Color::Black);
    window.draw(background);
    window.draw(title);
    window.draw(input_text);
    window.display();
  }
}

void Menu::DrawAll(){
  window_->clear();
  window_->draw(*bg_);
  for(auto t : texts_){
   window_->draw(t); 
  }
  window_->display();
}

void Menu::RunMenu(){
  while(window_->isOpen()){
    LoopEvents();
    DrawAll();
  }
  ReceiveName();
  cout << options_[pos_] << " " << player_name_ << endl; // Imprime os dados no terminal para fins de verificação
}

int Menu::ReturnClass(){return (pos_-2);} //Retorna a classe do player baseado na posiçao do menu subtraida de 2 pra correção

string Menu::ReturnName(){return player_name_;}