#ifndef _AUDIO_
#define _AUDIO_

#include <raylib.h>

class Audio
{
private:
    Sound _shot;
public:
    Audio(/* args */);
    ~Audio();
    void playShotSound();
    void loadShotSound(const char *path);
    void unloadShotSound();
};

#endif