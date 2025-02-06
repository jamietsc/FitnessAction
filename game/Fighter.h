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
#include "Gravity.h"

class Fighter {
public:
    Fighter(sf::String name, int health, int velocity, int xPos, int yPos, float velocityY, Gravity gravity);
    ~Fighter();

    //Funktionen
    void update();
    void render(sf::RenderTarget& target);

    //Bewegung
    void move(int dirX, float deltaTime);
    void jump();

private:
    sf::String name;
    int health;
    int velocity;
    int xPos, yPos;
    float velocityY;

    sf::RectangleShape shape;

    Gravity gravity; //Instanz der Gravitation
};



#endif //FIGHTER_H
