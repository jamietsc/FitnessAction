//
// Created by Admin on 15.02.2025.
//

#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

/**
 * @brief zum verwalten der Hintergrundmusik im Spiel
 * @details Die Klasse lädt Sounddateien und spielt diese dann ab
 */
class AudioManager {
public:
    /**
     * @brief konstruktor für den Audiomanager
     * @details lädt alle benötigten Sounddateien und bereit sie auf die Wiedergabe vor
     */
    AudioManager();

    /**
     * @brief für Klick-Sound im Menü
     * @details wird beim navigieren durch eines der Menüs verwendet
     */
    void playMenuClick();

    /**
     * @brief für Angriffs-Sound im Game
     * @details wird während eines Angriffs abgespielt
     */
    void playAttackSound();

    /**
     * @brief für die Hintergrund Musik im Spiel
     * @details wird während des kompletten Spiels abgespielt
     */
    void playBackgroundMusic();

    /**
     * @brief Stoppt die Hintergrundmusik
     * @details beendet die aktuell laufende Hintergrundmusik
     */
    void stopBackgroundMusic();

    /**
     * @brief Stoppt den Angriffssound
     * @details Beendet den aktuellen Angriff-Soundeffekt
     */
    void stopAttackSound();

private:
    sf::SoundBuffer clickBuffer;  /// Puffer für den Menü-Klick-Sound.
    sf::SoundBuffer attackBuffer; /// Puffer für den Angriff-Sound.

    sf::Sound clickSound;         /// Soundobjekt für den Menü-Klick.
    sf::Sound attackSound;        /// Soundobjekt für den Angriff.

    sf::Music backgroundMusic;    /// Hintergrundmusikobjekt.
};



#endif //AUDIOMANAGER_H
