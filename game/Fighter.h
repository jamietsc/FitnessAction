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
#include "Weapon.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Fighter {
public:
    Fighter(sf::String name, int health, int velocity, float xPos, float yPos, float velocityY, Gravity gravity, Weapon weapon);
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
    float xPos, yPos;
    float velocityY;

    sf::RectangleShape shape;

    Gravity gravity; //Instanz der Gravitation
    Weapon weapon; //Instanz für die Waffe des Spielers

    //Texturen von Waffe und Spieler
    sf::Texture playerTexture, weaponTexture;
    sf::Sprite playerSprite, weaponSprite;
};



#endif //FIGHTER_H
