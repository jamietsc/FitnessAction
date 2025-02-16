//
// Created by Admin on 06.02.2025.
//

#ifndef WEAPON_H
#define WEAPON_H
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/String.hpp"

/**
 * @brief Repräsentiert die Klasse fpr die Waffen im Spiel
 * @details die Klasse speichert Eigenschaften der Waffe aus dem Spiel
 */
class Weapon {
public:
    /**
     * @brief Konstruktor für die Weapon Klasse
     * @details initialisiert eine Waffe mit den nachfolgenden Paramtern
     * @param name name der Waffe im Spiel
     * @param damage schaden der Waffe im Spiel
     * @param attackSpeed angriffsgeschwindigkeit der Waffe im Spiel
     * @param weaponTexture Waffentextur der Waffe
     */
    Weapon(std::string name, int damage, float attackSpeed, const sf::String weaponTexture);

    /**
     * @brief rendert die Waffe auf dem Bildschirm
     * @details Zeichnet die WAffe an die Position des Spielers 
     * @param target das fenster in welchem gerendet werden soll
     * @param xPosPlayer x Position des Spielers 
     * @param yPosPlayer y Position des Spielers 
     */
    void render(sf::RenderTarget& target, float xPosPlayer, float yPosPlayer);

    //Getter
    /**
     * @brief Gibt den Schaden der Waffe zurück
     * @return den Schaden (int), den die Waffe verursacht
     */
    int getDamage();

    /**
     * @brief gibt die Angriffschgeschwindigkeit der Waffe zurück
     * @return die Angriffsgeschwindigkeit (float) welche die Waffe hat
     */
    float getAttackSpeed();

private:
    std::string name; ///Name der Waffe
    int damage; /// Schaden der Waffe
    float attackSpeed; ///Angriffsgeschwindigkeit der Waffe
    sf::Texture weaponTexture; //Waffentextur
    sf::Sprite weaponSprite; //Sprite der Waffe welche dann zum Rendern verwendet wird

};



#endif //WEAPON_H
