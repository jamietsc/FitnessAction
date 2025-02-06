//
// Created by Admin on 06.02.2025.
//

#include "Fighter.h"

Fighter::Fighter(sf::String name, int gesundheit, int geschwindigkeit, int xPos, int yPos)
    : name(name), gesundheit(gesundheit), geschwindigkeit(geschwindigkeit), xPos(xPos), yPos(yPos)
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

void Fighter::move(int dirX, int dirY) {
    this->xPos += dirX * this->geschwindigkeit;
    this->yPos += dirY * this->geschwindigkeit;
}

