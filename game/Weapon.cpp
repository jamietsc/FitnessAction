//
// Created by Admin on 06.02.2025.
//

#include "Weapon.h"

#include <iostream>
#include <ostream>

#include "SFML/Graphics/RenderTarget.hpp"

Weapon::Weapon(const sf::String &name, int damage, float attackSpeed, const sf::String weaponTexture)
    : name(name), damage(damage), attackSpeed(attackSpeed){
    if (!this->weaponTexture.loadFromFile(weaponTexture)) {
        std::cerr << "error while loading the weapon image" << std::endl;
    }
    this->weaponSprite.setTexture(this->weaponTexture);
}

void Weapon::use() {

}

void Weapon::render(sf::RenderTarget &target, float xPosPlayer, float yPosPlayer) {
    this->weaponSprite.setPosition(xPosPlayer + 20, yPosPlayer);
    target.draw(this->weaponSprite);
}

int Weapon::getDamage() {
    return this->damage;
}

float Weapon::getAttackSpeed() {
    return this->attackSpeed;
}
