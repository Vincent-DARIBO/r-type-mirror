#ifndef _MOVEMENTS_
#define _MOVEMENTS_

#include "./IComponent.hpp"
#include "./Position.hpp"
#include <memory>

namespace Components
{
    class Movements : public IComponent
    {
    private:
        int _speed;
        int _keyUp;
        int _keyDown;
        int _keyRight;
        int _keyLeft;
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