//
// Created by Admin on 06.02.2025.
//
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "../GUI/PlayerGUI.h"

int dirX = 0;

//Konstruktor und Destruktor
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initPlayer();
    this->initAI();
    this->initMainMenu();
}

Game::~Game() {
    delete this->window;
    delete this->player;
    delete this->ai;
    delete this->playerGUI;
    delete this->aiGUI;
    delete this->mainMenu;
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
        if (this->event.type == sf::Event::Closed) {
            this->window->close();
        }
        if (inMenu) {
            switch (this->event.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (this->event.key.code == sf::Keyboard::Up) {
                        std::cout << "up" << std::endl;
                        mainMenu->moveUp();
                    } else if (this->event.key.code == sf::Keyboard::Down) {
                        std::cout << "down" << std::endl;
                        mainMenu->moveDown();
                    } else if (this->event.key.code == sf::Keyboard::Enter) {
                        if (mainMenu->getSelectedItem() == 0) {
                            inMenu = false; // Spiel starten
                        } else if (mainMenu->getSelectedItem() == 1) {
                            //Hier dann die Logik für die Optionen einfügen
                        } else if (mainMenu->getSelectedItem() == 2) {
                            this->window->close();
                        }
                        break;
                    }
            }
        }
        if (!inMenu) {
            switch (this->event.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (this->event.key.code == sf::Keyboard::Escape) {
                        this->window->close();
                    } else if (this->event.key.code == sf::Keyboard::A) {
                        dirX = -1;
                    } else if (this->event.key.code == sf::Keyboard::D) {
                        dirX = 1;
                    } else if (this->event.key.code == sf::Keyboard::Space) {
                        this->player->jump();
                    }
                    break;
                case sf::Event::KeyReleased:
                    if (this->event.key.code != sf::Keyboard::A || this->event.key.code != sf::Keyboard::D) {
                        dirX = 0;
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (this->event.mouseButton.button == sf::Mouse::Left) {
                        this->player->attack(*ai);
                    }
                    break;
                case sf::Event::Resized:
                    scaleBackground();
                    break;
            }
        }
    }
}


void Game::update() {
    this->pollEvents();
    if (!inMenu) {
        //Spieler aktualisieren
        this->player->update(dt);
        this->player->move(dirX, dt);
        this->playerGUI->update(dt);

        //AI aktualisieren
        this->ai->update(dt, *player);
        this->aiGUI->update(dt);

        if (ai->isDead()) {
            this->window->close();
        }
        if (player->isDead()) {
            this->window->close();
        }
    }
}

void Game::render() {
    this->window->clear();

    if (inMenu) {
        mainMenu->render(*this->window);
    } else {
        //Hintergrund rendern
        this->window->draw(this->backgroundSprite);

        //Spieler und Waffe rendern
        this->player->render(*this->window);
        this->playerGUI->render(*this->window);

        //AI und Waffe Rendern
        this->ai->render(*this->window);
        this->aiGUI->render(*this->window);
    }
    this->window->display();
}

/** Private */

//Funktionen
void Game::initVariables() {
    this->window = nullptr;
    this->player = nullptr;
    this->ai = nullptr;
    this->playerGUI = nullptr;
    this->aiGUI = nullptr;
}

void Game::scaleBackground() {
    // Hole die aktuelle Fenstergröße
    sf::Vector2u windowSize = this->window->getSize();

    // Berechne den Skalierungsfaktor für das Hintergrundbild
    sf::FloatRect textureRect = this->backgroundSprite.getLocalBounds();
    this->backgroundSprite.setScale(
        windowSize.x / textureRect.width, // Skalierungsfaktor für Breite
        windowSize.y / textureRect.height // Skalierungsfaktor für Höhe
    );
}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "FitnessAction", sf::Style::Titlebar | sf::Style::Close);

    //Hintergrundbild laden
    if (!this->backgroundTexture.loadFromFile("../img/background.JPG")) {
        std::cerr << "Error loading background texture" << std::endl;
    }
    this->backgroundSprite.setTexture(this->backgroundTexture);

    scaleBackground();

    //Framelimit setzen
    window->setFramerateLimit(60);
}

void Game::initPlayer() {
    Weapon *playerWeapon = new Weapon("Kurzhantel", 5, 3.f, "../img/kurzhantel.png");
    this->player = new Fighter("Spieler1", 100, 3, 100.0, 500.0, 0.0f, 9.8f, *playerWeapon,
                               "../img/Spielertest.png");
    this->playerGUI = new PlayerGUI(this->player, sf::Vector2f(20.0f, 20.0f));
}

void Game::initAI() {
    Weapon *aiWeapon = new Weapon("Kurzhantel", 5, 3.f, "../img/kurzhantel.png");
    this->ai = new AI("AI", 100, 3, 400.0, 500.0, 0.0f, 9.8f, *aiWeapon, "../img/Spielertest.png");
    this->aiGUI = new PlayerGUI(this->ai, sf::Vector2f(620, 20.0f));
}

void Game::initMainMenu() {
    this->mainMenu = new MainMenu(this->window->getSize().x, this->window->getSize().y);
    if (!this->mainMenu) {
        std::cerr << "Fehler: mainMenu konnte nicht initialisiert werden!" << std::endl;
        exit(1);
    } else {
        std::cout << "Erfolg: mainMenu wurde korrekt initialisiert!" << std::endl;
    }
    this->inMenu = true;
}
