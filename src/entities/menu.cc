#include "../../include/menu.h"

Menu::Menu(){
  window_ = new RenderWindow();
  winclose_ = new RectangleShape();
  font_ = new Font();
  image_ = new Texture();
  bg_ = new Sprite();

  SetValues();
}

Menu::~Menu(){
  delete window_;
  delete winclose_;
  delete font_;
  delete image_;
  delete bg_;
}

void Menu::SetValues(){
  window_->create(VideoMode(1280,720), "Menu ", Style::Titlebar | Style::Close);
  window_->setPosition(Vector2i(0,0));

  pos_ = 0;
  pressed_ = theselect_ = false;
  font_->loadFromFile("./ethn.otf");
  image_->loadFromFile("./menu-sci-fi-game.png");

  bg_->setTexture(*image_);

  pos_mouse_ = {0,0};
  mouse_coord_ = {0, 0};

  options_ = {"War Game", "Play", "Options", "About", "Quit"};
  texts_.resize(5);
  coords_ = {{590,40},{610,191},{590,282},{600,370},{623,457}};
  sizes_ = {20,28,24,24,24};

  for (size_t i{}; i < texts_.size(); ++i){
   texts_[i].setFont(*font_); 
   texts_[i].setString(options_[i]); 
   texts_[i].setCharacterSize(sizes_[i]);
   texts_[i].setOutlineColor(Color::Black);
   texts_[i].setPosition(coords_[i]);
  }
  texts_[1].setOutlineThickness(4);
  pos_ = 1;

  winclose_->setSize(Vector2f(23,26));
  winclose_->setPosition(1178,39);
  winclose_->setFillColor(Color::Transparent);
}

void Menu::LoopEvents(){
  Event event;
  while(window_->pollEvent(event)){
    if( event.type == Event::Closed){
      window_->close();
    }

    pos_mouse_ = Mouse::getPosition(*window_);
    mouse_coord_ = window_->mapPixelToCoords(pos_mouse_);

    if(Keyboard::isKeyPressed(Keyboard::Down) && !pressed_){
      if( pos_ < 4){
        ++pos_;
        pressed_ = true;
        texts_[pos_].setOutlineThickness(4);
        texts_[pos_ - 1].setOutlineThickness(0);
        pressed_ = false;
        theselect_ = false;
      }
    }

    if(Keyboard::isKeyPressed(Keyboard::Up) && !pressed_){
      if( pos_ > 1){
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
      if( pos_ == 4){
        window_->close();
      }
      cout << options_[pos_] << '\n';
    }

    if(Mouse::isButtonPressed(Mouse::Left)){
      if(winclose_->getGlobalBounds().contains(mouse_coord_)){
        window_->close();
      }
    }
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
}