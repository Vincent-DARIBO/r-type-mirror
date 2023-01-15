#ifndef _CAMERA_BUILDER_
#define _CAMERA_BUILDER_

#include "../Entity/Entity.hpp"
#include <vector>

class CameraBuilder
{
private:
    Entity _entity;
    std::vector<std::shared_ptr<Components::IComponent>> _components;

public:
    CameraBuilder(/* args */);
    ~CameraBuilder();
    void setCameraComp();
};

#endif