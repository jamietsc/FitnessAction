//
// Created by Admin on 06.02.2025.
//

#include "AI.h"

AI::AI(sf::String name, int health, int velocity, float xPos, float yPos, float velocityY, Gravity gravity,
       Weapon weapon, sf::String skinPath)
    : Fighter(name, health, velocity, xPos, yPos, velocityY, gravity, weapon, skinPath) {
    this->aiTimer = 0.f;
    this->aiState = 0; // 0 = stehen, 1 = Bewegung, 2 = Angreifen
}

void AI::update(float deltaTime, Fighter& player) {
    this->updateAI(deltaTime, player);
    Fighter::update(deltaTime);
}

void AI::updateAI(float deltaTime, Fighter& player) {
    aiTimer += deltaTime;

    //Alle 2 Sekunden neue Aktion wählen
    if (aiTimer >= 2.f) {
        aiTimer = 0.f;

        int randomAction = rand() % 3; // Zufällige Aktion für die oben beschriebenen Zahlen

        switch (randomAction) {
            case 0:
                aiState = 0;
                break;
            case 1:
                aiState = 1;
                break;
            case 2:
                aiState = 2;
                break;
        }
    }


    //Verhalten je nach zustand
    if (aiState == 1) {
        int dir = (rand() % 2 == 0) ? 1 : -1;
        this->move(dir, deltaTime);
    } else if (aiState == 2) {
        //this->attack(player);
    }
}
