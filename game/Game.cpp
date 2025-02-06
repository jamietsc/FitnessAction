//
// Created by Admin on 06.02.2025.
//
#include <SFML/Graphics.hpp>
#include "Game.h"

//Konstruktor und Destruktor
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initPlayer();
}

Game::~Game() {
    delete this->window;
    delete this->player;
}

//accessors
const bool Game::isRunning() const {
    return this->window->isOpen();
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
                } else if (this->event.key.code == sf::Keyboard::W) {
                    this->player->move(0, -1);
                } else if (this->event.key.code == sf::Keyboard::A) {
                    this->player->move(-1, 0);
                } else if (this->event.key.code == sf::Keyboard::S) {
                    this->player->move(0, 1);
                } else if (this->event.key.code == sf::Keyboard::D) {
                    this->player->move(1, 0);
                }
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

    //Spieler rendern
    this->player->render(*this->window);

    this->window->display();
}

/** Private */

//Funktionen
void Game::initVariables() {
    this->window = nullptr;
    this->player = nullptr;
}

void Game::initWindow() {
    this -> videoMode.height = 600;
    this -> videoMode.width = 800;
    this -> window = new sf::RenderWindow(this->videoMode, "FitnessAction", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initPlayer() {
    this->player = new Fighter("Spieler1", 100, 5, 100, 100);
}
