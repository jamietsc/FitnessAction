//
// Created by Admin on 06.02.2025.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Fighter.h"
#include "AI.h"
#include "../GUI/PlayerGUI.h"
#include "../GUI/MainMenu.h"

class MainMenu;
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
    PlayerGUI* playerGUI; //Zeige auf playerGui

    //AI
    AI* ai; //Zeigt auf die AI
    PlayerGUI* aiGUI; //Zeigt auf aiGUI

    //Main Menu
    MainMenu* mainMenu;
    bool inMenu = false;

    //Private funktionen
    void initVariables();
    void scaleBackground();
    void initWindow();
    void initPlayer();
    void initAI();
    void initMainMenu();


};



#endif //GAME_H
