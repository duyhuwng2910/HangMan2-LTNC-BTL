#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include "Resources.h"

using namespace std;

class Sound {

public:

    Mix_Music *music;

    Mix_Chunk *chunk;

    Sound(Mix_Music *_music, Mix_Chunk *_chunk) {
        music = _music;
        chunk = _chunk;
    }

    void playMusic();

    void stopMusic();

};

#endif // SOUND_H
