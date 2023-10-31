#include "../../include/rpg.h"

Rpg::Rpg(Player jogador) {
    window = std::make_shared<RenderWindow>(
        VideoMode(1200, 800),
        "nometemporario",
        Style::Titlebar | Style::Close
    );
    window->setPosition(Vector2i(0, 0));
    window->setFramerateLimit(100);
    bg.loadFromFile("resources/bg_temp.jpg");

    background = make_shared<Sprite>();
    background->setTexture(bg);
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
    window->display();
}

void Rpg::Run() {
    while (window->isOpen()) {
        Events();
        Draw();
    }
}
