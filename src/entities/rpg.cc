#include "../../include/rpg.h"

Rpg::Rpg(Player jogador){
    player_ = jogador;

    window = std::make_shared<RenderWindow>(
        VideoMode(1200, 928),
        "nometemporario",
        Style::Titlebar | Style::Close
    );
    window->setPosition(Vector2i(0, 0));
    window->setFramerateLimit(100);

    bg.loadFromFile("resources/bgs/bg_temp.png");
    background = make_shared<Sprite>();
    background->setTexture(bg);
    background->setScale(2.35,2.35);

    buttons_.resize(4);
    buttons_[0].setSize(Vector2f(141, 141));
    buttons_[0].setPosition(Vector2f(122, 692));
    buttons_[0].setFillColor(Color::Transparent);
    buttons_[0].setOutlineColor(Color::Red);
    buttons_[0].setOutlineThickness(4);

    buttons_[1].setSize(Vector2f(65, 65));
    buttons_[1].setPosition(Vector2f(915, 680));
    buttons_[1].setFillColor(Color::Transparent);
    buttons_[1].setOutlineColor(Color::Red);
    buttons_[1].setOutlineThickness(4);

    buttons_[2].setSize(Vector2f(65, 65));
    buttons_[2].setPosition(Vector2f(1037, 680));
    buttons_[2].setFillColor(Color::Transparent);
    buttons_[2].setOutlineColor(Color::Red);
    buttons_[2].setOutlineThickness(4);

    buttons_[3].setSize(Vector2f(65, 65));
    buttons_[3].setPosition(Vector2f(976, 767));
    buttons_[3].setFillColor(Color::Transparent);
    buttons_[3].setOutlineColor(Color::Red);
    buttons_[3].setOutlineThickness(4);

    player_status_.resize(2);

    player_status_[0].setFillColor(Color::Green);
    player_status_[0].setOutlineThickness(0);
    player_status_[0].setSize(Vector2f(461, 21));
    player_status_[0].setPosition(Vector2f(369, 738));

    player_status_[1].setFillColor(Color::Blue);
    player_status_[1].setOutlineThickness(0);
    player_status_[1].setSize(Vector2f(409, 9.4));
    player_status_[1].setPosition(Vector2f(395, 766));

    stringstream aux;
    string aux_s;

    texts_strings_.push_back(player_.name_);

    aux << player_.stats_.atk;
    aux >> aux_s;

    texts_strings_.push_back(aux_s);

    aux << player_.stats_.def;
    aux >> aux_s;

    texts_strings_.push_back(aux_s);

    aux << player_.stats_.xp;
    aux >> aux_s;

    texts_strings_.push_back(aux_s);

    texts_sizes_.resize(4);
    texts_sizes_ = {25,16,15,15};

    Font fonte;
    fonte.loadFromFile("../../fonts/super_legend_boy.ttf");

    for(int i = 0; i < 4; i++){
        texts_[i].setString(texts_strings_[i]);
        texts_[i].setCharacterSize(texts_sizes_[i]);
        texts_[i].setFont(fonte);
    }

    texts_coords_.resize(4);

    float var = texts_[0].getGlobalBounds().width()/2;

    texts_coords_ = {{600 - var, },{},{},{}};
}

void Rpg::Game(){
    frame += 0.07;
    SetAnimePlayer();
}

void Rpg::SetAnimeEnemy(){
    
}

void Rpg::SetAnimePlayer(){
    if(player_.classe_ == 0){
        player_.img_player_.setPosition(150,300);
        
        if (frame > 4){
            frame -= 4;
        }

        player_.img_player_.setTextureRect(IntRect(67*(int)frame,0,67,64));
    }else if(player_.classe_ == 1){
        player_.img_player_.setPosition(125,285);    

        if(frame > 8){
            frame -= 8;
        }

        player_.img_player_.setTextureRect(IntRect(67*(int)frame,0,67,67));
    }else if(player_.classe_ == 2){
        player_.img_player_.setPosition(110,265);
        
        if(frame > 6){
            frame -= 6;
        }

        player_.img_player_.setTextureRect(IntRect(67*(int)frame,0,67,70));
    }
}

void Rpg::Events() {
    auto event = make_shared<Event>();
    while (window->pollEvent(*event)) {
        if (event->type == Event::Closed) {
            window->close();

        }
    }
}

void Rpg::Draw() {
    window->clear(Color::Black);
    window->draw(*background);
    for(int i = 0; i < 4; i++){
        window->draw(buttons_[i]);
    }
    for(int i = 0; i < 2; i++){
        window->draw(player_status_[i]);
    }
    window->draw(player_.img_player_);
    window->display();

}

void Rpg::Run() {
    while (window->isOpen()) {
        Events();
        Game();
        Draw();
    }
}