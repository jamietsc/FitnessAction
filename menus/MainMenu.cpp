//
// Created by Admin on 12.02.2025.
//

#include "MainMenu.h"

#include <iostream>
#include <ostream>

MainMenu::MainMenu(sf::RenderWindow& window) {
    if (!font.loadFromFile("../assets/fonts/STENCIL.TTF")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    sf::Vector2u windowSize = window.getSize();
    float centerX = windowSize.x / 2.0f;

    //Titel
    title.setFont(font);
    title.setString("Fitness Action");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(centerX, 100);

    //Play Button
    playButton.setFont(font);
    playButton.setString("Spiel starten");
    playButton.setCharacterSize(40);
    playButton.setFillColor(sf::Color::Red);
    playButton.setPosition(centerX, 250);

    //Options Button
    /**
    optionsButton.setFont(font);
    optionsButton.setString("Optionen");
    optionsButton.setCharacterSize(40);
    optionsButton.setFillColor(sf::Color::White);
    optionsButton.setPosition(centerX, 350);
    **/

    //Exit Button
    exitButton.setFont(font);
    exitButton.setString("Beenden");
    exitButton.setCharacterSize(40);
    exitButton.setFillColor(sf::Color::White);
    exitButton.setPosition(centerX, 450);

    selectedItemIndex = 0;
}

void MainMenu::render(sf::RenderWindow &window) {
    window.draw(title);
    window.draw(playButton);
    //window.draw(optionsButton);
    window.draw(exitButton);
}

void MainMenu::moveUp() {
    if (selectedItemIndex > 0) {
        selectedItemIndex -= 2;
        switch (selectedItemIndex) {
            case 0:
                playButton.setFillColor(sf::Color::Red);
                optionsButton.setFillColor(sf::Color::White);
                exitButton.setFillColor(sf::Color::White);
                break;
            case 1:
                playButton.setFillColor(sf::Color::White);
                optionsButton.setFillColor(sf::Color::Red);
                exitButton.setFillColor(sf::Color::White);
                break;
            case 2:
                playButton.setFillColor(sf::Color::White);
                optionsButton.setFillColor(sf::Color::White);
                exitButton.setFillColor(sf::Color::Red);
                break;
        }
    }
}

void MainMenu::moveDown() {
    if (selectedItemIndex < 2) {
        selectedItemIndex += 2;
        switch (selectedItemIndex) {
            case 0:
                playButton.setFillColor(sf::Color::Red);
                optionsButton.setFillColor(sf::Color::White);
                exitButton.setFillColor(sf::Color::White);
                break;
            case 1:
                playButton.setFillColor(sf::Color::White);
                optionsButton.setFillColor(sf::Color::Red);
                exitButton.setFillColor(sf::Color::White);
                break;
            case 2:
                playButton.setFillColor(sf::Color::White);
                optionsButton.setFillColor(sf::Color::White);
                exitButton.setFillColor(sf::Color::Red);
                break;
        }
    }
}

int MainMenu::getSelectedItem() {
    return selectedItemIndex;
}

void MainMenu::resize(sf::RenderWindow &window) {
    sf::Vector2u windowSize = window.getSize();
    float centerX = windowSize.x / 2.0f;

    title.setPosition(centerX, 120);
    playButton.setPosition(centerX, 250);
    optionsButton.setPosition(centerX, 350);
    exitButton.setPosition(centerX, 450);
}
