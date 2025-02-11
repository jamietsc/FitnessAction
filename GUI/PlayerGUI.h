//
// Created by Admin on 11.02.2025.
//

#ifndef PLAYERGUI_H
#define PLAYERGUI_H

#include "../game/Fighter.h"
#include "SFML/Graphics/Font.hpp"

class PlayerGUI {
private:
    Fighter *playerFighter;


    sf::Font font;
    sf::RectangleShape hpBarBackground;
    sf::RectangleShape hpBarInner;

    void initFont();
    void initHPBar(sf::Vector2f position);

public:
    PlayerGUI(Fighter* playerFighter, sf::Vector2f position);
    virtual ~PlayerGUI();

    //Funktionen
    void updateHPBar();
    void update(const float& dt);

    void renderHPBar(sf::RenderTarget &target);
    void render(sf::RenderTarget& target);
};


#endif //PLAYERGUI_H
