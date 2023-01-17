#include "./Position.hpp"

Components::Position::Position(/* args */)
{
    _componentType = ComponentTypes::POSITION;
}

Components::Position::Position(Vector2 pos)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
    _componentType = ComponentTypes::POSITION;
}

Components::Position::~Position()
{
}

void Components::Position::setPosition(Vector2 pos)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
}

Vector2 Components::Position::getPosition()
{
    return _pos;
}