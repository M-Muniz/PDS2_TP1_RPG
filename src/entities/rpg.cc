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