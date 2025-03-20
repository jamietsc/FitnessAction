//
// Created by Admin on 15.02.2025.
//

#include "AudioManager.h"

#include <iostream>
#include <ostream>

AudioManager::AudioManager() {
    if (!clickBuffer.loadFromFile("../assets/sounds/menu_sound.wav")) {
        std::cerr << "AudioManager: Fehler beim laden von ../assets/sound/menu_sound.wav" << std::endl;
    }
    clickSound.setBuffer(clickBuffer);

    if (!attackBuffer.loadFromFile("../assets/sounds/attack_sound.wav")) {
        std::cerr << "AudioManager: Fehler beim laden von ../assets/sounds/attack_sound.wav" << std::endl;
    }
    attackSound.setBuffer(attackBuffer);

    if (!backgroundMusic.openFromFile("../assets/sounds/background_music_2.mp3")) {
        std::cerr << "AudioManager: Fehler beim laden von ../assets/sounds/background_music.wav" << std::endl;
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
    backgroundMusic.setVolume(30);
    backgroundMusic.play();
}

void AudioManager::stopBackgroundMusic() {
    backgroundMusic.stop();
}

void AudioManager::stopAttackSound() {
    attackSound.stop();
}