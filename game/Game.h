//
// Created by Admin on 06.02.2025.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Fighter.h"
#include "AI.h"
#include "../menus/EndScreen.h"
#include "../GUI/PlayerGUI.h"
#include "../menus/MainMenu.h"
#include "../menus/CharacterMenu.h"

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
    void restartGame();
    void goIntoCharacterMenu();


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
    Weapon* playerWeapon; //Zeige auf die Waffe des Spielers
    PlayerGUI* playerGUI; //Zeige auf playerGui

    //AI
    AI* ai; //Zeigt auf die AI
    Weapon* aiWeapon; //Zeige auf die Waffe der AI
    PlayerGUI* aiGUI; //Zeigt auf aiGUI

    //Main Menu
    MainMenu* mainMenu;
    bool inMenu = true;

    //Character Auswahl
    CharacterMenu* characterMenu;
    bool inCharacterMenu = false;

    //Variable ob das Spiel aktiv ist
    bool inGame = false;

    //End Bildschirm
    EndScreen* endScreen;
    bool inEndScreen = false;

    //Audio Manager für die Sounds
    AudioManager audioManager;

    //Variable für Fullscreen
    bool isFullScreen = false;

    //Private funktionen
    void initVariables();
    void scaleBackground();
    void initWindow();
    void initPlayer();
    void initAI();
    void initMainMenu();
    void initCharacterMenu();
    void initEndScreen();

    void resizeGame();


};



#endif //GAME_H
