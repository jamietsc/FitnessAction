//
// Created by Admin on 06.02.2025.
//

#include "AI.h"
#include <cmath>

AI::AI(int health, int velocity, float xPos, float yPos, float velocityY,
       Weapon weapon, sf::String skinPath)
    : Fighter(health, velocity, xPos, yPos, velocityY, weapon, skinPath) {
    this->aiTimer = 0.f;
    this->aiState = 0; // 0 = stehen, 1 = Bewegung, 2 = Angreifen, 3 = Ausweichen
}

void AI::update(float deltaTime, Fighter& player) {
    this->updateAI(deltaTime, player);
    Fighter::update(deltaTime);
}

void AI::updateAI(float deltaTime, Fighter& player) {
    aiTimer += deltaTime;

    float distance = std::abs(this->getXPos() - player.getXPos());

    if (aiTimer >= 0.5f) { // Schnellere Entscheidungsfindung
        aiTimer = 0.f;

        if (distance < 50.f) {
            aiState = 3; // Ausweichen
        } else if (distance < 100.f) {
            aiState = (rand() % 2 == 0) ? 2 : 1; // Entweder angreifen oder sich neu positionieren
        } else {
            aiState = 1; // Sich dem Spieler nähern
        }
    }

    // Verhalten je nach Zustand
    switch (aiState) {
        case 1:
            this->move((player.getXPos() > this->getXPos()) ? 1 : -1, deltaTime);
        break;
        case 2:
            if (distance < 80.f) {
                this->attack(player);
            }
        break;
        case 3:
            this->move((rand() % 2 == 0) ? 1 : -1, deltaTime); // Zufällig ausweichen
        break;
        default:
            break;
    }
}

