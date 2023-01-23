#ifndef _POSITION_
#define _POSITION_

#include "./IComponent.hpp"
#include "../System/Vector2Int.hpp"

namespace Components
{
    class Position : public IComponent
    {
    private:
        Vector2Int _pos;
    public:
        Position(/* args */);
        Position(Vector2Int pos);
        ~Position();
        void setPosition(Vector2Int pos);
        Vector2Int getPosition();
    };
}

#endif