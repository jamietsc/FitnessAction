//
// Created by Admin on 15.02.2025.
//

#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"


class AudioManager {
public:
    AudioManager();
    void playMenuClick();
    void playAttackSound();
    void playBackgroundMusic();
    void stopBackgroundMusic();

private:
    sf::SoundBuffer clickBuffer;
    sf::SoundBuffer attackBuffer;
    sf::Sound clickSound;
    sf::Sound attackSound;
    sf::Music backgroundMusic;
};



#endif //AUDIOMANAGER_H
