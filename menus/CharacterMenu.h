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
#include <SFML/Graphics/Sprite.hpp>

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
    //Charakter Auswahl f
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
            "../img/player/spieler_blau.png",
        "../img/player/spieler_gruen.png"
    };

    std::vector<std::string> weaponPaths = {
            "../img/weapons/kurzhantel.png",
            "../img/weapons/langhantel_hor.png"
    };

    //Texturen von Waffe und Spieler
    sf::Texture firstPlayerTexture, secondPlayerTexture, firstWeaponTexture, secondWeaponTexture;
    sf::Sprite firstPlayerSprite, firstWeaponSprite, secondPlayerSprite, secondWeaponSprite;
public:
    CharacterMenu(float width, float height);
    void render(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    std::string getSelectedFirstCharacter();
    std::string getSelectedFirstWeapon();
    std::string getSelectedSecondCharacter();
    std::string getSelectedSecondWeapon();
    int getSelectedLayer();
};


#endif //FITNESSACTION_CHARACTERMENU_H
