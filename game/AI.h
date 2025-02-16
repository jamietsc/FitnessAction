//
// Created by Admin on 06.02.2025.
//

#ifndef AI_H
#define AI_H

#include "Fighter.h"

/**
 * @brief Repräsentiert den Computer im Spiel
 * @details Erweitert die Klasse Fighter um eine eigene Entscheidungslogik für den Computer einzubauen
 */
class AI : public Fighter {
private:
    /**
     * @brief Stellt den Timer für die Entscheidungen der KI dar
     * @details Variable um die Entscheidungszeit des Computers festzulegen
     */
    float aiTimer;

    /**
     * @brief Stellt den Zustand des Computers dar
     * @details 0 = ruhig, 1 = Bewegen, 2 = Angreifen
     */
    int aiState;

    /**
     * @brief updatet den Computer
     * @details hier werden die Entscheidungen per Zufall getroffen und ausgeführt
     * @param dt DeltaTime um den aiTimer festzulegen und die Zeit zu überprüfen
     * @param player Spieler Variable für die Angriffsmethode
     */
    void updateAI(float dt, Fighter& player);



public:
    /**
     * @brief Konstruktor für den Computer
     * @details Erstellt den Computer mit den selben Argumenten welche der Spieler hat
     * @param health Leben des Comptuers
     * @param velocity Geschwindigkeit des Computers
     * @param xPos xPosition des Computers
     * @param yPos yPosition des Computers
     * @param velocityY vertikale Geschwindigkeit des Computers
     * @param weapon Waffe des Computers
     * @param skinPath Pfad des Skins des Computers
     */
    AI(int health, int velocity, float xPos, float yPos, float velocityY, Weapon weapon, sf::String skinPath);

    /**
     * @brief Methode zum Updaten des aiTimerss
     * @details updatet den aiTimer welcher festlegt wann die nächste Entscheidung getroffen wird
     * @param dt deltaTime welche die vergangene Zeit zwischen zwei Frames darstellt
     * @param player Fighter Objekt da die klasse AI Fighter erweitert
     */
    void update(float dt, Fighter& player);
};

#endif //AI_H
