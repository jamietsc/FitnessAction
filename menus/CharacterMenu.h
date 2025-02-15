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

struct weaponStats {
    std::string name;
    int damage;
    float attackSpeed;
};

class CharacterMenu {
private:
    sf::Font font;
    sf::Text title;

    /** Erster Spieler **/
    sf::Text firstPlayerText;
    //Charakter Auswahl
    sf::RectangleShape firstPlayerCharcterBack;
    //Waffenauswahl
    sf::RectangleShape firstPlayerWeaponBack;

    /** Zweiter Spieler **/
    sf::Text secondPlayerText;
    //Charakter Auswahl
    sf::RectangleShape secondPlayerCharacterBack;
    //Waffenauswahl
    sf::RectangleShape secondPlayerWeaponBack;

    //Pfeile
    sf::Text arrowLeft;
    sf::Text arrowRight;

    int selectedItemFirstCharacter = 0; //dasselbe wie bei Spieler 2 nur für Spieler 1
    int selectedItemFirstWeapon = 0; //dasselbe wie bei Spieler 2 nur für Spieler 1
    int selectedItemSecondCharacter = 0; //dient dazu um bei Spieler zwei den Charakter auszuwählen
    int selectedItemSecondWeapon = 0; //dient dazu um bei Spieler zwei die waffe auszuwählen
    int selectedLayer = 0; //Dient dazu um nach oben und unten zu navigieren


    sf::Text enterButton;

    std::vector<sf::Vector2f> arrowLeftPosition;
    std::vector<sf::Vector2f> arrowRightPosition;

    std::vector<std::string> skinPaths = {
            "../assets/img/player/spieler_blau.png",
        "../assets/img/player/spieler_gruen.png"
    };

    std::vector<std::string> weaponPaths = {
            "../assets/img/weapons/kurzhantel.png",
            "../assets/img/weapons/langhantel_hor.png"
    };

    std::vector<weaponStats> weaponStats = {
        {"Kurzhantel", 10, 2.0}, //Stats für die Kurzhantel
        {"Langhantel", 20, 4.0} //Stats für die Langhantel
    };

    sf::RectangleShape firstWeaponStats, secondWeaponsStats;
    sf::Text firstName, firstDamage, firstAttackSpeed, secondName, secondDamage, secondAttackSpeed;

    //Waffenobjekte um diese ins Game zu laden
    Weapon* firstPlayerWeapon;
    Weapon* secondPlayerWeapon;

    //Texturen von Waffe und Spieler
    sf::Texture firstPlayerTexture, secondPlayerTexture, firstWeaponTexture, secondWeaponTexture;
    sf::Sprite firstPlayerSprite, firstWeaponSprite, secondPlayerSprite, secondWeaponSprite;

    void showNewStats();
public:
    CharacterMenu(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void resize(sf::RenderWindow &window);

    std::string getSelectedFirstCharacter();
    std::string getSelectedFirstWeapon();
    std::string getSelectedSecondCharacter();
    std::string getSelectedSecondWeapon();
    int getSelectedLayer();

    Weapon* getFirstWeapon();
    Weapon* getSecondWeapon();
};


#endif //FITNESSACTION_CHARACTERMENU_H
