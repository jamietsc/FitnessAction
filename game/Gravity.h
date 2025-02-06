//
// Created by Admin on 06.02.2025.
//

#ifndef GRAVITY_H
#define GRAVITY_H



class Gravity {
private:
    float gravityStrength; //Gravitationsstärke
public:
    Gravity(float gravityStrength = 9.8f); //Standardwert für Gravitation auf der Erde
    ~Gravity();

    //Berechnet die Geschwindigkeit basierend auf der Gravitation
    float calculateVelocity(float currentVelocity, float deltaTime);

    //Aktualisiert die Position basierend auf Geschwindigkeit
    float applyGravity(float position, float& velocity, float deltaTime);
};



#endif //GRAVITY_H
