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

enum Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

typedef struct vector2int
{
    int x;
    int y;
} vector2int;

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