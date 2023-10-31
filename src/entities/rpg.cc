#include "../../include/rpg.h"

Rpg::Rpg(Player* jogador){
    window = std::make_shared<RenderWindow>(
        VideoMode(1200, 652),
        "nometemporario",
        Style::Titlebar | Style::Close
    );
    player_class_ = jogador->classe_;
    window->setPosition(Vector2i(0, 0));
    window->setFramerateLimit(100);

    player_sprite= make_shared<Sprite>();
    player_sprite->setTexture(jogador->img_player_texture_);
    player_sprite->setScale(5,5);

    bg.loadFromFile("resources/bgs/bg_temp.png");
    background = make_shared<Sprite>();
    background->setTexture(bg);
    background->setScale(2.35,2.35);
}

void Rpg::Game(){
    SetAnimePlayer();
}

void Rpg::SetAnimeEnemy(){
    
}

void Rpg::SetAnimePlayer(){
    frame += 0.07;
    if(player_class_ == 0){
        player_sprite->setPosition(150,300);
        
        if (frame > 4){
            frame -= 4;
        }

        player_sprite->setTextureRect(IntRect(67*(int)frame,0,67,64));
    }else if(player_class_ == 1){
        player_sprite->setPosition(125,300);    

        if(frame > 8){
            frame -= 8;
        }

        player_sprite->setTextureRect(IntRect(67*(int)frame,0,67,67));
    }else if(player_class_ == 2){
        player_sprite->setPosition(110,300);
        
        if(frame > 6){
            frame -= 6;
        }

        player_sprite->setTextureRect(IntRect(67*(int)frame,0,67,70));
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
    window->draw(*player_sprite);
    window->display();

}

void Rpg::Run() {
    while (window->isOpen()) {
        Events();
        Game();
        Draw();
    }
}