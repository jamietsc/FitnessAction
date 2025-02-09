//
// Created by Admin on 06.02.2025.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Fighter.h"
#include "Weapon.h"

/**
 * Klasse welche die Game Engine darstellt
 */
class Game {
public:
    //Konstruktoren und Destruktoren
    Game();
    virtual ~Game();

    //accessors
    const bool isRunning() const;

    //Funktionen
    void updateDt();
    void pollEvents();
    void update();
    void render();


private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    //Hintergrund
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    //Delta time
    sf::Clock dtClock;
    float dt;

    //spieler
    Fighter* player; //zeige auf den Spieler

    //AI
    Fighter* AI; //Zeigt auf die AI

    //Private funktionen
    void initVariables();
    void scaleBackground();
    void initWindow();
    void initPlayer();
    void initAI();


};



#endif //GAME_H
