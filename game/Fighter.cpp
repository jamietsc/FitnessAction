//
// Created by Admin on 06.02.2025.
//

#include "Fighter.h"

Fighter::Fighter(sf::String name, int health, int velocity, int xPos, int yPos, float velocityY, Gravity gravity)
    : name(name), health(health), velocity(velocity), xPos(xPos), yPos(yPos), velocityY(velocityY), gravity(gravity)
{
    //Initialisierung der Form
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setFillColor(sf::Color::Blue);
    this->shape.setPosition(this->xPos, this->yPos);
}

Fighter::~Fighter() {
}

void Fighter::update() {
    this->shape.setPosition(static_cast<float>(this->xPos), static_cast<float>(this->yPos));
}

void Fighter::render(sf::RenderTarget& target) {
    //zeichnen des Spielers
    target.draw(this->shape);
}

void Fighter::move(int dirX, float deltaTime) {
    this->xPos += dirX * this->velocity * deltaTime;
}

void Fighter::jump() {

}

