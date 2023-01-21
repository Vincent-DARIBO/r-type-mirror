#include "./Movements.hpp"

Components::Movements::Movements(/* args */)
{
    _componentType = ComponentTypes::MOVEMENTS;
}

Components::Movements::Movements(int speed)
{
    _componentType = ComponentTypes::MOVEMENTS;
    _speed = speed;
}

Components::Movements::~Movements()
{
}

void Components::Movements::move(std::shared_ptr<Position> pos, Direction direction)
{
    float x = pos->getPosition().x;
    float y = pos->getPosition().y;
    switch (direction)
    {
    case UP:
        pos->setPosition({x, y - _speed});
        break;
    case RIGHT:
        pos->setPosition({x + _speed, y});
        break;
    case DOWN:
        pos->setPosition({x, y + _speed});
        break;
    case LEFT:
        pos->setPosition({x - _speed, y});
        break;

    default:
        break;
    }
}

void Components::Movements::setSpeed(int speed)
{
    _speed = speed;
}

int Components::Movements::getSpeed()
{
    return _speed;
}