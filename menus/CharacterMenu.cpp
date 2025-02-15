//
// Created by sauser on 13.02.2025.
//

#include <iostream>
#include "CharacterMenu.h"

#include <cmath>

void CharacterMenu::showNewStats() {
    if (selectedLayer == 1) {
        firstName.setString(weaponStats[selectedItemFirstWeapon].name);
        firstDamage.setString("Schaden: " + std::to_string(weaponStats[selectedItemFirstWeapon].damage));
        firstAttackSpeed.setString("Geschwindigkeit: " + std::format("{:.1f}", weaponStats[selectedItemFirstWeapon].attackSpeed));
    } else if (selectedLayer == 3) {
        secondName.setString(weaponStats[selectedItemSecondWeapon].name);
        secondDamage.setString("Schaden: " +std::to_string(weaponStats[selectedItemSecondWeapon].damage));
        secondAttackSpeed.setString("Geschwindigkeit: " + std::format("{:.1f}", weaponStats[selectedItemSecondWeapon].attackSpeed));
    }
}

CharacterMenu::CharacterMenu(sf::RenderWindow &window) {
    sf::Vector2u windowSize = window.getSize();
    float centerX = windowSize.x / 2;
    float centerY = windowSize.y / 2;

    if (!font.loadFromFile("../assets/fonts/STENCIL.TTF")) {
        std::cerr << "CharacterMenu: Laden der Schriftart Fehlgeschlagen." << std::endl;
    }

    //Titel
    title.setFont(font);
    title.setString("Charakter Auwahl");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(centerX - (0.5f * title.getLocalBounds().width), 50);

    //Erster Spieler Spalte
    firstPlayerText.setFont(font);
    firstPlayerText.setString("Spieler 1:");
    firstPlayerText.setCharacterSize(30);
    firstPlayerText.setFillColor(sf::Color::White);
    firstPlayerText.setPosition(centerX - 300, 120);

    //Erster Spieler Charakterauswahl
    firstPlayerCharcterBack.setFillColor(sf::Color(200, 200, 200, 200));
    firstPlayerCharcterBack.setPosition(centerX - 300, 170);
    firstPlayerCharcterBack.setSize(sf::Vector2f(150.f, 250.f));

    //Erster Spieler Waffenauswahl
    firstPlayerWeaponBack.setFillColor(sf::Color(200, 200, 200, 200));
    firstPlayerWeaponBack.setPosition(centerX - 300, 450);
    firstPlayerWeaponBack.setSize(sf::Vector2f(150.f, 75.f));

    //Zweiter Spieler Spalte
    secondPlayerText.setFont(font);
    secondPlayerText.setString("Spieler 2:");
    secondPlayerText.setCharacterSize(30);
    secondPlayerText.setFillColor(sf::Color::White);
    secondPlayerText.setPosition(centerX + 100, 120);

    secondPlayerCharacterBack.setFillColor(sf::Color(200, 200, 200, 200));
    secondPlayerCharacterBack.setPosition(centerX + 100, 170);
    secondPlayerCharacterBack.setSize(sf::Vector2f(150.f, 250.f));

    //Zweiter Spieler Waffenauswahl
    secondPlayerWeaponBack.setFillColor(sf::Color(200, 200, 200, 200));
    secondPlayerWeaponBack.setPosition(centerX + 100, 450);
    secondPlayerWeaponBack.setSize(sf::Vector2f(150.f, 75.f));

    //Zum überprüfen ob alle Spieler Bilder geladen werden können
    for (size_t i = 0; i < skinPaths.size(); i++) {
        if (!this->firstPlayerTexture.loadFromFile(skinPaths[i])) {
            std::cerr << "CharacterMenu: Fehler beim Laden der Skins" << std::endl;
        }
        if (!this->firstWeaponTexture.loadFromFile(weaponPaths[i])) {
            std::cerr << "CharacterMenu: Fehler beim Laden der Waffenskins." << std::endl;
        }
    }
    firstPlayerTexture.loadFromFile(skinPaths[0]);
    firstWeaponTexture.loadFromFile(weaponPaths[0]);
    secondPlayerTexture.loadFromFile(skinPaths[0]);
    secondWeaponTexture.loadFromFile(weaponPaths[0]);

    firstPlayerSprite.setTexture(firstPlayerTexture);
    firstWeaponSprite.setTexture(firstWeaponTexture);
    secondPlayerSprite.setTexture(secondPlayerTexture);
    secondWeaponSprite.setTexture(secondWeaponTexture);

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
        {
            firstPlayerCharcterBack.getPosition().x - 50,
            firstPlayerCharcterBack.getPosition().y + (firstPlayerCharcterBack.getSize().y / 2)
        },
        {
            firstPlayerWeaponBack.getPosition().x - 50,
            firstPlayerWeaponBack.getPosition().y + (firstPlayerWeaponBack.getSize().y / 2)
        },
        {
            secondPlayerCharacterBack.getPosition().x - 50,
            secondPlayerCharacterBack.getPosition().y + (secondPlayerCharacterBack.getSize().y / 2)
        },
        {
            secondPlayerWeaponBack.getPosition().x - 50,
            secondPlayerWeaponBack.getPosition().y + (secondPlayerWeaponBack.getSize().y / 2)
        }
    };

    arrowRightPosition = {
        {
            firstPlayerCharcterBack.getPosition().x + firstPlayerCharcterBack.getSize().x + 20,
            firstPlayerCharcterBack.getPosition().y + (firstPlayerCharcterBack.getSize().y / 2)
        },
        {
            firstPlayerWeaponBack.getPosition().x + firstPlayerWeaponBack.getSize().x + 20,
            firstPlayerWeaponBack.getPosition().y + (firstPlayerWeaponBack.getSize().y / 2)
        },
        {
            secondPlayerCharacterBack.getPosition().x + secondPlayerCharacterBack.getSize().x + 20,
            secondPlayerCharacterBack.getPosition().y + (secondPlayerCharacterBack.getSize().y / 2)
        },
        {
            secondPlayerWeaponBack.getPosition().x + secondPlayerWeaponBack.getSize().x + 20,
            secondPlayerWeaponBack.getPosition().y + (secondPlayerWeaponBack.getSize().y / 2)
        }
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
        centerX - 125, windowSize.y - 50
    );

    firstPlayerWeapon = new Weapon(weaponStats[0].name, weaponStats[0].damage, weaponStats[0].attackSpeed,
                                   weaponPaths[0]);
    secondPlayerWeapon = new Weapon(weaponStats[0].name, weaponStats[0].damage, weaponStats[0].attackSpeed,
                                    weaponPaths[0]);

    // Erster Spieler Waffen-Stats
    firstName.setFont(font);
    firstName.setString(weaponStats[0].name);
    firstName.setCharacterSize(15);
    firstName.setFillColor(sf::Color::White);
    firstName.setPosition(firstPlayerCharcterBack.getPosition().x + 170, firstPlayerCharcterBack.getPosition().y);

    firstDamage.setFont(font);
    firstDamage.setString("Schaden: " + std::to_string(weaponStats[0].damage));
    firstDamage.setCharacterSize(15);
    firstDamage.setFillColor(sf::Color::White);
    firstDamage.setPosition(firstPlayerCharcterBack.getPosition().x + 170,
                            firstPlayerCharcterBack.getPosition().y + 30);

    firstAttackSpeed.setFont(font);
    firstAttackSpeed.setString("Angriffsgeschw.: " + std::format("{:.1f}", weaponStats[0].attackSpeed));
    firstAttackSpeed.setCharacterSize(15);
    firstAttackSpeed.setFillColor(sf::Color::White);
    firstAttackSpeed.setPosition(firstPlayerCharcterBack.getPosition().x + 170,
                                 firstPlayerCharcterBack.getPosition().y + 60);

    // Zweiter Spieler Waffen-Stats
    secondName.setFont(font);
    secondName.setString(weaponStats[0].name);
    secondName.setCharacterSize(15);
    secondName.setFillColor(sf::Color::White);
    float secondPlayerLeft = secondPlayerCharacterBack.getPosition().x - 20;
    secondName.setPosition(secondPlayerLeft - secondName.getLocalBounds().width, secondPlayerCharacterBack.getPosition().y);

    secondDamage.setFont(font);
    secondDamage.setString("Schaden: " + std::to_string(weaponStats[0].damage));
    secondDamage.setCharacterSize(15);
    secondDamage.setFillColor(sf::Color::White);
    secondDamage.setPosition(secondPlayerLeft - secondDamage.getLocalBounds().width, secondPlayerCharacterBack.getPosition().y + 30);

    secondAttackSpeed.setFont(font);
    secondAttackSpeed.setString("Angriffsgeschw.: " + std::format("{:.1f}", weaponStats[0].attackSpeed));
    secondAttackSpeed.setCharacterSize(15);
    secondAttackSpeed.setFillColor(sf::Color::White);
    secondAttackSpeed.setPosition(secondPlayerLeft - secondAttackSpeed.getLocalBounds().width, secondPlayerCharacterBack.getPosition().y + 60);
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

    if (selectedLayer == 1) {
        window.draw(firstName);
        window.draw(firstDamage);
        window.draw(firstAttackSpeed);
    }
    if (selectedLayer == 3) {
        window.draw(secondName);
        window.draw(secondDamage);
        window.draw(secondAttackSpeed);
    }

    window.draw(enterButton);
}

void CharacterMenu::moveUp() {
    if (selectedLayer == 4) {
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
            if (selectedItemFirstCharacter == 0) {
                selectedItemFirstCharacter = skinPaths.size() - 1;
            } else {
                selectedItemFirstCharacter--;
            }
            firstPlayerTexture.loadFromFile(skinPaths[selectedItemFirstCharacter]);
            firstPlayerSprite.setTexture(firstPlayerTexture);
            break;
        case 1:
            if (selectedItemFirstWeapon == 0) {
                selectedItemFirstWeapon = weaponPaths.size() - 1;
            } else {
                selectedItemFirstWeapon--;
            }
            firstWeaponTexture.loadFromFile(weaponPaths[selectedItemFirstWeapon]);
            firstWeaponSprite.setTexture(firstWeaponTexture);
            firstPlayerWeapon = new Weapon(weaponStats[selectedItemFirstWeapon].name,
                                           weaponStats[selectedItemFirstWeapon].damage,
                                           weaponStats[selectedItemFirstWeapon].attackSpeed,
                                           weaponPaths[selectedItemFirstWeapon]);
            break;
        case 2:
            if (selectedItemSecondCharacter == 0) {
                selectedItemSecondCharacter = skinPaths.size() - 1;
            } else {
                selectedItemSecondCharacter--;
            }
            secondPlayerTexture.loadFromFile(skinPaths[selectedItemSecondCharacter]);
            secondPlayerSprite.setTexture(secondPlayerTexture);
            break;
        case 3:
            if (selectedItemSecondWeapon == 0) {
                selectedItemSecondWeapon = weaponPaths.size() - 1;
            } else {
                selectedItemSecondWeapon--;
            }
            secondWeaponTexture.loadFromFile(weaponPaths[selectedItemSecondWeapon]);
            secondWeaponSprite.setTexture(secondWeaponTexture);
            secondPlayerWeapon = new Weapon(weaponStats[selectedItemSecondWeapon].name,
                                            weaponStats[selectedItemSecondWeapon].damage,
                                            weaponStats[selectedItemSecondWeapon].attackSpeed,
                                            weaponPaths[selectedItemSecondWeapon]);
            break;
        default:
            break;
    }
    showNewStats();
}

void CharacterMenu::moveRight() {
    switch (selectedLayer) {
        case 0:
            if (selectedItemFirstCharacter + 1 == skinPaths.size()) {
                selectedItemFirstCharacter = 0;
            } else {
                selectedItemFirstCharacter++;
            }
            firstPlayerTexture.loadFromFile(skinPaths[selectedItemFirstCharacter]);
            firstPlayerSprite.setTexture(firstPlayerTexture);
            break;
        case 1:
            if (selectedItemFirstWeapon + 1 == weaponPaths.size()) {
                selectedItemFirstWeapon = 0;
            } else {
                selectedItemFirstWeapon++;
            }
            firstWeaponTexture.loadFromFile(weaponPaths[selectedItemFirstWeapon]);
            firstWeaponSprite.setTexture(firstWeaponTexture);
            firstPlayerWeapon = new Weapon(weaponStats[selectedItemFirstWeapon].name,
                                           weaponStats[selectedItemFirstWeapon].damage,
                                           weaponStats[selectedItemFirstWeapon].attackSpeed,
                                           weaponPaths[selectedItemFirstWeapon]);
            break;
        case 2:
            if (selectedItemSecondCharacter + 1 == skinPaths.size()) {
                selectedItemSecondCharacter = 0;
            } else {
                selectedItemSecondCharacter++;
            }
            secondPlayerTexture.loadFromFile(skinPaths[selectedItemSecondCharacter]);
            secondPlayerSprite.setTexture(secondPlayerTexture);
            break;
        case 3:
            if (selectedItemSecondWeapon + 1 == weaponPaths.size()) {
                selectedItemSecondWeapon = 0;
            } else {
                selectedItemSecondWeapon++;
            }
            secondWeaponTexture.loadFromFile(weaponPaths[selectedItemSecondWeapon]);
            secondWeaponSprite.setTexture(secondWeaponTexture);
            secondPlayerWeapon = new Weapon(weaponStats[selectedItemSecondWeapon].name,
                                            weaponStats[selectedItemSecondWeapon].damage,
                                            weaponStats[selectedItemSecondWeapon].attackSpeed,
                                            weaponPaths[selectedItemSecondWeapon]);
            break;
        default:
            break;
    }
    showNewStats();
}

void CharacterMenu::resize(sf::RenderWindow &window) {
    sf::Vector2u windowSize = window.getSize();
    float centerX = windowSize.x / 2;
    float centerY = windowSize.y / 2;

    // Titel
    title.setPosition(centerX - 275, 50);

    // Erster Spieler Spalte
    firstPlayerText.setPosition(centerX - 300, 120);
    firstPlayerCharcterBack.setPosition(centerX - 300, 170);
    firstPlayerWeaponBack.setPosition(centerX - 300, 450);

    // Zweiter Spieler Spalte
    secondPlayerText.setPosition(centerX + 100, 120);
    secondPlayerCharacterBack.setPosition(centerX + 100, 170);
    secondPlayerWeaponBack.setPosition(centerX + 100, 450);

    // Spieler-Sprites neu positionieren
    firstPlayerSprite.setPosition(
        firstPlayerCharcterBack.getPosition().x + firstPlayerCharcterBack.getSize().x / 2,
        firstPlayerCharcterBack.getPosition().y + firstPlayerCharcterBack.getSize().y / 2
    );

    firstWeaponSprite.setPosition(
        firstPlayerWeaponBack.getPosition().x + firstPlayerWeaponBack.getSize().x / 2,
        firstPlayerWeaponBack.getPosition().y + firstPlayerWeaponBack.getSize().y / 2
    );

    secondPlayerSprite.setPosition(
        secondPlayerCharacterBack.getPosition().x + secondPlayerCharacterBack.getSize().x / 2,
        secondPlayerCharacterBack.getPosition().y + secondPlayerCharacterBack.getSize().y / 2
    );

    secondWeaponSprite.setPosition(
        secondPlayerWeaponBack.getPosition().x + secondPlayerWeaponBack.getSize().x / 2,
        secondPlayerWeaponBack.getPosition().y + secondPlayerWeaponBack.getSize().y / 2
    );

    // Pfeile neu positionieren
    arrowLeftPosition = {
        {firstPlayerCharcterBack.getPosition().x - 50, firstPlayerCharcterBack.getPosition().y + firstPlayerCharcterBack.getSize().y / 2},
        {firstPlayerWeaponBack.getPosition().x - 50, firstPlayerWeaponBack.getPosition().y + firstPlayerWeaponBack.getSize().y / 2},
        {secondPlayerCharacterBack.getPosition().x - 50, secondPlayerCharacterBack.getPosition().y + secondPlayerCharacterBack.getSize().y / 2},
        {secondPlayerWeaponBack.getPosition().x - 50, secondPlayerWeaponBack.getPosition().y + secondPlayerWeaponBack.getSize().y / 2}
    };

    arrowRightPosition = {
        {firstPlayerCharcterBack.getPosition().x + firstPlayerCharcterBack.getSize().x + 20, firstPlayerCharcterBack.getPosition().y + firstPlayerCharcterBack.getSize().y / 2},
        {firstPlayerWeaponBack.getPosition().x + firstPlayerWeaponBack.getSize().x + 20, firstPlayerWeaponBack.getPosition().y + firstPlayerWeaponBack.getSize().y / 2},
        {secondPlayerCharacterBack.getPosition().x + secondPlayerCharacterBack.getSize().x + 20, secondPlayerCharacterBack.getPosition().y + secondPlayerCharacterBack.getSize().y / 2},
        {secondPlayerWeaponBack.getPosition().x + secondPlayerWeaponBack.getSize().x + 20, secondPlayerWeaponBack.getPosition().y + secondPlayerWeaponBack.getSize().y / 2}
    };

    arrowLeft.setPosition(arrowLeftPosition[selectedLayer]);
    arrowRight.setPosition(arrowRightPosition[selectedLayer]);

    // Bestätigen-Button
    enterButton.setPosition(centerX - 125, windowSize.y - 50);
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

Weapon *CharacterMenu::getFirstWeapon() {
    return firstPlayerWeapon;
}

Weapon *CharacterMenu::getSecondWeapon() {
    return secondPlayerWeapon;
}
