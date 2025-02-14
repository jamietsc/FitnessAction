//
// Created by Admin on 12.02.2025.
//

#include "EndScreen.h"

#include <iostream>
#include <ostream>


EndScreen::EndScreen(float width, float height) {
    if (!font.loadFromFile("../fonts/STENCIL.ttf")) {
        std::cerr << "Fehler: Laden der Schrift fehlgeschlagen" << std::endl;
    }

    //Titel
    title.setFont(font);
    title.setString("Fitness Action");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(width / 2 - 100, 100);

    //Gewonnen anzeige
    message.setFont(font);
    message.setString("");
    message.setCharacterSize(30);
    message.setFillColor(sf::Color::Yellow);
    message.setPosition(width / 2 - 380, 350);

    //Erneut Spielen Knopf
    playAgainButton.setFont(font);
    playAgainButton.setString("Erneut spielen");
    playAgainButton.setCharacterSize(40);
    playAgainButton.setFillColor(sf::Color::Red);
    playAgainButton.setPosition(width / 2 - 50, 250);

    //Character Auswahl Knopf
    differentCharacters.setFont(font);
    differentCharacters.setString("Charakter Auswahl");
    differentCharacters.setCharacterSize(40);
    differentCharacters.setFillColor(sf::Color::White);
    differentCharacters.setPosition(width / 2 - 50, 350);

    //Exit Button
    exitButton.setFont(font);
    exitButton.setString("Beenden");
    exitButton.setCharacterSize(40);
    exitButton.setFillColor(sf::Color::White);
    exitButton.setPosition(width / 2 - 50, 450);

    selectedItemIndex = 0;
}

void EndScreen::render(sf::RenderWindow &window) {
    window.draw(title);
    window.draw(message);
    window.draw(playAgainButton);
    window.draw(differentCharacters);
    window.draw(exitButton);
}


void EndScreen::moveUp() {
    if (selectedItemIndex > 0) {
        selectedItemIndex--;
        switch (selectedItemIndex) {
            case 0:
                playAgainButton.setFillColor(sf::Color::Red);
                differentCharacters.setFillColor(sf::Color::White);
                exitButton.setFillColor(sf::Color::White);
                break;
            case 1:
                playAgainButton.setFillColor(sf::Color::White);
                differentCharacters.setFillColor(sf::Color::Red);
                exitButton.setFillColor(sf::Color::White);
                break;
            case 2:
                playAgainButton.setFillColor(sf::Color::White);
                differentCharacters.setFillColor(sf::Color::White);
                exitButton.setFillColor(sf::Color::Red);
                break;
            default:
                break;
        }
    }
}

void EndScreen::moveDown() {
    if (selectedItemIndex < 2) {
        selectedItemIndex++;
        switch (selectedItemIndex) {
            case 0:
                playAgainButton.setFillColor(sf::Color::Red);
                differentCharacters.setFillColor(sf::Color::White);
                exitButton.setFillColor(sf::Color::White);
                break;
            case 1:
                playAgainButton.setFillColor(sf::Color::White);
                differentCharacters.setFillColor(sf::Color::Red);
                exitButton.setFillColor(sf::Color::White);
                break;
            case 2:
                playAgainButton.setFillColor(sf::Color::White);
                differentCharacters.setFillColor(sf::Color::White);
                exitButton.setFillColor(sf::Color::Red);
                break;
            default:
                break;
        }
    }
}

int EndScreen::getSelectedItem() {
    return this->selectedItemIndex;
}

void EndScreen::winnerMessage(int winner) {
    if (winner == 0) {
        message.setString("Sie haben gewonnen!");
    }
    else if (winner == 1) {
        message.setString("Sie haben verloren!");
    }
}
