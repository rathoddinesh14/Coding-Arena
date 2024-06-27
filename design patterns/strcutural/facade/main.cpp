#include "HomeTheaterFacade.h"
#include "AudioSystem.h"
#include "VideoSystem.h"
#include "LightingSystem.h"

int main() {
    AudioSystem audio;
    VideoSystem video;
    LightingSystem lighting;

    HomeTheaterFacade homeTheater(&audio, &video, &lighting);

    homeTheater.watchMovie();
    // ... watching movie ...
    homeTheater.endMovie();

    return 0;
}
