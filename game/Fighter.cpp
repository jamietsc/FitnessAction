//
// Created by Admin on 06.02.2025.
//

#include "Fighter.h"

const float groundYCor = 500.0f;

Fighter::Fighter(sf::String name, int health, int velocity, float xPos, float yPos, float velocityY, Gravity gravity,
                 Weapon weapon, sf::String skinPath)
    : name(name), health(health), velocity(velocity), xPos(xPos), yPos(yPos), velocityY(velocityY), gravity(gravity),
      weapon(weapon), skinPath(skinPath) {
    //Initialisierung der Form
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setFillColor(sf::Color::Transparent);
    this->shape.setPosition(this->xPos, this->yPos);

    if (!this->playerTexture.loadFromFile(skinPath)) {
        std::cerr << "Error loading skin texture" << std::endl;
    }
    this->playerSprite.setTexture(this->playerTexture);
}

Fighter::~Fighter() {
}

void Fighter::update(float deltaTime) {
    // Schwerkraft anwenden
    if (this->yPos < groundYCor) {
        this->velocityY += 0.5f * deltaTime * 60;
        this->yPos += this->velocityY * deltaTime * 60;
    } else {
        this->yPos = groundYCor;  // Auf dem Boden bleiben
        this->velocityY = 0;      // Geschwindigkeit zurücksetzen
    }

    // Aktualisiere Position
    this->shape.setPosition(this->xPos, this->yPos);
    this->playerSprite.setPosition(this->xPos, this->yPos);
    this->weaponSprite.setPosition(this->xPos + 20, this->yPos + 20);
}

void Fighter::render(sf::RenderTarget &target) {
    //zeichnen des Spielers
    target.draw(this->shape);
    target.draw(this->playerSprite);

    //Zeichnen der Waffe
    weapon.render(target, xPos, yPos + 10);
}

bool Fighter::isDead() {
    if (this->health <= 0) {
        return true;
    } else {
        return false;
    }
}

void Fighter::move(int dirX, float deltaTime) {
    if (dirX == -1) {
        this->xPos -= (this->velocity * deltaTime) + velocity;
    } else if (dirX == 1) {
        this->xPos = this->xPos + (dirX * this->velocity * deltaTime) + velocity;
    }
}

void Fighter::jump() {
    if (this->yPos == groundYCor) {
        this->velocityY = -10.0f;  // Negative Geschwindigkeit für Sprung
        this->yPos += this->velocityY;
    }
}

void Fighter::attack(Fighter &enemy) {
    std::cout << "Spieler Gesundheit: " << this->health << std::endl;
    std::cout << "Gegner Gesundheit: " << enemy.health << std::endl;
    //Zahlen anpassen um die Hitbox einzustellen
    if (this->xPos + 60 >= enemy.xPos && this->xPos - 60 <= enemy.xPos) {
        enemy.health -= this->weapon.getDamage();
    } else {
        std::cerr << "Gegner war nicht in der nähe" << std::endl;
    }
}

float Fighter::getXPos() {
    return this->xPos;
}
