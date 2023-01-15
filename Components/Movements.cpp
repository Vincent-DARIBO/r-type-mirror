#include "./Movements.hpp"

Components::Movements::Movements(/* args */)
{
}

Components::Movements::~Movements()
{
}

void Components::Movements::setSpeed(int speed)
{
    _speed = speed;
}

int Components::Movements::getSpeed()
{
    return _speed;
}