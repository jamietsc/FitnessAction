//
// Created by Admin on 12.02.2025.
//

#include "MainMenu.h"

#include <iostream>
#include <ostream>

MainMenu::MainMenu(float width, float height) {
    std::cout << "MainMenu.Konstruktor aufgerufen!" << std::endl;
    if (!font.loadFromFile("../fonts/STENCIL.TTF")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    //Titel
    title.setFont(font);
    title.setString("Fitness Action");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(width / 2 - 100, 100);

    //Play Button
    playButton.setFont(font);
    playButton.setString("Spiel starten");
    playButton.setCharacterSize(40);
    playButton.setFillColor(sf::Color::Red);
    playButton.setPosition(width / 2 - 50, 250);

    //Options Button
    optionsButton.setFont(font);
    optionsButton.setString("Optionen");
    optionsButton.setCharacterSize(40);
    optionsButton.setFillColor(sf::Color::White);
    optionsButton.setPosition(width / 2 - 50, 350);

    //Exit Button
    exitButton.setFont(font);
    exitButton.setString("Beenden");
    exitButton.setCharacterSize(40);
    exitButton.setFillColor(sf::Color::White);
    exitButton.setPosition(width / 2 - 50, 450);

    selectedItemIndex = 0;
}

void MainMenu::render(sf::RenderWindow &window) {
    window.draw(title);
    window.draw(playButton);
    window.draw(optionsButton);
    window.draw(exitButton);
}

void MainMenu::moveUp() {
    if (selectedItemIndex > 0) {
        selectedItemIndex--;
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
        selectedItemIndex++;
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
