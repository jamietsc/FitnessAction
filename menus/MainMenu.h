//
// Created by Admin on 12.02.2025.
//

#ifndef MAINMENU_H
#define MAINMENU_H
#include "../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/RenderWindow.hpp"
#include "../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/Text.hpp"


class MainMenu {
private:
    sf::Font font;
    sf::Text title;
    sf::Text playButton;
    sf::Text optionsButton;
    sf::Text exitButton;

    int selectedItemIndex; //0 = Spiel Starten, 1 = Optionen, 2 = Spiel beenden

public:
    MainMenu(sf::RenderWindow& window);
    void render(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getSelectedItem();
    void resize(sf::RenderWindow& window);
};


#endif //MAINMENU_H
