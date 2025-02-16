//
// Created by sauser on 13.02.2025.
//

#ifndef FITNESSACTION_CHARACTERMENU_H
#define FITNESSACTION_CHARACTERMENU_H


#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <iostream>
#include "../game/Weapon.h"
#include <SFML/Graphics/Sprite.hpp>

#include "../game/AudioManager.h"

/**
 * @brief Struct zum speichern der Waffenstats
 */
struct weaponStats {
    std::string name;
    int damage;
    float attackSpeed;
};

/**
 * @brief Repräsentiert das Charaktermenü
 */
class CharacterMenu {
private:
    sf::Font font; //Schriftart
    sf::Text title; //Titel der Seite

    /** Erster Spieler **/
    sf::Text firstPlayerText; //Text des Spieler 1
    //Charakter Auswahl
    sf::RectangleShape firstPlayerCharcterBack; //Hintergrund des ersten Spielers
    //Waffenauswahl
    sf::RectangleShape firstPlayerWeaponBack; //Hintergrund der Waffe des ersten Spielers

    /** Zweiter Spieler **/
    sf::Text secondPlayerText; //Text des Spieler 2
    //Charakter Auswahl
    sf::RectangleShape secondPlayerCharacterBack; //Hintergrund des zweiten Spielers
    //Waffenauswahl
    sf::RectangleShape secondPlayerWeaponBack; //Hintergrund der Waffe des zweiten Spielers

    //Pfeile
    sf::Text arrowLeft; //Linker Pfeil welcher angezeigt wird
    sf::Text arrowRight; //Rechter Pfeil welcher angezeigt wird

    int selectedItemFirstCharacter = 0; //dasselbe wie bei Spieler 2 nur für Spieler 1
    int selectedItemFirstWeapon = 0; //dasselbe wie bei Spieler 2 nur für Spieler 1
    int selectedItemSecondCharacter = 0; //dient dazu um bei Spieler zwei den Charakter auszuwählen
    int selectedItemSecondWeapon = 0; //dient dazu um bei Spieler zwei die waffe auszuwählen
    int selectedLayer = 0; //Dient dazu um nach oben und unten zu navigieren


    sf::Text enterButton; //Bestätigen Knopf

    std::vector<sf::Vector2f> arrowLeftPosition; //Positionen des Linken Pfeils
    std::vector<sf::Vector2f> arrowRightPosition; //Position des Rechten Pfeils

    //Pfade zu den Skin Bildern
    std::vector<std::string> skinPaths = {
            "../assets/img/player/spieler_blau.png",
        "../assets/img/player/spieler_gruen.png"
    };

    //Pfade zu den Waffenbildern
    std::vector<std::string> weaponPaths = {
            "../assets/img/weapons/kurzhantel.png",
            "../assets/img/weapons/langhantel_hor.png"
    };

    //Waffenstat
    std::vector<weaponStats> weaponStats = {
        {"Kurzhantel", 10, 2.0}, //Stats für die Kurzhantel
        {"Langhantel", 20, 4.0} //Stats für die Langhantel
    };

    sf::RectangleShape firstWeaponStats, secondWeaponsStats; //Formen für die Waffenstats
    sf::Text firstName, firstDamage, firstAttackSpeed, secondName, secondDamage, secondAttackSpeed; //Text für die Waffenstats

    //Waffenobjekte um diese ins Game zu laden
    Weapon* firstPlayerWeapon;
    Weapon* secondPlayerWeapon;

    //Texturen von Waffe und Spieler
    sf::Texture firstPlayerTexture, secondPlayerTexture, firstWeaponTexture, secondWeaponTexture;
    sf::Sprite firstPlayerSprite, firstWeaponSprite, secondPlayerSprite, secondWeaponSprite;

    /**
     * @brief anzeigen der Waffenstats
     * @details wird aktualisiert wenn sich die Ebene ändert
     */
    void showNewStats();
public:
    /**
     * @brief Konstruktor für das Charaktermenü
     * @param window wird für die Objektplatzierung genutzt
     */
    CharacterMenu(sf::RenderWindow &window);

    /**
     * @brief rendern der Objekte
     * @param window Ziel wo gerendert werden soll
     */
    void render(sf::RenderWindow &window);

    /**
     * @brief um die Ebenen im Charaktermneü zu wechseln
     * @details selecteLayer wird verringert im Menü geht es eins nach oben
     */
    void moveUp();

    /**
    * @brief um die Ebenen im Charaktermneü zu wechseln
    * @details selecteLayer wird erhöht im Menü geht es eins nach oben
    */
    void moveDown();

    /**
     * @brief um Charakter oder Waffe zu wechseln
     */
    void moveLeft();

    /**
     * @brief um Charakter oder Waffe zu wechseln
     */
    void moveRight();

    /**
     * @brief anpassen ans Fenster
     * @details Funktion wird genutzt um die Elemente relaitv zum Fenster zu platzieren
     * @param window
     */
    void resize(sf::RenderWindow &window);

    /**
     * @brief Charakter für Spieler 1
     * @return gibt den Pfad des ausgewählten Charakters für Spieler 1 zurück (std::string)
     */
    std::string getSelectedFirstCharacter();

    /**
     * @brief Waffe für Spieler 1
     * @return gibt den Pfad der ausgewählten Waffe für Spieler 1 zurück (std::string)
     */
    std::string getSelectedFirstWeapon();

    /**
     * @brief Charakter für Spieler 2
     * @return gibt den ausgewählten Pfad des Charakters für Spieler 2 zurück (std::string)
     */
    std::string getSelectedSecondCharacter();

    /**
    * @brief Charakter für Spieler 1
    * @return gibt den Pfad für die ausgewählte Waffe für Spieler 2 zurück (std::string)
    */
    std::string getSelectedSecondWeapon();

    /**
     * @brief gibt aktuell ausgewähltes Layer zurück
     * @details das Layer stellt dabei dar in welchem auswahlpunkt der Spieler ist:
     *      - 0: Charakter Spieler 1
     *      - 1: Waffe Spieler 1
     *      - 2: Charakter Spieler 2
     *      - 3: Waffe Spieler 2
     *      - 4: Enter Button
     * @return aktuell ausgewälhtes Layer (int)
     */
    int getSelectedLayer();

    //Instanz für die Waffen des Spielers und Computers
    Weapon* getFirstWeapon();
    Weapon* getSecondWeapon();
};


#endif //FITNESSACTION_CHARACTERMENU_H
