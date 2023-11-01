#include "../../include/rpg.h"

Rpg::Rpg(Player jogador){
    player_ = jogador;

    window = std::make_shared<RenderWindow>(VideoMode(1200, 928), "nometemporario", Style::Titlebar | Style::Close);
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

    stringstream aux;
    string aux_s_1, aux_s_2, aux_s_3;

    aux << player_.stats_.atk;
    aux >> aux_s_1;

    aux << player_.stats_.def;
    aux >> aux_s_2;

    aux << player_.stats_.xp;
    aux >> aux_s_3;

    texts_strings_ = {aux_s_1, aux_s_2, aux_s_3};
    texts_coords_ = {{0,0},{0,0},{0,0}};

    Font fonte;
    fonte.loadFromFile("fonts/super_legend_boy.ttf");

    texts_.resize(3);

    for(size_t i{}; i < texts_.size(); i++){
        texts_[i].setString(texts_strings_[i]);
        texts_[i].setFont(fonte);
        texts_[i].setPosition(texts_coords_[i]);
        texts_[i].setCharacterSize(15);
        texts_[i].setFillColor(Color::White);
        texts_[i].setOutlineColor(Color::Black);
        texts_[i].setOutlineThickness(2);
    }

    // texts_[0].setString(texts_strings_[0]);
    // texts_[0].setFillColor(Color::White);
    // texts_[0].setOutlineColor(Color::Black);
    // texts_[0].setOutlineThickness(2);
    // texts_[0].setCharacterSize(15);
    // texts_[0].setFont(fonte);

    FloatRect text_bound = texts_[0].getLocalBounds();
    float x = (1200 - text_bound.width)/2;

    texts_[0].setPosition(Vector2f(x,830));
    // texts_[1].setPosition(Vector2f());
    // texts_[2].setPosition(Vector2f());
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
    // for(size_t i{}; i < texts_.size(); i++){
    //     window->draw(texts_[i]);
    // }
    
    window->draw(texts_[0]);
    
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