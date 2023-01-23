#include "./CameraFactory.hpp"

CameraFactory::CameraFactory(/* args */)
{
}

CameraFactory::~CameraFactory()
{
}

Entity *CameraFactory::create() const 
{
    return new rTypeCamera();
}