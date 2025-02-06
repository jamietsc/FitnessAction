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

    //Delta time
    sf::Clock dtClock;
    float dt;

    //spieler
    Fighter* player; //zeige auf den Spieler

    //Private funktionen
    void initVariables();
    void initWindow();
    void initPlayer();


};



#endif //GAME_H
