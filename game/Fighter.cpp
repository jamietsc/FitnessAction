//
// Created by Admin on 06.02.2025.
//

#include "Fighter.h"

Fighter::Fighter(sf::String name, int health, int velocity, float xPos, float yPos, float velocityY, Gravity gravity, Weapon weapon)
    : name(name), health(health), velocity(velocity), xPos(xPos), yPos(yPos), velocityY(velocityY), gravity(gravity), weapon(weapon)
{

    //Initialisierung der Form
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setFillColor(sf::Color::Blue);
    this->shape.setPosition(this->xPos, this->yPos);


}

Fighter::~Fighter() {
}

void Fighter::update() {

    this->shape.setPosition((this->xPos), (this->yPos));
    //Position der Waffe setzen
    this->weaponSprite.setPosition(this->xPos + 20, this->yPos);
}

void Fighter::render(sf::RenderTarget& target) {
    //zeichnen des Spielers
    target.draw(this->shape);

    //Zeichnen der Waffe
    weapon.render(target, xPos, yPos);
}

void Fighter::move(int dirX, float deltaTime) {
    if (dirX == -1) {
        this->xPos -= (this->velocity * deltaTime) + velocity;
    } else if (dirX == 1) {
        this->xPos = this->xPos + (dirX * this->velocity * deltaTime) + velocity;
    }
}

void Fighter::jump() {

}



