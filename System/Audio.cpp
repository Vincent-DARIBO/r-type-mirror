#include "./Audio.hpp"

Audio::Audio(/* args */)
{
}

Audio::~Audio()
{
}

void Audio::loadShotSound(const char *path)
{
    _shot = LoadSound(path);
}

void Audio::playShotSound()
{
    PlaySound(_shot);
}

void Audio::unloadShotSound()
{
    UnloadSound(_shot);
}