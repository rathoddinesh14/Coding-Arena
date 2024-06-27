// HomeTheaterFacade.h
#pragma once
#include "AudioSystem.h"
#include "VideoSystem.h"
#include "LightingSystem.h"

class HomeTheaterFacade {
public:
    HomeTheaterFacade(AudioSystem* audio, VideoSystem* video, LightingSystem* lighting)
        : audio(audio), video(video), lighting(lighting) {}

    void watchMovie() {
        std::cout << "Get ready to watch a movie..." << std::endl;
        lighting->dim(10);
        video->on();
        video->setResolution(1920, 1080);
        audio->on();
        audio->setVolume(5);
        std::cout << "Movie is starting!" << std::endl;
    }

    void endMovie() {
        std::cout << "Shutting down movie theater..." << std::endl;
        lighting->on();
        audio->off();
        video->off();
        std::cout << "Movie theater is shut down." << std::endl;
    }

private:
    AudioSystem* audio;
    VideoSystem* video;
    LightingSystem* lighting;
};
