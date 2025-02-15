//
// Created by Admin on 11.02.2025.
//

#include "PlayerGUI.h"

void PlayerGUI::initFont() {
    this->font.loadFromFile("../assets/fonts/STENCIL.TTF");
}

void PlayerGUI::initHPBar(sf::Vector2f position) {
    this->hpBarBackground.setSize(sf::Vector2f(160.0f, 30.0f));
    this->hpBarBackground.setFillColor(sf::Color(50, 50, 50, 200));
    this->hpBarBackground.setPosition(position.x, position.y);

    this->hpBarInner.setSize(sf::Vector2f(140.0f, 20.0f));
    this->hpBarInner.setFillColor(sf::Color(20, 200, 20, 200));
    this->hpBarInner.setPosition(position.x + 10, position.y + 5);
}

PlayerGUI::PlayerGUI(Fighter *playerFighter, sf::Vector2f position) {
    this->playerFighter = playerFighter;

    this->initHPBar(position);
    this->initFont();
}

PlayerGUI::~PlayerGUI() {
}

//Funktionen
void PlayerGUI::updateHPBar() {
    float hpPercent = static_cast<float>(this->playerFighter->getHealth()) / 100.f;
    this->hpBarInner.setSize(sf::Vector2f(140.f * hpPercent, 20.f));
}

void PlayerGUI::update(const float &dt) {
    this->updateHPBar();
}

void PlayerGUI::renderHPBar(sf::RenderTarget &target) {
    target.draw(this->hpBarBackground);
    target.draw(this->hpBarInner);
}

void PlayerGUI::render(sf::RenderTarget &target) {
    this->renderHPBar(target);
}
