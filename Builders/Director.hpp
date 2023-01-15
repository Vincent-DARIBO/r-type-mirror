#ifndef _DIRECTOR_
#define _DIRECTOR_

#include "./IEntityBuilder.hpp"
#include "./CameraBuilder.hpp"
#include "./PlayerBuilder.hpp"

enum EntityTypes
{
    BASE_CAMERA,
    MAP,
    PLAYER,
};

class Director
{
private:
    CameraBuilder _cameraBuilder;
    // MapBuilder _mapBuilder;
    PlayerBuilder _playerBuilder;

public:
    Director(/* args */);
    ~Director();
    Entity &make(EntityTypes type);
};
#endif