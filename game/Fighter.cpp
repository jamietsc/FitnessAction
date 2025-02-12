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

    this->attackCooldown = weapon.getAttackSpeed();
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

    this->attackTimer += deltaTime; // Angriffstimer weiter hochzählen

    if (this->attackTimer > this->attackCooldown) {
        this->attackTimer = this->attackCooldown; // Begrenzen, aber nicht zurücksetzen!
    }
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
    float maxSpeed = 5.0f; //maximale Geschwindigkeit

    if (dirX != 0) {
        if ((dirX > 0 && velocityX < 0) || (dirX < 0 && velocityX > 0)) {
            velocityX = 0; //Geschwindigkeit nach Richtungswechsel zurücksetzen
        }

        //Beschleunigung
        velocityX += dirX * acceleration * deltaTime * 60;

        //Geschwindigkeit auf maxSpeed begrenzen
        if (velocityX > maxSpeed) {
            velocityX = maxSpeed;
        }
        if (velocityX < -maxSpeed) {
            velocityX = -maxSpeed;
        }
    } else {
        //Falls keine Taste gedrückt wird, langsames abbremsen
        velocityX *= friction;

        if (std::abs(velocityX) < 0.1f) {
            velocityX = 0;
        }
    }

    xPos += velocityX * deltaTime * 60;

    //Begrenzung für den Spieler um im Bild zu bleiben
    xPos = std::clamp(xPos, 0.0f, 800.f - shape.getSize().x);

    //Position aktualisieren
    shape.setPosition(this->xPos, this->yPos);
    playerSprite.setPosition(this->xPos, this->yPos);
    weaponSprite.setPosition(this->xPos + 20, this->yPos + 20);
}

void Fighter::jump() {
    if (this->yPos == groundYCor) {
        this->velocityY = -10.0f;  // Negative Geschwindigkeit für Sprung
        this->yPos += this->velocityY;
    }
}

void Fighter::attack(Fighter &enemy) {
    //Zahlen anpassen um die Hitbox einzustellen
    if (this->xPos + 80 >= enemy.xPos && this->xPos - 80 <= enemy.xPos) {
        if (this->attackTimer >= this->attackCooldown) { // Attacke nur ausführen, wenn Cooldown vorbei ist
            enemy.health -= this->weapon.getDamage();
            this->attackTimer = 0; // Timer hier zurücksetzen
        }
    }
}

float Fighter::getXPos() {
    return this->xPos;
}

int Fighter::getHealth() {
    return this->health;
}
