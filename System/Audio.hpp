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
    void loadShotSound(const char *path);
    void playShotSound();
    void unloadShotSound();
};

#endif