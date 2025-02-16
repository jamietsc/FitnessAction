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
#include "Weapon.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "AudioManager.h"

/**
* @brief Repräsentiert die Kämpfer im Spiel
* @details Die Klassse verwaltet die Eigenschaften der Spieler Charaktere
*/
class Fighter {
public:
    /**
     * @brief Konstruktor der Fighter klasse
     * @details Initialisiert alle Attribute die der Spieler hat
     * @param health Leben des Spielers
     * @param velocity Geschwindigkeit des Spielers
     * @param xPos x-Startpoistion der Spielfigur
     * @param yPos y-Startposition der Spielfigur
     * @param velocityY vertikale Geschwindigkeit
     * @param weapon Waffe des Spielers
     * @param skinPath Speicherpfad der Skintextur des Spielers
     */
    Fighter(int health, int velocity, float xPos, float yPos, float velocityY, Weapon weapon, sf::String skinPath);

    /**
     * @brief Destruktor der Fighter Klasse
     */
    ~Fighter();

    //Funktionen
    /**
     * @brief aktualisiert die Spiel-Logik des Fighters
     * @param deltaTime Zeit seit dem letztem Frame
     */
    void update(float deltaTime);

    /**
     * @brief rendert den fighter im Spielfenster
     * @details zeichnet den Spiel Charakter und die Waffe auf das Render Target
     * @param target fenster auf welchem gezeichnet werden soll
     */
    void render(sf::RenderTarget& target);

    /**
     * @brief prüft ob der Spieler gestorben ist
     * @return ob der Spieler tot ist (bool)
     */
    bool isDead();

    //Bewegung
    /**
     * @brief bewegt die Figur
     * @details die Bewegung ist hierbei unter Berücksichtigung von Reibung und Beschleunigung durchgeführt
     * @param dirX Bewegungsrichtung (-1 = links, 1 = rechts)
     * @param deltaTime Zeit seit dem letztem Frame
     */
    void move(int dirX, float deltaTime);

    /**
     * @brief führt einen Sprung aus
     */
    void jump();

    //Kampf Funktionen
    /**
     * @brief fphrt einen angriff aus
     * @details bei erfolgreichem Angriff werden dem Gegner Lebenspunkte abgezogen
     * @param enemy Gegnerische Figur
     */
    void attack(Fighter& enemy);

    //Getter
    /**
     * @brief gibt die x-Position des Fighters zurück
     * @return aktuelle x-Position (float)
     */
    float getXPos();

    /**
     * @brief gibt die Gesundheit des Fighters zurück
     * @return aktuelle Gesundheit (float)
     */
    int getHealth();

    //setter
    /**
     * @brief setzt die Bodenhöhe
     * @param window Referenz zum Spielfenster um die Bodenposition zu bestimmen
     */
    void setGround(sf::RenderWindow &window);



private:
    // Attribute für Spiellogik
    int health;     /// Aktuelle Lebenspunkte des Spielers
    int velocity;   /// Bewegungsgeschwindigkeit auf der X-Achse
    float xPos, yPos;   /// Aktuelle Position des Spielers
    float velocityY;    /// Vertikale Geschwindigkeit des Spielers

    float velocityX = 0.0f; //aktuelle Bewegungsgeschwindigkeit
    float acceleration = 1.1f; //Beschleunigung des Spielers
    float friction = 0.9f; //Reibung für langsames stoppen
    float ground; //Y-Koordinate des Spielers

    float attackCooldown; //Zeit zwischen zwei Angriffen
    float attackTimer = 0.0f; //Timer für den nächsten Angriff

    //
    //bool isJumping = false;

    sf::RectangleShape shape; //Rechteckige Form des Spielers (für Kollisionsüberprüfung)

    Weapon weapon; //Instanz für die Waffe des Spielers

    //Texturen von Waffe und Spieler
    sf::Texture playerTexture, weaponTexture; //Textur für Spieler und Textur
    sf::Sprite playerSprite, weaponSprite; //Sprite für Spieler und Waffe
    sf::String skinPath; //Pfad der Skin Datei

    //Angriffsound
    AudioManager audioManager; //Spielt Sound Effekt bei erfolgreichem Schlag
};



#endif //FIGHTER_H
