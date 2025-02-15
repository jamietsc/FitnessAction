//
// Created by Admin on 15.02.2025.
//

#include "AudioManager.h"

#include <iostream>
#include <ostream>

AudioManager::AudioManager() {
    if (!clickBuffer.loadFromFile("../sounds/menu_sound.wav")) {
        std::cerr << "AudioManager: Fehler beim laden von ../sound/menu_sound.wav" << std::endl;
    }
    clickSound.setBuffer(clickBuffer);

    if (!attackBuffer.loadFromFile("../sounds/attack_sound.wav")) {
        std::cerr << "AudioManager: Fehler beim laden von ../sounds/attack_sound.wav" << std::endl;
    }
    attackSound.setBuffer(attackBuffer);

    if (!backgroundMusic.openFromFile("../sounds/background_music.wav")) {
        std::cerr << "AudioManager: Fehler beim laden von ../sounds/background_music.wav" << std::endl;
    }
}

void AudioManager::playMenuClick() {
    clickSound.play();
}

void AudioManager::playAttackSound() {
    attackSound.play();
}

void AudioManager::playBackgroundMusic() {
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(50);
    backgroundMusic.play();
}

void AudioManager::stopBackgroundMusic() {
    backgroundMusic.stop();
}
