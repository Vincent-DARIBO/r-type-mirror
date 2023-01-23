#ifndef _MOVEMENTS_
#define _MOVEMENTS_

#include "./IComponent.hpp"
#include "./Position.hpp"
#include <memory>

enum Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

namespace Components
{
    class Movements : public IComponent
    {
    private:
        int _speed;
    public:
        Movements(/* args */);
        Movements(int speed);
        ~Movements();
        void move(std::shared_ptr<Position> pos, Direction direction);
        void setSpeed(int speed);
        int getSpeed();
    };
}

#endif