//
// Created by Admin on 06.02.2025.
//
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"


//Konstruktor und Destruktor
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initPlayer();
    this->initAI();
}

Game::~Game() {
    delete this->window;
    delete this->player;
}

//accessors
const bool Game::isRunning() const {
    return this->window->isOpen();
}

void Game::updateDt() {
    //Update der dt Varibale mit der Zeit wie lange es gedauert hat einen Frame zu rendern
    this->dt = this->dtClock.restart().asSeconds();



}

/* Funktionen */
void Game::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                } else if (this->event.key.code == sf::Keyboard::A) {
                    this->player->move(-1, dt);
                } else if (this->event.key.code == sf::Keyboard::D) {
                    this->player->move(1, dt);
                } else if (this->event.key.code == sf::Keyboard::Space) {
                    this->player->jump();
                }
            case sf::Event::Resized:
                scaleBackground();
                break;
            break;
        }
    }
}


void Game::update() {
    this->pollEvents();

    //Spieler aktualisieren
    this->player->update();
}

void Game::render() {
    this->window->clear();

    //Hintergrund rendern
    this->window->draw(this->backgroundSprite);

    //Spieler und Waffe rendern
    this->player->render(*this->window);

    //AI Rendern
    this->AI->render(*this->window);

    this->window->display();
}

/** Private */

//Funktionen
void Game::initVariables() {
    this->window = nullptr;
    this->player = nullptr;
    this->AI = nullptr;
}

void Game::scaleBackground() {
    // Hole die aktuelle Fenstergröße
    sf::Vector2u windowSize = this->window->getSize();

    // Berechne den Skalierungsfaktor für das Hintergrundbild
    sf::FloatRect textureRect = this->backgroundSprite.getLocalBounds();
    this->backgroundSprite.setScale(
        windowSize.x / textureRect.width,  // Skalierungsfaktor für Breite
        windowSize.y / textureRect.height // Skalierungsfaktor für Höhe
    );
}

void Game::initWindow() {
    this -> videoMode.height = 600;
    this -> videoMode.width = 800;
    this -> window = new sf::RenderWindow(this->videoMode, "FitnessAction", sf::Style::Titlebar | sf::Style::Close);

    //Hintergrundbild laden
    if (!this->backgroundTexture.loadFromFile("../img/background.JPG")) {
        std::cerr << "Error loading background texture" << std::endl;
    }
    this->backgroundSprite.setTexture(this->backgroundTexture);

    scaleBackground();
}

void Game::initPlayer() {
    Weapon *playerWeapon = new Weapon("Kurzhantel", 5, 5, "../img/kurzhantel.png");
    this->player = new Fighter("Spieler1", 100, 3, 100, 500, 0.0f, 9.8f, *playerWeapon);

}

void Game::initAI() {
    Weapon *aiWeapon = new Weapon("Kurzhantel", 5, 5, "../img/kurzhantel.png");
    this->AI = new Fighter("AI", 100, 3, 400, 500, 0.0f, 9.8f, *aiWeapon);
}
