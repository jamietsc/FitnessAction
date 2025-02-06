#include <SFML/Graphics.hpp>

int main() {
    int posX = 0, posY = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Fitness Action");
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(posX, posY);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    posX = posX + 50;
                }
                if (event.key.code == sf::Keyboard::Left) {
                    posX = posX - 50;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    posY = posY + 50;
                }
                if (event.key.code == sf::Keyboard::Up) {
                    posY = posY - 50;
                }
            }
            shape.setPosition(posX, posY);
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
