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
            break;
        }
    }
}


void Game::update() {
    this->pollEvents();

    //Spieler aktualisieren
    this->player->update();

    std::cout << dt << " sekunden" << std::endl;
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
    this->player = new Fighter("Spieler1", 100, 5, 100, 100, 0.0f, 9.8f);
}
