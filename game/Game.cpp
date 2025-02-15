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
    this->initMainMenu();
    this->initCharacterMenu();
    this->initEndScreen();
    audioManager.playBackgroundMusic();
}

Game::~Game() {
    delete this->window;
    this->window = nullptr;
    delete this->player;
    this->player = nullptr;
    delete this->ai;
    this->ai = nullptr;
    delete this->playerGUI;
    this->playerGUI = nullptr;
    delete this->aiGUI;
    this->aiGUI = nullptr;
    delete this->mainMenu;
    this->mainMenu = nullptr;
    delete this->characterMenu;
    this->characterMenu = nullptr;
    delete this->endScreen;
    this->endScreen = nullptr;
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

        /** Kann auskommentiert werden, wenn weitere Bearbeitung
        //Steuerung für Fullscreen
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11) {
            isFullScreen = !isFullScreen;
            window->close();
            if (isFullScreen) {
                window->create(sf::VideoMode::getDesktopMode(), "FitnessAction", sf::Style::Fullscreen);
            } else {
                window->create(sf::VideoMode(800, 600), "FitnessAction", sf::Style::Default);
            }
            if (inMenu) {
                mainMenu->resize(*this->window);
            }
            if (inCharacterMenu) {
                characterMenu->resize(*this->window);
            }
            if (inGame) {
                resizeGame();
            }
        }
        **/

        //steuerung für das Main Menu
        if (inMenu) {
            switch (this->event.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (this->event.key.code == sf::Keyboard::Up) {
                        audioManager.playMenuClick();
                        mainMenu->moveUp();
                    } else if (this->event.key.code == sf::Keyboard::Down) {
                        audioManager.playMenuClick();
                        mainMenu->moveDown();
                    } else if (this->event.key.code == sf::Keyboard::Enter) {
                        audioManager.playMenuClick();
                        if (mainMenu->getSelectedItem() == 0) {
                            inMenu = false; // Spiel starten
                            inCharacterMenu = true;
                        } else if (mainMenu->getSelectedItem() == 1) {
                            //Hier dann die Logik für die Optionen einfügen
                        } else if (mainMenu->getSelectedItem() == 2) {
                            this->window->close();
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        //Steuerung für das Character Menü
        if (inCharacterMenu) {
            switch (this->event.type) {
                case sf::Event::KeyPressed:
                    if (this->event.key.code == sf::Keyboard::Left) {
                        characterMenu->moveLeft();
                        audioManager.playMenuClick();
                    } else if (this->event.key.code == sf::Keyboard::Right) {
                        characterMenu->moveRight();
                        audioManager.playMenuClick();
                    } else if (this->event.key.code == sf::Keyboard::Up) {
                        characterMenu->moveUp();
                        audioManager.playMenuClick();
                    } else if (this->event.key.code == sf::Keyboard::Down) {
                        characterMenu->moveDown();
                        audioManager.playMenuClick();
                    } else if (this->event.key.code == sf::Keyboard::Enter) {
                        audioManager.playMenuClick();
                        if (characterMenu->getSelectedLayer() == 4) {
                            inCharacterMenu = false;
                            this->initPlayer();
                            this->initAI();
                            inGame = true;
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        //Steuerung für das Spiel
        if (inGame) {
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
                default:
                    break;
            }
        }

        //Steuerung für den End Bildschirm
        if (inEndScreen) {
            switch (this->event.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed:
                    audioManager.playMenuClick();
                    if (this->event.key.code == sf::Keyboard::Up) {
                        endScreen->moveUp();
                    } else if (this->event.key.code == sf::Keyboard::Down) {
                        endScreen->moveDown();
                    } else if (this->event.key.code == sf::Keyboard::Enter) {
                        audioManager.playMenuClick();
                        if (endScreen->getSelectedItem() == 0) {
                            restartGame();
                        } else if (endScreen->getSelectedItem() == 1) {
                            goIntoCharacterMenu();
                        } else if (endScreen->getSelectedItem() == 2) {
                            this->window->close();
                        }
                        break;
                    }
            }
        }
    }
}

void Game::update() {
    this->pollEvents();
    if (inGame) {
        //Spieler aktualisieren
        this->player->update(dt);
        this->player->move(dirX, dt);
        this->playerGUI->update(dt);

        //AI aktualisieren
        this->ai->update(dt, *player);
        this->aiGUI->update(dt);

        if (ai->isDead()) {
            endScreen->winnerMessage(0);
            this->inEndScreen = true;
        } else if (player->isDead()) {
            endScreen->winnerMessage(1);
            this->inGame = true;
        }
    }
}

void Game::render() {
    this->window->clear();
    //Rendern des Start Menüs
    if (inMenu) {
        mainMenu->render(*this->window);
    }

    //Rendern des Menüs zur Charakterauswahl
    if (inCharacterMenu) {
        characterMenu->render(*this->window);
    }

    //Rendern des Spiels
    if (inGame) {
        //Hintergrund rendern
        this->window->draw(this->backgroundSprite);

        //Spieler und Waffe rendern
        this->player->render(*this->window);
        this->playerGUI->render(*this->window);

        //AI und Waffe Rendern
        this->ai->render(*this->window);
        this->aiGUI->render(*this->window);
    }

    //Rendern des Endbildschirms
    if (inEndScreen) {
        this->window->clear();
        this->endScreen->render(*this->window);
    }
    this->window->display();
}

void Game::restartGame() {
    delete this->player;
    delete this->ai;
    delete this->playerGUI;
    delete this->aiGUI;

    this->initPlayer();
    this->initAI();
    this->inEndScreen = false;
    this->inGame = true;
}

void Game::goIntoCharacterMenu() {
    // Lösche alle spielbezogenen Objekte, um Speicherlecks zu vermeiden
    if (this->player) {
        delete this->player;
        this->player = nullptr;
    }
    if (this->ai) {
        delete this->ai;
        this->ai = nullptr;
    }
    if (this->playerGUI) {
        delete this->playerGUI;
        this->playerGUI = nullptr;
    }
    if (this->aiGUI) {
        delete this->aiGUI;
        this->aiGUI = nullptr;
    }
    if (this->endScreen) {
        delete this->endScreen;
        this->endScreen = nullptr;
    }

    // Setze die Zustände zurück
    this->inGame = false;
    this->inEndScreen = false;
    this->inMenu = false;
    this->inCharacterMenu = true; // Charaktermenü aktivieren

    // Falls das Charaktermenü gelöscht wurde, neu initialisieren
    if (!this->characterMenu) {
        this->initCharacterMenu();
    }
}

/** Private */

//Funktionen
void Game::initVariables() {
    this->window = nullptr;
    this->player = nullptr;
    this->ai = nullptr;
    this->playerGUI = nullptr;
    this->aiGUI = nullptr;

    //Variablen für die Menüs
    this->mainMenu = nullptr;
    this->characterMenu = nullptr;
    this->endScreen = nullptr;
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
    if (!this->backgroundTexture.loadFromFile("../assets/img/background.JPG")) {
        std::cerr << "Error loading background texture" << std::endl;
    }
    this->backgroundSprite.setTexture(this->backgroundTexture);

    scaleBackground();

    //Framelimit setzen
    window->setFramerateLimit(60);
}

void Game::initPlayer() {
    this->player = new Fighter(100, 3, 100.0, 500.0, 0.0f, *characterMenu->getFirstWeapon(),
                               characterMenu->getSelectedFirstCharacter());
    player->setGround(*this->window);
    this->playerGUI = new PlayerGUI(this->player, sf::Vector2f(20.0f, 20.0f));
}

void Game::initAI() {
    this->ai = new AI(100, 3, 400.0, 500.0, 0.0f, *characterMenu->getSecondWeapon(),
                      characterMenu->getSelectedSecondCharacter());
    ai->setGround(*this->window);
    this->aiGUI = new PlayerGUI(this->ai, sf::Vector2f(620, 20.0f));
}

void Game::initMainMenu() {
    this->mainMenu = new MainMenu(*this->window);
    if (!this->mainMenu) {
        std::cerr << "Fehler: mainMenu konnte nicht initialisiert werden!" << std::endl;
        exit(1);
    }
    this->inMenu = true;
}

void Game::initCharacterMenu() {
    this->characterMenu = new CharacterMenu(*this->window);
    if (!this->characterMenu) {
        std::cerr << "Fehler: characterMenu konnte nicht initialisiert werden!" << std::endl;
        exit(1);
    }
    this->inCharacterMenu = false;
}

void Game::initEndScreen() {
    this->endScreen = new EndScreen(this->window->getSize().x, this->window->getSize().y);
    if (!this->endScreen) {
        std::cerr << "Fehler: endScreen konnte nicht initialisiert werden!" << std::endl;
        exit(1);
    }
    this->inEndScreen = false;
}

void Game::resizeGame() {
    //this->scaleBackground();
    player->setGround(*this->window);
    ai->setGround(*window);
}
