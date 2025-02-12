//
// Created by Admin on 12.02.2025.
//

#ifndef ENDSCREEN_H
#define ENDSCREEN_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"


class EndScreen {
private:
    sf::Font font;
    sf::Text title;
    sf::Text playAgainButton;
    sf::Text differentCharacters;
    sf::Text exitButton;

    int selectedItemIndex; //0 = Nochmal spielen, 1 = Charakter Auswahl, 2 = Spiel beenden

public:
    EndScreen(float width, float height);
    void render(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getSelectedItem();
};



#endif //ENDSCREEN_H
