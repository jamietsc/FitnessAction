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
 * @brief Klasse welche die Game Engine darstellt
 */
class Game {
public:
    //Konstruktoren und Destruktoren
    /**
     * @brief Konstruktor der Game Klasse
     * @details Initialisiert das Game
     */
    Game();

    /**
     * @brief Destruktor der Game Klasse
     */
    virtual ~Game();

    //accessors
    /**
     * @brief prüft ob das Spiel aktuell läuft
     * @return ob das Spiel läuft (bool)
     */
    const bool isRunning() const;

    //Funktionen
    /**
     * @brief Funktion zum updaten der DeltaTime
     * @details updatet die zeit welche pro Frame vergeht
     */
    void updateDt();

    /**
     * @brief für Steuerung
     * @details Funktion überprüft die Eingaben des Spielers
     */
    void pollEvents();

    /**
     * @brief updatet die gerenderten Inhalte
     */
    void update();

    /**
     * @brief rendert alle Inhalte
     */
    void render();

    /**
     * @brief Funktion um das Spiel neu zu starten
     */
    void restartGame();

    /**
     * @brief Funktion um wieder zurück ins Charakter Menü zu gehen
     */
    void goIntoCharacterMenu();


private:
    //Variables
    //Window
    sf::RenderWindow* window; //Instanz für das Window
    sf::VideoMode videoMode; //Videomode um attribute festzulegen
    sf::Event event;//event um Eingaben entgegen zu nehmen

    //Hintergrund
    sf::Texture backgroundTexture; //Textur für den Hintergrund
    sf::Sprite backgroundSprite; //Sprite für den Hintergrund

    //Delta time
    sf::Clock dtClock; //Clock um die DeltaTime zu messen
    float dt; //Zeit welche zwischen zwei Frames vergeht

    //spieler
    Fighter* player; //zeige auf den Spieler
    Weapon* playerWeapon; //Zeige auf die Waffe des Spielers
    PlayerGUI* playerGUI; //Zeige auf playerGui

    //AI
    AI* ai; //Zeigt auf die AI
    Weapon* aiWeapon; //Zeige auf die Waffe der AI
    PlayerGUI* aiGUI; //Zeigt auf aiGUI

    //Main Menu
    MainMenu* mainMenu; //Instanz auf Main Menu
    bool inMenu = true; //Spiel immer im Hauptmenü starten

    //Character Auswahl
    CharacterMenu* characterMenu; //Instanz auf das Character Menü
    bool inCharacterMenu = false; //wird auf true gesetzt wenn das charactermenu geöffnet wird

    //Variable ob das Spiel aktiv ist
    bool inGame = false;

    //End Bildschirm
    EndScreen* endScreen; //Instanz auf den Endbildschirm
    bool inEndScreen = false; //wird auf true gesetzt wenn der Endscreen geöffnet wird

    //Audio Manager für die Sounds
    AudioManager audioManager; //audio manager um HIntergrundmusik abzuspielen

    //Variable für Fullscreen
    bool isFullScreen = false; //wird auf true gesetzt wenn Fullscreen aktiv

    //Private funktionen
    /**
     * @brief Funktion zum initialisieren der Variabeln
     * @details Variablen werden alle auf nullptr gesetzt um Speicherlecks zu vermeidne
     */
    void initVariables();

    /**
     * @brief skaliert den Hintergrund auf Fenstergröße
     */
    void scaleBackground();

    /**
     * @brief initialisiert das Fenster
     */
    void initWindow();

    /**
     * @brief initialisiert den Spieler
     * @details erstellt die Spieler Instanz
     */
    void initPlayer();

    /**
     * @brief initialisiert den Computer
     * @details erstellt die Computer Instanz
     */
    void initAI();

    /**
     * @brief initialisiert das Hauptmenü
     */
    void initMainMenu();

    /**
     * @brief initialisiert das Charakter Menü
     */
    void initCharacterMenu();

    /**
     * @brief initialisiert den Endbildschirm
     */
    void initEndScreen();

    /**
     * @brief resized das Spiel
     * @details sorgt dafür das alle Elemente an die Fenstergröße angepasst werden
     */
    void resizeGame();


};



#endif //GAME_H
