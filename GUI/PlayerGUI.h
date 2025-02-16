//
// Created by Admin on 11.02.2025.
//

#ifndef PLAYERGUI_H
#define PLAYERGUI_H

#include "../game/Fighter.h"
#include "SFML/Graphics/Font.hpp"

/**
 * @brief Verwaltet die Benutzeroberläche (GUI) für den Spieler
 * @details die Klasse ist für die HP des Spielers zuständig
 */
class PlayerGUI {
private:
    Fighter *playerFighter; ///Zeiger auf den Charakter um die HP für ihn anzeigen zu lassen


    sf::Font font; ///Schriftart für die GUI
    sf::RectangleShape hpBarBackground; ///Hintergrund für die HP Leister
    sf::RectangleShape hpBarInner; ///Innere der HP Leiste um die aktuellen Gesundheitszustand anzeigen zu lassen

    /**
     * @brief initialisiert die Font
     * @details lädt die Schriftart aus einer Datei und stellt sie bereit
     */
    void initFont();

    /**
     * @brief initialisiert die HP Leiste
     * @details erstellt den HIntergrund und Vordergrundbalken für die HP-Leiste
     * @param position die Position an der die HP Leiste angezeigt werden soll
     */
    void initHPBar(sf::Vector2f position);

public:
    /**
     * @brief Konstruktor der PlayerGUI
     * @details initialisiert die GUI mit dem übergeben Spielercharacter
     * @param playerFighter Zeiger auf das Spielerobjekt Fighter
     * @param position Position an der die HP-Leiste angezeigt wirdd
     */
    PlayerGUI(Fighter* playerFighter, sf::Vector2f position);

    /**
     * @brief Destruktor der PlayerGUI
     * @details führt die Aufräumarbeiten durch
     */
    virtual ~PlayerGUI();

    //Funktionen
    /**
     * @rief aktualisiert die HP Leiste
     * @details passt die Länger der HP bar an den Spieler an
     */
    void updateHPBar();

    /**
     * @brief aktualisiert die GUI-Elemente
     * @details wird einmal pro Frame aufgerufen
     * @param dt  deltaTime zur Aktualisierung pro Frame
     */
    void update(const float& dt);

    /**
     * @brief rendert die HP-Bar
     * @details zeichnet die HP-Leiste
     * @param target Ziel auf das die HP Leiste angezeigt wird
     */
    void renderHPBar(sf::RenderTarget &target);

    /**
     * @brief rendert die gesamte gui
     * @details zeichnet alle GUI Elemente auf das angegebene Render-Target
     * @param target Ziel auf das die GUI-Elemente gezeichnet werden sollen
     */
    void render(sf::RenderTarget& target);
};


#endif //PLAYERGUI_H
