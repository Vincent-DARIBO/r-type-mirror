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
    void playShotSound(const char *path);
    void loadShotSound(const char *path);
    void unloadShotSound();
};

#endif