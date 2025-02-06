//
// Created by Admin on 06.02.2025.
//

#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/String.hpp"
#include "SFML/System/Vector2.hpp"
#include "Fighter.h"

class Fighter {
public:
    Fighter(sf::String name, int gesundheit, int geschwindigkeit, int xPos, int yPos);
    ~Fighter();

    //Funktionen
    void update();
    void render(sf::RenderTarget& target);

    //Bewegung
    void move(int dirX, int dirY);

private:
    sf::String name;
    int gesundheit;
    int geschwindigkeit;
    int xPos, yPos;

    sf::RectangleShape shape;
};



#endif //FIGHTER_H
