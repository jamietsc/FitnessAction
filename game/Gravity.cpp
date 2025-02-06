//
// Created by Admin on 06.02.2025.
//

#include "Gravity.h"

Gravity::Gravity(float gravityStrength)
    : gravityStrength(gravityStrength) {}

Gravity::~Gravity() {}

float Gravity::calculateVelocity(float currentVelocity, float deltaTime) {
    return currentVelocity + this->gravityStrength * deltaTime;
}

float Gravity::applyGravity(float position, float &velocity, float deltaTime) {
    velocity = this->calculateVelocity(position, deltaTime);
    return position + velocity * deltaTime;
}




