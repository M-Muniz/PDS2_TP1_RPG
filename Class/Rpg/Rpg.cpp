#include "Rpg.h"
#include <SFML/Graphics.hpp>

Rpg::Rpg(){
    Window=std::make_shared<sf::RenderWindow>(
        sf::VideoMode(1200,800),
        "nometemporario",
        sf::Style::Titlebar | sf::Style::Close
    );
    Window->setPosition(sf::Vector2i(0,0));
    Window->setFramerateLimit(100);
    bg.loadFromFile("Resources/BG_temp.jpg");

    background =std::make_shared<sf::Sprite>();
    background->setTexture(bg);
}

void Rpg::events(){
    auto Fecha = std::make_shared<sf::Event>();
    while(Window->pollEvent(*Fecha)){
        if(Fecha->type == sf::Event::Closed){
            Window->close();
        }
    }
}

void Rpg::draw(){
    Window->clear(sf::Color::Black);
    Window->draw(*background);
    Window->display();
}

void Rpg::Run(){
    while(Window->isOpen()){
        events();
        draw();
    }
}