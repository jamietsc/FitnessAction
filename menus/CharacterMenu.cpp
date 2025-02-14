//
// Created by sauser on 13.02.2025.
//

#include <iostream>
#include "CharacterMenu.h"

CharacterMenu::CharacterMenu(float width, float height) {
    if (!font.loadFromFile("../fonts/STENCIL.TTF")) {
        std::cerr << "CharacterMenu: Laden der Schriftart Fehlgeschlagen." << std::endl;
    }

    //Titel
    title.setFont(font);
    title.setString("Charakter Auwahl");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(width / 2 - 275, 50);

    //Erster Spieler Spalte
    firstPlayerText.setFont(font);
    firstPlayerText.setString("Spieler 1:");
    firstPlayerText.setCharacterSize(30);
    firstPlayerText.setFillColor(sf::Color::White);
    firstPlayerText.setPosition(width / 2 - 300, 120);

    //Erster Spieler Charakterauswahl
    firstPlayerCharcterBack.setFillColor(sf::Color(200, 200, 200, 200));
    firstPlayerCharcterBack.setPosition(width / 2 - 300, 170);
    firstPlayerCharcterBack.setSize(sf::Vector2f(150.f, 250.f));

    //Erster Spieler Waffenauswahl
    firstPlayerWeaponBack.setFillColor(sf::Color(200, 200, 200, 200));
    firstPlayerWeaponBack.setPosition(width / 2 - 300, 450);
    firstPlayerWeaponBack.setSize(sf::Vector2f(150.f, 75.f));

    //Zweiter Spieler Spalte
    secondPlayerText.setFont(font);
    secondPlayerText.setString("Spieler 2:");
    secondPlayerText.setCharacterSize(30);
    secondPlayerText.setFillColor(sf::Color::White);
    secondPlayerText.setPosition(width / 2 + 100, 120);

    secondPlayerCharacterBack.setFillColor(sf::Color(200, 200, 200, 200));
    secondPlayerCharacterBack.setPosition(width / 2 + 100, 170);
    secondPlayerCharacterBack.setSize(sf::Vector2f(150.f, 250.f));

    //Zweiter Spieler Waffenauswahl
    secondPlayerWeaponBack.setFillColor(sf::Color(200, 200, 200, 200));
    secondPlayerWeaponBack.setPosition(width / 2 + 100, 450);
    secondPlayerWeaponBack.setSize(sf::Vector2f(150.f, 75.f));

    for (size_t i = 0; i < skinPaths.size(); i++) {
        if (!this->playerTexture.loadFromFile(skinPaths[i])) {
            std::cerr << "CharacterMenu: Fehler beim Laden der Skins" << std::endl;
        }
        if (!this->weaponTexture.loadFromFile(weaponPaths[i])) {
            std::cerr << "CharacterMenu: Fehler beim Laden der Waffenskins." << std::endl;
        }
    }
    playerTexture.loadFromFile(skinPaths[0]);
    weaponTexture.loadFromFile(weaponPaths[0]);

    firstPlayerSprite.setTexture(playerTexture);
    firstWeaponSprite.setTexture(weaponTexture);
    secondPlayerSprite.setTexture(playerTexture);
    secondWeaponSprite.setTexture(weaponTexture);

    //Grafiken Spieler 1
    firstPlayerSprite.setOrigin(
            firstPlayerSprite.getLocalBounds().width / 2,
            firstPlayerSprite.getLocalBounds().height / 2
    );
    firstPlayerSprite.setScale(2.f, 2.f);
    firstPlayerSprite.setPosition(
            firstPlayerCharcterBack.getPosition().x + firstPlayerCharcterBack.getSize().x / 2,
            firstPlayerCharcterBack.getPosition().y + firstPlayerCharcterBack.getSize().y / 2
    );

    firstWeaponSprite.setOrigin(
            firstWeaponSprite.getLocalBounds().width / 2,
            firstWeaponSprite.getLocalBounds().height / 2
    );
    firstWeaponSprite.setScale(2.f, 2.f);
    firstWeaponSprite.setPosition(
            firstPlayerWeaponBack.getPosition().x + firstPlayerWeaponBack.getSize().x / 2,
            firstPlayerWeaponBack.getPosition().y + firstPlayerWeaponBack.getSize().y / 2
    );

    //Spieler 2
    secondPlayerSprite.setOrigin(
            secondPlayerSprite.getLocalBounds().width / 2,
            secondPlayerSprite.getLocalBounds().height / 2
    );
    secondPlayerSprite.setScale(2.f, 2.f);
    secondPlayerSprite.setPosition(
            secondPlayerCharacterBack.getPosition().x + secondPlayerCharacterBack.getSize().x / 2,
            secondPlayerCharacterBack.getPosition().y + secondPlayerCharacterBack.getSize().y / 2
    );

    secondWeaponSprite.setOrigin(
            secondWeaponSprite.getLocalBounds().width / 2,
            secondWeaponSprite.getLocalBounds().height / 2
    );
    secondWeaponSprite.setScale(2.f, 2.f);
    secondWeaponSprite.setPosition(
            secondPlayerWeaponBack.getPosition().x + secondPlayerWeaponBack.getSize().x / 2,
            secondPlayerWeaponBack.getPosition().y + secondPlayerWeaponBack.getSize().y / 2
    );

    arrowLeftPosition = {
            {firstPlayerCharcterBack.getPosition().x - 50,
                    firstPlayerCharcterBack.getPosition().y + (firstPlayerCharcterBack.getSize().y / 2)},
            {firstPlayerWeaponBack.getPosition().x - 50,
                    firstPlayerWeaponBack.getPosition().y + (firstPlayerWeaponBack.getSize().y / 2)},
            {secondPlayerCharacterBack.getPosition().x - 50,
                    secondPlayerCharacterBack.getPosition().y + (secondPlayerCharacterBack.getSize().y / 2)},
            {secondPlayerWeaponBack.getPosition().x - 50,
                    secondPlayerWeaponBack.getPosition().y + (secondPlayerWeaponBack.getSize().y / 2)}
    };

    arrowRightPosition = {
            {firstPlayerCharcterBack.getPosition().x + firstPlayerCharcterBack.getSize().x + 20,
                    firstPlayerCharcterBack.getPosition().y + (firstPlayerCharcterBack.getSize().y / 2)},
            {firstPlayerWeaponBack.getPosition().x + firstPlayerWeaponBack.getSize().x + 20,
                    firstPlayerWeaponBack.getPosition().y + (firstPlayerWeaponBack.getSize().y / 2)},
            {secondPlayerCharacterBack.getPosition().x + secondPlayerCharacterBack.getSize().x + 20,
                    secondPlayerCharacterBack.getPosition().y + (secondPlayerCharacterBack.getSize().y / 2)},
            {secondPlayerWeaponBack.getPosition().x + secondPlayerWeaponBack.getSize().x + 20,
                    secondPlayerWeaponBack.getPosition().y + (secondPlayerWeaponBack.getSize().y / 2)}
    };

    arrowLeft.setFont(font);
    arrowLeft.setString("<<");
    arrowLeft.setCharacterSize(20);
    arrowLeft.setFillColor(sf::Color::White);
    arrowLeft.setPosition(arrowLeftPosition[0]);

    arrowRight.setFont(font);
    arrowRight.setString(">>");
    arrowRight.setCharacterSize(20);
    arrowRight.setFillColor(sf::Color::White);
    arrowRight.setPosition(arrowRightPosition[0]);

    enterButton.setFont(font);
    enterButton.setString("Bestätigen");
    enterButton.setCharacterSize(30);
    enterButton.setFillColor(sf::Color::White);
    enterButton.setPosition(
            width / 2 - 125,
            height - 50
            );
}

void CharacterMenu::render(sf::RenderWindow &window) {
    window.draw(title);
    window.draw(firstPlayerText);
    window.draw(firstPlayerCharcterBack);
    window.draw(firstPlayerWeaponBack);
    window.draw(firstPlayerSprite);
    window.draw(firstWeaponSprite);

    window.draw(secondPlayerText);
    window.draw(secondPlayerCharacterBack);
    window.draw(secondPlayerWeaponBack);
    window.draw(secondPlayerSprite);
    window.draw(secondWeaponSprite);

    window.draw(arrowLeft);
    window.draw(arrowRight);

    window.draw(enterButton);
}

void CharacterMenu::moveUp() {
    if(selectedLayer == 4){
        arrowLeft.setFillColor(sf::Color::White);
        arrowRight.setFillColor(sf::Color::White);
        enterButton.setFillColor(sf::Color::White);
    }

    if (selectedLayer > 0) {
        selectedLayer--;
        arrowLeft.setPosition(arrowLeftPosition[selectedLayer]);
        arrowRight.setPosition(arrowRightPosition[selectedLayer]);
    }
}

void CharacterMenu::moveDown() {
    if (selectedLayer < 3) {
        selectedLayer++;
        arrowLeft.setPosition(arrowLeftPosition[selectedLayer]);
        arrowRight.setPosition(arrowRightPosition[selectedLayer]);

    } else if (selectedLayer == 3) {
        selectedLayer++;
        arrowLeft.setFillColor(sf::Color::Transparent);
        arrowRight.setFillColor(sf::Color::Transparent);
        enterButton.setFillColor(sf::Color::Red);
    }
}

void CharacterMenu::moveLeft() {
    switch (selectedLayer) {
        case 0:
            if (selectedItemFirstCharacter - 1 < skinPaths.size()) {
                selectedItemFirstCharacter = skinPaths.size();
            } else {
                selectedItemFirstCharacter--;
            }
            playerTexture.loadFromFile(skinPaths[selectedItemFirstCharacter]);
            firstPlayerSprite.setTexture(playerTexture);
            break;
        case 1:
            if (selectedItemFirstWeapon - 1 < weaponPaths.size()) {
                selectedItemFirstWeapon = weaponPaths.size();
            } else {
                selectedItemFirstWeapon--;
            }
            weaponTexture.loadFromFile(weaponPaths[selectedItemFirstWeapon]);
            firstWeaponSprite.setTexture(weaponTexture);
            break;
        case 2:
            if (selectedItemSecondCharacter - 1 < skinPaths.size()) {
                selectedItemSecondCharacter = skinPaths.size();
            } else {
                selectedItemSecondCharacter--;
            }
            playerTexture.loadFromFile(skinPaths[selectedItemSecondCharacter]);
            secondPlayerSprite.setTexture(playerTexture);
            break;
        case 3:
            if (selectedItemSecondWeapon - 1 < weaponPaths.size()) {
                selectedItemSecondWeapon = weaponPaths.size();
            } else {
                selectedItemSecondWeapon--;
            }
            weaponTexture.loadFromFile(weaponPaths[selectedItemSecondWeapon]);
            secondWeaponSprite.setTexture(weaponTexture);
            break;
        default:
            break;
    }
}

void CharacterMenu::moveRight() {
    switch (selectedLayer) {
        case 0:
            if (selectedItemFirstCharacter + 1 > skinPaths.size()) {
                selectedItemFirstCharacter = 0;
            } else {
                selectedItemFirstCharacter++;
            }
            playerTexture.loadFromFile(skinPaths[selectedItemFirstCharacter]);
            firstPlayerSprite.setTexture(playerTexture);
            break;
        case 1:
            if (selectedItemFirstWeapon + 1 > weaponPaths.size()) {
                selectedItemFirstWeapon = 0;
            } else {
                selectedItemFirstWeapon++;
            }
            weaponTexture.loadFromFile(weaponPaths[selectedItemFirstWeapon]);
            firstWeaponSprite.setTexture(weaponTexture);
            break;
        case 2:
            if (selectedItemSecondCharacter + 1 > skinPaths.size()) {
                selectedItemSecondCharacter = 0;
            } else {
                selectedItemSecondCharacter++;
            }
            playerTexture.loadFromFile(skinPaths[selectedItemSecondCharacter]);
            secondPlayerSprite.setTexture(playerTexture);
            break;
        case 3:
            if (selectedItemSecondWeapon + 1 > weaponPaths.size()) {
                selectedItemSecondWeapon = 0;
            } else {
                selectedItemSecondWeapon++;
            }
            weaponTexture.loadFromFile(weaponPaths[selectedItemSecondWeapon]);
            secondWeaponSprite.setTexture(weaponTexture);
            break;
        default:
            break;
    }
}

std::string CharacterMenu::getSelectedFirstCharacter() {
    return skinPaths[selectedItemFirstCharacter];
}

std::string CharacterMenu::getSelectedFirstWeapon() {
    return weaponPaths[selectedItemFirstWeapon];
}

std::string CharacterMenu::getSelectedSecondCharacter() {
    return skinPaths[selectedItemSecondCharacter];
}

std::string CharacterMenu::getSelectedSecondWeapon() {
    return weaponPaths[selectedItemSecondWeapon];
}

int CharacterMenu::getSelectedLayer() {
    return selectedLayer;
}
