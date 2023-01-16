#ifndef _DIRECTOR_
#define _DIRECTOR_

#include "./IEntityBuilder.hpp"
#include "./CameraBuilder.hpp"
#include "./PlayerBuilder.hpp"
#include "./ProjectilesBuilder.hpp"
#include <memory>

enum EntityTypes
{
    BASE_CAMERA,
    MAP,
    PLAYER,
    PROJECTILES
};

class Director
{
private:
    CameraBuilder _cameraBuilder;
    // MapBuilder _mapBuilder;
    PlayerBuilder _playerBuilder;
    ProjectilesBuilder _projectileBuilder;

public:
    Director(/* args */);
    ~Director();
    Entity &make(EntityTypes type);
};
#endif