//
// Created by Admin on 12.02.2025.
//

#ifndef ENDSCREEN_H
#define ENDSCREEN_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"

/**
 * @brief Repräsentiert den Endbildschirm
 */
class EndScreen {
private:
    sf::Font font; //Schrift der Text
    sf::Text title; //Title des Menüs

    sf::Text message; //Nachricht wer das Spiel gewonnen hat

    sf::Text playAgainButton; //Knopf um das Spiel nochmal zu starten
    sf::Text differentCharacters; //Knopf um ins Charakter Menü zu gehen
    sf::Text exitButton; //Knopf um das Spiel zu beenden

    int selectedItemIndex; //0 = Nochmal spielen, 1 = Charakter Auswahl, 2 = Spiel beenden

public:
    /**
     * @brief Konstruktor um Endscreen zu erstellen
     * @param width breite des Endbildschirms
     * @param height höhe des Endbildschirms
     */
    EndScreen(float width, float height);

    /**
     * @brief rendert den Endbilschirm
     * @param window Ziel wo gerendert werden soll
     */
    void render(sf::RenderWindow &window);

    /**
     * @brief Steuerung um einen Menüpunkt nach oben zu gehen
     * @details selectedItemIndex wird um eins nach unten gesetzt
     */
    void moveUp();

    /**
    * @brief Steuerung um einen Menüpunkt nach unten zu gehen
    * @details selectedItemIndex wird um eins nach oben gesetzt
    */
    void moveDown();

    /**
     * @brief aktuell ausgewähltes Element erhalten
     * @return aktuell ausgewähltes Element (int)
     */
    int getSelectedItem();

    //TextFunktionen
    /**
     * @brief zeigt an wer gewonnen hat
     * @details gibt die nachricht aus ob der Spieler oder der Compute gewonnen hat
     * @param winner
     */
    void winnerMessage(int winner); //0 = Spieler hat gewonnen, 1 = Computer hat gewonnen
};


#endif //ENDSCREEN_H
