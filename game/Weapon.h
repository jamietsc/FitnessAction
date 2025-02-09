//
// Created by Admin on 06.02.2025.
//

#ifndef WEAPON_H
#define WEAPON_H
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/String.hpp"


class Weapon {
public:
    Weapon(const sf::String& name, int damage, float attackSpeed, const sf::String weaponTexture);

    void use();
    void render(sf::RenderTarget& target, float xPosPlayer, float yPosPlayer);

private:
    sf::String name;
    int damage;
    float attackSpeed;
    sf::Texture weaponTexture;
    sf::Sprite weaponSprite;

};



#endif //WEAPON_H
