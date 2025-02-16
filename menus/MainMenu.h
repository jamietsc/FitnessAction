//
// Created by Admin on 12.02.2025.
//

#ifndef MAINMENU_H
#define MAINMENU_H
#include "../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/RenderWindow.hpp"
#include "../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/Text.hpp"

/**
 * @brief repräsentiert das Hauptmenü des Spiels
 * @details klasse verwaltet die Anzeige und Navigation des Hauptmenüs
 */
class MainMenu {
private:
    sf::Font font;         /// Schriftart für den Menütitel und die Buttons.
    sf::Text title;        /// Titel des Spiels im Hauptmenü.
    sf::Text playButton;   /// Text für den "Spiel starten"-Button.
    sf::Text optionsButton;/// Text für den "Optionen"-Button.
    sf::Text exitButton;   ///  Text für den "Beenden"-Button.

    int selectedItemIndex; //0 = Spiel Starten, 1 = Optionen, 2 = Spiel beenden

public:
    /**
     * @brief Konstruktor für das Hauptmenü
     * @details initialisiert die Schriftarten, Menütexte und platziert sie korrekt im Fenster
     * @param window Referenz auf das Render-Fenster in dem ddas Menü angezeigt wird
     */
    MainMenu(sf::RenderWindow& window);

    /**
     * @brief Render das Menü im Fenster
     * @details zeichnet den Titel und alle Buttons
     * @param window Referenz auf das Render-Fenster
     */
    void render(sf::RenderWindow &window);

    /**
     * @brief verschiebt die Menüauswahl nach oben
     * @details reduziert den "selectedItemIndex" um den vorherigen Menüpunkt auszuwähne
     */
    void moveUp();

    /**
      * @brief verschiebt die Menüauswahl nach unten
      * @details erhöhte den "selectedItemIndex" um den nachfolgenden Menüpunkt auszuwähne
      */
    void moveDown();

    /**
     * @brief gibt den aktuellen ausgewählten Menüpunkt zurück
     * @return  Index des ausgewählten Menüpunkts:
     *          - 0: Spiel starten
     *          - 1: Optionen
     *          - 2: Spiel beenden
     */
    int getSelectedItem();

    /**
     * @brief passt die Position und Größe an die Fenster größe an
     * @details sorgt dafür das das Menü bei größenänderung korrekt an das Fenster angepasst wird
     * @param window
     */
    void resize(sf::RenderWindow& window);
};


#endif //MAINMENU_H
