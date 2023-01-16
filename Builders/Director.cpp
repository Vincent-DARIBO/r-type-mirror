#include "Director.hpp"

Director::Director(/* args */)
{
}

Director::~Director()
{
}

Entity &Director::make(EntityTypes type)
{
    switch (type)
    {
    case EntityTypes::BASE_CAMERA:
        // _cameraBuilder.setCameraComp({0.0, 0.0, 0.0}, {0.0, 10.0, 0.0});
        // _cameraBuilder.addComps();
        // return _cameraBuilder.getEntity();
    case EntityTypes::MAP:
        // _mapBuilder.setSquareComp(1.0, 1.0, 1.0, GRAY);
        // _mapBuilder.setCollisionComp();
        // _mapBuilder.addComps();
        // return _mapBuilder.getEntity();
    case EntityTypes::PLAYER:
        _playerBuilder.setObject();
        _playerBuilder.setPosition();
        _playerBuilder.setAnimation();
        // _playerBuilder.setTexture();
        _playerBuilder.setMovement();
        // _playerBuilder.setCollision();
        _playerBuilder.addComps();
        return _playerBuilder.getEntity();
    case EntityTypes::PROJECTILES:
        _projectileBuilder.setObject();
        _projectileBuilder.setPosition();
        // _projectileBuilder.setMovement();
        // _playerBuilder.setAnimation();
        _projectileBuilder.addComps();
        return _projectileBuilder.getEntity();
    default:
        throw "Invalid EntityTypes";
    }
}