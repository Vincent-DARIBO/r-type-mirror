#ifndef _POSITION_
#define _POSITION_

#include "./IComponent.hpp"

namespace Components
{
    class Position : public IComponent
    {
    private:
        Vector2 _pos;
    public:
        Position(/* args */);
        Position(Vector2 pos);
        ~Position();
        void setPosition(Vector2 pos);
        Vector2 getPosition();
    };
}

#endif