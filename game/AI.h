//
// Created by Admin on 06.02.2025.
//

#ifndef AI_H
#define AI_H

#include "Fighter.h"

class AI : public Fighter {
private:
    float aiTimer; //Timer für KI Entscheidungen
    int aiState; //Zustand der KI (z.B. 0 = ruhig, 1 = Angriff)

    void updateAI(float dt); //Logik für das verhalten des Gegners

public:
    AI(sf::String name, int health, int velocity, float xPos, float yPos, float velocityY, Gravity gravity, Weapon weapon, sf::String skinPath);
    void update(float dt);
};

#endif //AI_H
