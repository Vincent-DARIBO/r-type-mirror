#ifndef CAMERA_FACTORY_
#define CAMERA_FACTORY_

#include "./Factory.hpp"
#include "../Entity/rTypeCamera.hpp"

class CameraFactory : public Factory
{
private:
    /* data */
public:
    CameraFactory(/* args */);
    ~CameraFactory();
    Entity *create() const override;
};

#endif