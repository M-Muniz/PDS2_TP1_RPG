#include "../../include/rpg.h"

Rpg::Rpg() {
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(1200, 800),
        "nometemporario",
        sf::Style::Titlebar | sf::Style::Close
    );
    window->setPosition(sf::Vector2i(0, 20));
    window->setFramerateLimit(100);
    bg.loadFromFile("resources/bg_temp.jpg");

    background = std::make_shared<sf::Sprite>();
    background->setTexture(bg);
}

void Rpg::Events() {
    auto event = std::make_shared<sf::Event>();
    while (window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed) {
            window->close();
        }
    }
}

void Rpg::Draw() {
    window->clear(sf::Color::Black);
    window->draw(*background);
    window->display();
}

void Rpg::Run() {
    while (window->isOpen()) {
        Events();
        Draw();
    }
}
