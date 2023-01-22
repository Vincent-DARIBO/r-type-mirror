#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "raylib.h"
#include <string>

enum ComponentTypes
{
    // CAMERA,
    HEALTH,
    POSITION,
    MOVEMENTS,
    OBJECT,
    TEXT,
    // COLLISION,
    // IA,
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