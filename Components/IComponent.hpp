#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "raylib.h"
#include <string>

enum ComponentTypes
{
    HEALTH,
    POSITION,
    MOVEMENTS,
    OBJECT,
    TEXT,
    CAMERACOMP,
    // COLLISION,
    AI,
    // RENDER,
    ANIMATION,
};

namespace Components
{
    class IComponent
    {
    protected:
        enum ComponentTypes _componentType;

    public:
        enum ComponentTypes getComponentType() const { return _componentType; };
    };
}

#endif